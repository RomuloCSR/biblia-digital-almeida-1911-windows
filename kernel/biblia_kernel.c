/* =============================================================================
 * biblia_kernel.c — kernel da Bíblia Almeida ARC-1911 (implementação da API 1.0)
 *
 * O que faz: limpa o Markdown e atualiza a ortografia de cada versículo, lê o capítulo
 *            (.md em memória) e entrega versos e subtítulos por callback; traz as tabelas
 *            de livros. É o mesmo texto do motor.biblia.c, byte a byte, cerca de 20 vezes
 *            mais rápido.
 * Por quê:   os 6 programas (terminais, WebView2, GTK, Android) passam a usar um só
 *            arquivo C, sem printf, system, terminal nem caminho de arquivo.
 * Como:      - gerado/motor_secoes.inc: as partes 1 e 3 do motor copiadas como estão
 *              (tabelas de livros, limpeza, gerúndio, sufixos/ênclises);
 *            - gerado/regras_tabela.inc: todas as regras de atualizar_ortografia(), na
 *              mesma ordem, em tabela;
 *            - gerado/regras_indice.inc: índice das regras pelo 1º par de bytes.
 *            Os três vêm de gerador/gerar_kernel.c, que lê o motor.biblia.c.
 *            Este arquivo só tem o que não dá para gerar: as trocas rápidas (cópia fiel
 *            de substituir_*), o percurso da tabela e a API.
 * Compilar:  gcc -O2 -Wall -Wextra -c biblia_kernel.c   (o programa liga o .o junto)
 * Teste:     com -DBK_USAR_MOTOR_ORIGINAL -I<pasta do motor>, a mesma API roda em cima do
 *            motor.biblia.c original (só para o teste de regressão comparar os dois).
 * Data:      27/11/2026. Fonte: motor.biblia.c do app Windows (commit 15ef5f8) e o
 *            protótipo motor_rapido.c / biblia_kernel_proto.c de biblia-build/kernel_rev.
 * ============================================================================= */
#include <stdio.h>     /* só snprintf/sprintf (montar texto); nenhuma E/S */
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define BK_COMPILANDO
#include "biblia_kernel.h"

/* -----------------------------------------------------------------------------
 * A. CÓDIGO QUE VEM DO MOTOR
 *    Normal: as partes 1 e 3 do motor, geradas (tudo "static").
 *    Teste (-DBK_USAR_MOTOR_ORIGINAL): o motor.biblia.c original inteiro, com o main
 *    renomeado, e atualizar_ortografia() original no lugar da tabela.
 * ----------------------------------------------------------------------------- */
#ifdef BK_USAR_MOTOR_ORIGINAL
#  define main bk_main_do_motor_nao_usado
#  include "motor.biblia.c"
#  undef main
#  define bk_atualizar_no_lugar atualizar_ortografia
#else
/* O GCC do Linux (com _FORTIFY_SOURCE) avisa -Wformat-overflow no
 * sprintf(palavra, "%s%s", radical, sufixo) de normalizar_composto_hifen (código do motor,
 * copiado sem mudança). O aviso é falso: atualizar_sufixos_e_enclises só chama essa função
 * com palavra de até 249 bytes (o "if (len >= 250)" do motor), e a troca do radical cresce
 * no máximo 1 byte ("poz" -> "pôs"), então cabe em palavra[256]. O AddressSanitizer
 * confirmou nos testes. Por isso o aviso fica desligado só neste trecho. */
#  if defined(__GNUC__) && !defined(__clang__)
#    pragma GCC diagnostic push
#    pragma GCC diagnostic ignored "-Wformat-overflow"
#  endif
#  include "gerado/motor_secoes.inc"
#  if defined(__GNUC__) && !defined(__clang__)
#    pragma GCC diagnostic pop
#  endif
#endif

typedef char bk_confere_max_texto[(BK_MAX_TEXTO == MAX_LINHA) ? 1 : -1];

