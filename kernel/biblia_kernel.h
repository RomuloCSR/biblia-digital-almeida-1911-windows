/* =============================================================================
 * biblia_kernel.h — API pública do kernel da Bíblia Almeida ARC-1911 (versão 1.0)
 *
 * O que é: o cabeçalho único que os 6 programas incluem (terminal Windows, Linux e
 *          macOS, app Windows WebView2, app Linux GTK e Android JNI). A implementação
 *          está em biblia_kernel.c, que traz as tabelas geradas da pasta gerado/.
 * Por quê: hoje cada programa tem a sua cópia do motor.biblia.c e do laço que lê o
 *          capítulo. Com o kernel, todos chamam as mesmas funções e dão o mesmo texto.
 * Data:    27/11/2026. Fonte: a API proposta em biblia-build/kernel_rev
 *          (relatorio_arquitetura.md, seção 3), agora ligada ao motor atual
 *          (commit 15ef5f8 do app Windows) e com o erro BK_ERRO_GRANDE.
 *
 * Regras do kernel:
 *  - Só C99 + <stddef.h> aqui. Nada de printf, system, terminal, cores, arquivos ou
 *    locale no kernel. Quem lê o .md (fopen, AAssetManager, g_file_get_contents...)
 *    é o programa, que entrega o conteúdo em memória.
 *  - Reentrante: nenhum estado global que mude; tabelas só de leitura; o resultado vai
 *    sempre para um buffer de quem chama. Pode ser chamado de várias threads ao mesmo tempo.
 *  - Não precisa iniciar nem liberar nada.
 *  - Nunca corta texto: se uma troca não cabe em BK_MAX_TEXTO, o texto fica como
 *    estava (igual ao motor). Se o buffer de quem chama é pequeno, nada é escrito pela
 *    metade: saida[0] = '\0' e a função devolve BK_ERRO_BUFFER.
 *  - Código de retorno: >= 0 = sucesso (tamanho em bytes ou número de itens),
 *    < 0 = erro (BK_ERRO_*).
 *  - Texto sempre em UTF-8, terminado em '\0'.
 *  - As funções de caractere (isalpha, isdigit, tolower) são as do motor e contam com
 *    o locale "C" (o padrão de todo programa C; os testes rodaram assim). isalpha só é
 *    usada em bytes ASCII. isdigit e tolower também recebem bytes >= 0x80 (UTF-8); num
 *    locale UTF-8 (GTK chama setlocale) elas dão o mesmo resultado, mas num locale de
 *    1 byte (ex.: Latin-1 no Windows) poderiam dar outro. Não chame setlocale(LC_CTYPE)
 *    com locale de 1 byte no mesmo processo.
 * ============================================================================= */
#ifndef BIBLIA_KERNEL_H
#define BIBLIA_KERNEL_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Exportação: só precisa se o kernel virar DLL/.so separada; ligado direto, fica vazio. */
#if defined(BK_DLL) && defined(_WIN32)
#  ifdef BK_COMPILANDO
#    define BK_API __declspec(dllexport)
#  else
#    define BK_API __declspec(dllimport)
#  endif
#elif defined(BK_DLL)
#  define BK_API __attribute__((visibility("default")))
#else
#  define BK_API
#endif

/* ---------------------------------------------------------------------------
 * 1. VERSÃO
 *    API (MAIOR.MENOR): MAIOR muda quando uma função muda ou some; MENOR quando entra
 *    função nova. REGRAS: data da tabela de ortografia; muda a cada revisão de texto,
 *    junto com o golden (teste/golden/todos_versos.golden.tsv.sha256).
 * --------------------------------------------------------------------------- */
#define BK_API_MAIOR 1
#define BK_API_MENOR 0

BK_API int         bk_api_versao(void);    /* BK_API_MAIOR * 100 + BK_API_MENOR (ex.: 100)     */
BK_API const char *bk_regras_versao(void); /* ex.: "2026-11-27"                                 */
BK_API const char *bk_golden_sha256(void); /* SHA-256 esperado da saída dos 31104 itens (LF)    */

/* O programa confere na partida que foi compilado com a mesma API MAIOR:
 *   if (!BK_API_COMPATIVEL()) { ...avisa e sai... }                                           */
#define BK_API_COMPATIVEL() (bk_api_versao() / 100 == BK_API_MAIOR)

/* ---------------------------------------------------------------------------
 * 2. ERROS
 * --------------------------------------------------------------------------- */