#ifndef BK_USAR_MOTOR_ORIGINAL

/* -----------------------------------------------------------------------------
 * B. TABELA DE REGRAS (gerada) E CONFERÊNCIAS DE COMPILAÇÃO
 *    Cada R(...) de regras_tabela.inc vira um item: tipo, flag de acento, tamanhos
 *    calculados pelo compilador (sizeof - 1) e os dois textos.
 * ----------------------------------------------------------------------------- */
enum { R_TEXTO, R_INICIO, R_INTEIRA, R_SUFIXOS, R_GERUNDIO };

typedef struct {
    unsigned char tipo, acento;   /* acento: só R_INICIO ("a regra acrescenta acento?") */
    unsigned short la, ln;        /* strlen de antigo e de novo                          */
    const char *a, *n;            /* antigo, novo                                        */
} BkRegra;

#define R(t, a, n, ac) { t, ac, (unsigned short)(sizeof(a) - 1), (unsigned short)(sizeof(n) - 1), a, n },
static const BkRegra BK_REGRAS[] = {
#include "gerado/regras_tabela.inc"
};
#undef R
#define BK_TOTAL_REGRAS ((int)(sizeof(BK_REGRAS) / sizeof(BK_REGRAS[0])))

#include "gerado/regras_indice.inc"
#define BK_PALAVRAS_FILA ((BK_TOTAL_REGRAS + 63) / 64)

/* A tabela, o índice e as partes copiadas têm de ter vindo do mesmo motor. */
typedef char bk_confere_indice[(BK_IDX_TOTAL_REGRAS == BK_TOTAL_REGRAS &&
                                BK_GERADO_TOTAL_REGRAS == BK_TOTAL_REGRAS &&
                                sizeof(BK_IDX_SEMPRE) / sizeof(BK_IDX_SEMPRE[0]) == BK_PALAVRAS_FILA) ? 1 : -1];
typedef char bk_confere_max_linha[(BK_GERADO_MAX_LINHA == MAX_LINHA) ? 1 : -1];

/* Assinatura das funções substituir_texto, substituir_inicio_palavra e
 * substituir_palavra_inteira do motor, no dia em que bk_troca_texto e bk_troca_palavra
 * (seção C) foram conferidas contra elas, linha a linha (27/11/2026, commit 15ef5f8).
 * Se o gerador achar outro texto nessas funções, o kernel NÃO compila: revise a seção C
 * para fazer o mesmo que o motor novo, rode o teste e só então troque este valor pelo
 * BK_GERADO_ASSINATURA_TROCAS de gerado/regras_tabela.inc. */
#define BK_TROCAS_REVISADAS 0xf3bd7e03ea0ee6c3ull
#if BK_GERADO_ASSINATURA_TROCAS != BK_TROCAS_REVISADAS
#  error "substituir_* mudou no motor.biblia.c: revise bk_troca_texto/bk_troca_palavra em biblia_kernel.c (veja o comentario de BK_TROCAS_REVISADAS)"
#endif

/* -----------------------------------------------------------------------------
 * C. TROCAS RÁPIDAS — cópia fiel de substituir_texto, substituir_inicio_palavra e
 *    substituir_palavra_inteira do motor (mesmos testes de tamanho e de começo/fim de
 *    palavra, na mesma ordem). Diferenças, só de velocidade:
 *      - o 1º strstr já foi feito por quem chama (pos != NULL);
 *      - os tamanhos e o flag de acento vêm prontos da tabela;
 *      - o resultado vai para o outro buffer (dst) e não volta com strcpy.
 *    Se não couber em MAX_LINHA, devolve BK_NAO_COUBE e o texto fica como estava
 *    (igual ao "return" do motor).
 * ----------------------------------------------------------------------------- */
#define BK_NAO_COUBE ((size_t)-1)

/* mesmo teste do motor: "prev < 0x80 && !isalpha(prev)" */
static int bk_fora_de_palavra(unsigned char c) { return c < 0x80 && !isalpha(c); }