#define BK_ERRO_ARGUMENTO  (-1)  /* ponteiro nulo, livro/capítulo fora da faixa         */
#define BK_ERRO_BUFFER     (-2)  /* buffer de quem chama pequeno demais (nada escrito)   */
#define BK_ERRO_PARADO     (-3)  /* o callback pediu para parar                          */
#define BK_ERRO_GRANDE     (-4)  /* linha do .md com BK_MAX_TEXTO bytes ou mais (bk_verso) */

/* Tamanho máximo de uma linha/verso, igual ao MAX_LINHA do motor (o kernel confere na
 * compilação). Um buffer de BK_MAX_TEXTO bytes sempre basta para bk_verso() e
 * bk_atualizar() com texto menor que BK_MAX_TEXTO. */
#define BK_MAX_TEXTO 8192

/* ---------------------------------------------------------------------------
 * 3. LIVROS E CAPÍTULOS (índice 0..65: 0..38 = AT, 39..65 = NT)
 * --------------------------------------------------------------------------- */
#define BK_TOTAL_LIVROS 66

BK_API int         bk_total_livros(void);          /* 66                                    */
BK_API const char *bk_livro_nome(int livro);       /* "Gênesis" ... "Apocalipse"; NULL fora  */
BK_API const char *bk_livro_pasta(int livro);      /* "01-GEN" ... "67-REV";      NULL fora  */
BK_API int         bk_livro_capitulos(int livro);  /* 50 ...; BK_ERRO_ARGUMENTO fora         */
BK_API int         bk_livro_testamento(int livro); /* 1 = AT, 2 = NT; BK_ERRO_ARGUMENTO fora */

/* Caminho relativo do capítulo, a partir da pasta "textos":
 *   tentativa 0 -> "01-GEN/01.md"   tentativa 1 -> "19-PSA/001.md"
 * (o motor tenta "%02d" e depois "%03d"; o programa faz o mesmo com a sua forma de
 *  abrir arquivo). Devolve o tamanho escrito ou BK_ERRO_*. */
BK_API int bk_caminho_capitulo(int livro, int capitulo, int tentativa, char *saida, size_t tamanho);

/* ---------------------------------------------------------------------------
 * 4. TEXTO
 * --------------------------------------------------------------------------- */

/* Uma linha de verso do .md (já sem o número, como o motor recebe hoje) ->
 * limpa o Markdown (notas [^x], [1], **, *) e atualiza a ortografia.
 * Grava em 'saida' (tamanho >= BK_MAX_TEXTO sempre basta). Devolve strlen ou BK_ERRO_*
 * (BK_ERRO_GRANDE se a linha tem BK_MAX_TEXTO bytes ou mais; o motor não aceita isso). */
BK_API int bk_verso(const char *linha_md, char *saida, size_t tamanho);

/* Só a atualização de ortografia (texto já limpo: busca, palavras, testes).
 * 'saida' pode ser o próprio 'texto'. Texto com BK_MAX_TEXTO bytes ou mais não cabe no
 * motor: sai igual, sem nenhuma troca (nunca cortado). */
BK_API int bk_atualizar(const char *texto, char *saida, size_t tamanho);

/* Capítulo inteiro: 'md' é o conteúdo do arquivo .md em memória (não precisa terminar
 * em '\0'; 'tamanho' bytes). Para cada verso ou subtítulo, NA ORDEM do arquivo, chama
 *   cb(ctx, tipo, numero, texto, tamanho_texto)
 * tipo = BK_VERSO (numero = número do verso) ou BK_SUBTITULO (numero = 0).
 * 'texto' só vale durante a chamada (copie se precisar). Se o callback devolver != 0,
 * para e devolve BK_ERRO_PARADO. Sucesso: devolve quantos itens entregou.
 * Mesma leitura de ler_capitulo() do motor: linhas como fgets(MAX_LINHA) ("\r\n" vira
 * "\n"; o resto de uma linha longa demais é descartado), tira o BOM do UTF-8, para em
 * "---", pula linhas "#" e "[", verso começa com número (depois de "*" e espaços),
 * subtítulo começa com "**". */
#define BK_VERSO     1
#define BK_SUBTITULO 2
typedef int (*bk_item_cb)(void *ctx, int tipo, int numero, const char *texto, size_t tamanho_texto);

BK_API int bk_capitulo(const char *md, size_t tamanho, bk_item_cb cb, void *ctx);

#ifdef __cplusplus
}
#endif
#endif /* BIBLIA_KERNEL_H */