static size_t bk_troca_texto(const char *src, size_t len, char *dst, const BkRegra *r, const char *pos) {
    size_t usado = 0;
    const char *atual = src;
    while (pos != NULL) {
        size_t trecho = (size_t)(pos - atual);
        if (usado + trecho + r->ln >= MAX_LINHA - 1) return BK_NAO_COUBE;
        memcpy(dst + usado, atual, trecho);
        usado += trecho;
        memcpy(dst + usado, r->n, r->ln);
        usado += r->ln;
        atual = pos + r->la;
        pos = strstr(atual, r->a);
    }
    size_t resto = len - (size_t)(atual - src);
    if (usado + resto >= MAX_LINHA - 1) return BK_NAO_COUBE;
    memcpy(dst + usado, atual, resto);
    usado += resto;
    dst[usado] = '\0';
    return usado;
}

/* inteira = 1: substituir_palavra_inteira; inteira = 0: substituir_inicio_palavra */
static size_t bk_troca_palavra(const char *src, size_t len, char *dst, const BkRegra *r, const char *pos, int inteira) {
    size_t usado = 0;
    const char *atual = src;
    while (pos != NULL) {
        int ok = (pos == src) || bk_fora_de_palavra((unsigned char)pos[-1]);
        if (inteira) {
            unsigned char next = (unsigned char)pos[r->la];
            if (!(next == '\0' || bk_fora_de_palavra(next))) ok = 0;
        } else if (ok && r->acento) {
            /* a regra acrescenta acento: só vale para a palavra e -s, -o, -a, -os, -as, -es */
            const char *resto_p = pos + r->la;
            int tam_resto = 0;
            while (resto_p[tam_resto] != '\0' && !bk_fora_de_palavra((unsigned char)resto_p[tam_resto])) tam_resto++;
            int resto_ok = (tam_resto == 0) ||
                (tam_resto == 1 && (resto_p[0] == 's' || resto_p[0] == 'o' || resto_p[0] == 'a')) ||
                (tam_resto == 2 && resto_p[1] == 's' && (resto_p[0] == 'o' || resto_p[0] == 'a' || resto_p[0] == 'e'));
            if (!resto_ok) ok = 0;
        }
        if (!ok) {
            size_t avanco = (size_t)(pos - atual) + 1;
            if (usado + avanco >= MAX_LINHA - 1) return BK_NAO_COUBE;
            memcpy(dst + usado, atual, avanco);
            usado += avanco;
            atual = pos + 1;
            pos = strstr(atual, r->a);
            continue;
        }
        size_t trecho = (size_t)(pos - atual);
        if (usado + trecho + r->ln >= MAX_LINHA - 1) return BK_NAO_COUBE;
        memcpy(dst + usado, atual, trecho);
        usado += trecho;
        memcpy(dst + usado, r->n, r->ln);
        usado += r->ln;
        atual = pos + r->la;
        pos = strstr(atual, r->a);
    }
    size_t resto = len - (size_t)(atual - src);
    if (usado + resto >= MAX_LINHA - 1) return BK_NAO_COUBE;
    memcpy(dst + usado, atual, resto);
    usado += resto;
    dst[usado] = '\0';
    return usado;
}

/* -----------------------------------------------------------------------------
 * D. PERCURSO DA TABELA (substitui atualizar_ortografia do motor)
 *
 *    Cada versículo tem um conjunto de 4096 bits com os pares de bytes (bigramas) que
 *    já apareceram nele. Uma regra só entra na fila quando o 1º par do "antigo" aparece;
 *    antes do strstr, confere se TODOS os pares do "antigo" estão no conjunto. A fila é
 *    percorrida em ordem crescente, que é a ordem do motor.
 *
 *    Por que a saída é igual à do motor:
 *     - Regra pulada não podia casar (falta um par do "antigo" no texto). No motor,
 *       regra que não casa deixa o texto como estava.
 *     - O conjunto nunca perde um par: os pares novos entram quando o texto muda e os
 *       antigos ficam (no máximo causa um strstr a mais, nunca uma regra pulada).
 *     - Se o 1º par de uma regra só apareceu depois da vez dela, no motor, na vez dela,
 *       o texto também não tinha esse par, e ela também não casava.
 *     - Regra que casa roda a mesma troca do motor (seção C); sufixos e gerúndio são as
 *       próprias funções do motor (motor_secoes.inc).
 * ----------------------------------------------------------------------------- */
typedef struct { unsigned long long w[64]; } BkBigramas;

static int bk_bg_tem(const BkBigramas *s, unsigned c0, unsigned c1) {
    unsigned h = BK_BG(c0, c1);
    return (int)((s->w[h >> 6] >> (h & 63)) & 1u);
}

/* junta os pares do texto; cada par novo põe na fila as regras dele que ainda vêm (> atual) */
static void bk_bg_juntar_fila(BkBigramas *s, unsigned long long *fila, const char *t, size_t len, int atual) {
    const unsigned char *u = (const unsigned char *)t;
    for (size_t i = 0; i + 1 < len; i++) {
        unsigned h = BK_BG(u[i], u[i + 1]);
        unsigned long long bit = 1ull << (h & 63);
        if (s->w[h >> 6] & bit) continue;
        s->w[h >> 6] |= bit;
        for (unsigned k = BK_IDX_INI[h]; k < BK_IDX_INI[h + 1]; k++) {
            int ri = BK_IDX_REGRA[k];
            if (ri > atual) fila[ri >> 6] |= 1ull << (ri & 63);
        }
    }
}

/* posição do 1º bit ligado (x != 0): GCC/Clang (MinGW, Linux, macOS, NDK) ou MSVC */
#if defined(__GNUC__) || defined(__clang__)
#  define bk_ctz64(x) __builtin_ctzll(x)
#elif defined(_MSC_VER)
#  include <intrin.h>
static int bk_ctz64(unsigned long long x) { unsigned long i; _BitScanForward64(&i, x); return (int)i; }
#else
static int bk_ctz64(unsigned long long x) { int i = 0; while (!(x & 1)) { x >>= 1; i++; } return i; }
#endif

/* Mesmo contrato de atualizar_ortografia(): 'texto' tem MAX_LINHA bytes e strlen < MAX_LINHA. */
static void bk_atualizar_no_lugar(char *texto) {
    size_t len = strlen(texto);
    char outro[MAX_LINHA];
    char *cur = texto, *alt = outro;
    BkBigramas bg;
    unsigned long long fila[BK_PALAVRAS_FILA];
    memset(&bg, 0, sizeof(bg));
    memcpy(fila, BK_IDX_SEMPRE, sizeof(fila));      /* sufixos, gerúndio e regras de 1 byte */
    bk_bg_juntar_fila(&bg, fila, cur, len, -1);

    for (int w = 0; w < BK_PALAVRAS_FILA; w++) {
        while (fila[w]) {
            int i = w * 64 + bk_ctz64(fila[w]);
            fila[w] &= fila[w] - 1;                   /* tira a regra i da fila */
            const BkRegra *r = &BK_REGRAS[i];
            if (r->tipo == R_SUFIXOS || r->tipo == R_GERUNDIO) {
                if (r->tipo == R_SUFIXOS) atualizar_sufixos_e_enclises(cur);
                else converter_infinitivo_lusitano_para_gerundio(cur);
                len = strlen(cur);
                bk_bg_juntar_fila(&bg, fila, cur, len, i);
                continue;
            }
            if (r->la >= 2) {                         /* todos os pares do "antigo" no texto? */
                const unsigned char *a = (const unsigned char *)r->a;
                int falta = 0;
                for (unsigned k = 1; k + 1 < r->la; k++)   /* o 1º par já trouxe a regra */
                    if (!bk_bg_tem(&bg, a[k], a[k + 1])) { falta = 1; break; }
                if (falta) continue;
            }
            const char *pos = strstr(cur, r->a);
            if (pos == NULL) continue;                /* no motor: o texto ficava igual */
            size_t nl = r->tipo == R_TEXTO ? bk_troca_texto(cur, len, alt, r, pos)
                                           : bk_troca_palavra(cur, len, alt, r, pos, r->tipo == R_INTEIRA);
            if (nl == BK_NAO_COUBE) continue;         /* não coube: texto como estava */
            char *t = cur; cur = alt; alt = t; len = nl;   /* troca de buffer, sem strcpy */
            bk_bg_juntar_fila(&bg, fila, cur, len, i);
        }
    }
    if (cur != texto) memcpy(texto, cur, len + 1);
}

#endif /* !BK_USAR_MOTOR_ORIGINAL */

/* -----------------------------------------------------------------------------
 * E. API PÚBLICA (biblia_kernel.h)
 * ----------------------------------------------------------------------------- */

/* Versão das regras e SHA-256 do golden (teste/golden/todos_versos.golden.tsv, LF).
 * Mudou uma regra de propósito? Rode o teste com --atualizar, revise o diff do golden e
 * ponha aqui a data e o SHA novos (veja LEIAME.md). */
#define BK_REGRAS_VERSAO "2026-11-27"
#define BK_GOLDEN_SHA256 "C37979A1F09A0219E3A2F465DFBE8A94BD71A3ED2C90997A859DE9F5F3E3949A"

int bk_api_versao(void) { return BK_API_MAIOR * 100 + BK_API_MENOR; }
const char *bk_regras_versao(void) { return BK_REGRAS_VERSAO; }
const char *bk_golden_sha256(void) { return BK_GOLDEN_SHA256; }

int bk_total_livros(void) { return BK_TOTAL_LIVROS; }

const char *bk_livro_nome(int l) {
    if (l < 0 || l >= BK_TOTAL_LIVROS) return NULL;
    return l < 39 ? nomes_at[l] : nomes_nt[l - 39];
}

const char *bk_livro_pasta(int l) {
    if (l < 0 || l >= BK_TOTAL_LIVROS) return NULL;
    return l < 39 ? pastas_at[l] : pastas_nt[l - 39];
}

int bk_livro_capitulos(int l) {
    if (l < 0 || l >= BK_TOTAL_LIVROS) return BK_ERRO_ARGUMENTO;
    return l < 39 ? capitulos_at[l] : capitulos_nt[l - 39];
}

int bk_livro_testamento(int l) {
    if (l < 0 || l >= BK_TOTAL_LIVROS) return BK_ERRO_ARGUMENTO;
    return l < 39 ? 1 : 2;
}

int bk_caminho_capitulo(int l, int c, int tentativa, char *saida, size_t tamanho) {
    if (!saida || l < 0 || l >= BK_TOTAL_LIVROS || c < 1 || c > bk_livro_capitulos(l) || tentativa < 0 || tentativa > 1)
        return BK_ERRO_ARGUMENTO;
    int n = snprintf(saida, tamanho, tentativa == 0 ? "%s/%02d.md" : "%s/%03d.md", bk_livro_pasta(l), c);
    if (n < 0 || (size_t)n >= tamanho) { if (tamanho) saida[0] = '\0'; return BK_ERRO_BUFFER; }
    return n;
}

/* copia o resultado para quem chama só se couber inteiro (memmove: saida pode ser texto) */
static int bk_entregar(const char *t, size_t n, char *saida, size_t tamanho) {
    if (n > (size_t)INT_MAX || n + 1 > tamanho) { if (tamanho) saida[0] = '\0'; return BK_ERRO_BUFFER; }
    memmove(saida, t, n + 1);
    return (int)n;
}

int bk_atualizar(const char *texto, char *saida, size_t tamanho) {
    if (!texto || !saida) return BK_ERRO_ARGUMENTO;
    size_t n = strlen(texto);
    if (n >= MAX_LINHA) return bk_entregar(texto, n, saida, tamanho);   /* não cabe no motor: sai igual */
    char tmp[MAX_LINHA];
    memcpy(tmp, texto, n + 1);
    bk_atualizar_no_lugar(tmp);
    return bk_entregar(tmp, strlen(tmp), saida, tamanho);
}

int bk_verso(const char *linha_md, char *saida, size_t tamanho) {
    if (!linha_md || !saida) return BK_ERRO_ARGUMENTO;
    /* limpar_texto_verso não confere tamanho; a saída dela nunca é maior que a entrada */
    if (strlen(linha_md) >= MAX_LINHA) { if (tamanho) saida[0] = '\0'; return BK_ERRO_GRANDE; }
    char tmp[MAX_LINHA];
    limpar_texto_verso(linha_md, tmp);
    bk_atualizar_no_lugar(tmp);
    return bk_entregar(tmp, strlen(tmp), saida, tamanho);
}

/* Mesma leitura de ler_capitulo() do motor (parte 4), linha por linha, sem arquivo. */
int bk_capitulo(const char *md, size_t tamanho, bk_item_cb cb, void *ctx) {
    if (!md || !cb) return BK_ERRO_ARGUMENTO;
    char linha[MAX_LINHA], limpo[MAX_LINHA];
    size_t p = 0;
    int itens = 0, primeira_linha = 1;
    while (p < tamanho) {
        /* como fgets(linha, MAX_LINHA, f): até '\n' (incluído) ou MAX_LINHA-1 bytes;
           "\r\n" vira "\n", como fgets em modo texto no Windows */
        size_t k = 0;
        while (p < tamanho && k < MAX_LINHA - 1) {
            char ch = md[p++];
            if (ch == '\r' && p < tamanho && md[p] == '\n') continue;
            linha[k++] = ch;
            if (ch == '\n') break;
        }
        linha[k] = '\0';
        /* linha maior que MAX_LINHA: o motor descarta o resto, para não virar versículo falso */
        if (k > 0 && linha[k - 1] != '\n' && p < tamanho) {
            while (p < tamanho && md[p++] != '\n') {}
        }
        if (primeira_linha && (unsigned char)linha[0] == 0xEF &&
            (unsigned char)linha[1] == 0xBB && (unsigned char)linha[2] == 0xBF) {
            memmove(linha, linha + 3, strlen(linha + 3) + 1);   /* tira o BOM do UTF-8 */
        }
        primeira_linha = 0;

        if (linha[0] == '-' && linha[1] == '-' && linha[2] == '-') break;   /* strncmp(linha, "---", 3) */
        if (linha[0] == '#' || linha[0] == '[') continue;

        int idx = 0;
        while (linha[idx] == '*' || linha[idx] == ' ') idx++;

        int tipo, numero = 0;
        if (linha[idx] >= '1' && linha[idx] <= '9') {
            int v = 0;
            while (linha[idx] >= '0' && linha[idx] <= '9' && v < 19) {   /* até 19 dígitos, como o motor */
                if (numero <= (INT_MAX - 9) / 10) numero = numero * 10 + (linha[idx] - '0');
                idx++; v++;
            }
            while (linha[idx] == '*' || linha[idx] == ' ') idx++;
            tipo = BK_VERSO;
        } else if (strncmp(linha, "**", 2) == 0 && linha[idx] != '\0' && linha[idx] != '\n' && linha[idx] != '\r') {
            tipo = BK_SUBTITULO;
        } else {
            continue;
        }
        limpar_texto_verso(&linha[idx], limpo);
        bk_atualizar_no_lugar(limpo);
        itens++;
        if (cb(ctx, tipo, numero, limpo, strlen(limpo)) != 0) return BK_ERRO_PARADO;
    }
    return itens;
}
