/* =============================================================================
- PROJETO: Bíblia Digital Almeida 1911 em PT-BR (Domínio Público)
-          Atualização Ortográfica e Gramatical realizada em 11/2026
- OBJETIVO: Leitor de terminal para Windows 10 e 11 (PowerShell / Windows Terminal). Mostra o menu, lê os capítulos
-           (.md) e os exibe em páginas centralizadas.
- TEXTO:   desde 28/11/2026 a limpeza do Markdown e a atualização ortográfica
-          vêm do kernel da Bíblia (pasta kernel/): o mesmo texto do motor,
-          cerca de 12 vezes mais rápido, já com os nomes próprios e a revisão
-          dos versículos. As regras não ficam neste arquivo: elas são
-          editadas no motor.biblia.c de origem (fora desta pasta) e o kernel
-          é gerado de novo a partir dele (veja kernel/LEIAME.md).
- AUTOR: Romulo CSR (GitHub: RomuloCSR)
- COMPILAR: gcc -O2 -Wall -Wextra terminal.c kernel/biblia_kernel.c -o motor.biblia.exe
- =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
    #include <windows.h>
    #ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
        #define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
    #endif
#else
    #include <unistd.h>
    #include <sys/ioctl.h>
#endif

#define MAX_LINHA 8192
#define LARGURA_PAGINA 74

/* Códigos ANSI suaves para conforto de leitura */
#define COR_RESET   "\033[0m"
#define COR_NEGRITO "\033[1m"
#define COR_ITALICO "\033[3m"
#define COR_VERSO   "\033[1;36m"
#define COR_TITULO  "\033[1;33m"
#define COR_BORDA   "\033[36m"
#define COR_DIM     "\033[2m"


/* -----------------------------------------------------------------------------
- 1. KERNEL DA BÍBLIA (livros, capítulos e texto)
-    Nomes, pastas e total de capítulos: bk_livro_nome/pasta/capitulos(0..65),
-    0..38 = Antigo Testamento, 39..65 = Novo Testamento.
-    Texto de cada verso ou subtítulo: bk_verso() (limpa o Markdown e atualiza
-    a ortografia). Os arquivos .md nunca são alterados; só lidos.
- ----------------------------------------------------------------------------- */
#include "kernel/biblia_kernel.h"
/* -----------------------------------------------------------------------------
- 2. UTILITÁRIOS DE INTERFACE, CENTRALIZAÇÃO E ENTRADA
- ----------------------------------------------------------------------------- */

void configurar_terminal(void) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    SetConsoleTitleA("Bíblia Digital Almeida 1911 PT-BR");

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif
}

void limpar_tela(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void limpar_buffer_entrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Lê uma linha de comando do usuário (1 único ENTER) e retorna o 1º caractere digitado */
int ler_comando_tecla(void) {
    char entrada[64];
    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        return '\n';
    }
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] != ' ' && entrada[i] != '\t' && entrada[i] != '\r') {
            return (unsigned char)entrada[i];
        }
    }
    return '\n';
}

void obter_dimensoes_terminal(int *largura, int *altura) {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        *largura = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        *altura = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        if (*largura > 0 && *altura > 0) return;
    }
    *largura = 80;
    *altura = 24;
#else
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0 && w.ws_col > 0 && w.ws_row > 0) {
        *largura = w.ws_col;
        *altura = w.ws_row;
    } else {
        *largura = 80;
        *altura = 24;
    }
#endif
}

int calcular_margem_esquerda(int largura_conteudo) {
    int cols = 80, rows = 24;
    obter_dimensoes_terminal(&cols, &rows);
    if (cols <= largura_conteudo) return 2;
    return (cols - largura_conteudo) / 2;
}

void imprimir_espacos(int qtd) {
    for (int i = 0; i < qtd; i++) {
        putchar(' ');
    }
}

int comprimento_visivel_utf8(const char *texto) {
    int visivel = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if ((texto[i] & 0xC0) != 0x80) {
            visivel++;
        }
    }
    return visivel;
}

void imprimir_linha_centralizada(const char *texto, int largura_pagina) {
    int visivel = comprimento_visivel_utf8(texto);
    int margem = calcular_margem_esquerda(largura_pagina);
    int recuo_interno = (largura_pagina > visivel) ? (largura_pagina - visivel) / 2 : 0;
    imprimir_espacos(margem + recuo_interno);
    printf("%s\n", texto);
}

void imprimir_separador(int largura_pagina, char simbolo) {
    int margem = calcular_margem_esquerda(largura_pagina);
    imprimir_espacos(margem);
    printf("%s", COR_BORDA);
    for (int i = 0; i < largura_pagina; i++) {
        putchar(simbolo);
    }
    printf("%s\n", COR_RESET);
}

void pausar_tela(void) {
    int margem = calcular_margem_esquerda(LARGURA_PAGINA);
    printf("\n");
    imprimir_espacos(margem);
    printf("%s[Pressione ENTER para voltar ao menu...]%s", COR_DIM, COR_RESET);
    fflush(stdout);
    ler_comando_tecla();
}

void exibir_data_hora(void) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    const char *dias_semana[] = {
        "Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira",
        "Quinta-feira", "Sexta-feira", "Sábado"
    };
    const char *meses[] = {
        "Jan", "Fev", "Mar", "Abr", "Mai", "Jun",
        "Jul", "Ago", "Set", "Out", "Nov", "Dez"
    };

    char cabecalho[128];
    snprintf(cabecalho, sizeof(cabecalho), "%s, %02d de %s de %d  |  %02d:%02d",
             dias_semana[tm.tm_wday],
             tm.tm_mday,
             meses[tm.tm_mon],
             tm.tm_year + 1900,
             tm.tm_hour,
             tm.tm_min);

    printf("%s", COR_DIM);
    imprimir_linha_centralizada(cabecalho, LARGURA_PAGINA);
    printf("%s", COR_RESET);
}

void imprimir_coluna(int numero, const char *texto) {
    int tamanho_visivel = comprimento_visivel_utf8(texto);

    printf(" %2d - %s", numero, texto);

    int espacos = 20 - tamanho_visivel;
    for (int j = 0; j < espacos; j++) {
        printf(" ");
    }
}

/* -----------------------------------------------------------------------------
- 4. LEITURA E EXIBIÇÃO DE CAPÍTULOS (.md) ESTILO PÁGINA CENTRALIZADA
- ----------------------------------------------------------------------------- */

FILE *abrir_arquivo_capitulo(const char *pasta_livro, int capitulo, char *caminho_out) {
    sprintf(caminho_out, "%s/%02d.md", pasta_livro, capitulo);
    FILE *f = fopen(caminho_out, "r");

    if (f == NULL) {
        sprintf(caminho_out, "%s/%03d.md", pasta_livro, capitulo);
        f = fopen(caminho_out, "r");
    }
    return f;
}

/* Retorna: 1 = continuar | 0 = voltar ('0') | 2 = reimprimir capítulo inteiro ('T') */
int verificar_pausa_pagina(int *linhas_na_pagina, int *modo_continuo, const char *nome_livro, int capitulo) {
    if (*modo_continuo) return 1;

    int cols = 80, rows = 24;
    obter_dimensoes_terminal(&cols, &rows);
    int limite_linhas = (rows > 8) ? (rows - 5) : 18;

    if (*linhas_na_pagina >= limite_linhas) {
        int margem = calcular_margem_esquerda(LARGURA_PAGINA);
        imprimir_separador(LARGURA_PAGINA, '-');
        imprimir_espacos(margem);
        printf("%s[ENTER] Próxima página  |  [T] Ler capítulo inteiro  |  [0] Voltar: %s",
               COR_DIM, COR_RESET);
        fflush(stdout);

        int ch = ler_comando_tecla();
        if (ch == '0') {
            return 0;
        }
        if (ch == 't' || ch == 'T') {
            *modo_continuo = 1;
            return 2;
        }

        limpar_tela();
        char cabecalho[160];
        snprintf(cabecalho, sizeof(cabecalho), "%s — Capítulo %d (continuação)", nome_livro, capitulo);
        imprimir_separador(LARGURA_PAGINA, '=');
        printf("%s", COR_TITULO);
        imprimir_linha_centralizada(cabecalho, LARGURA_PAGINA);
        printf("%s", COR_RESET);
        imprimir_separador(LARGURA_PAGINA, '=');
        printf("\n");
        *linhas_na_pagina = 4;
    }
    return 1;
}

void imprimir_verso_formatado(const char *versiculo_num, const char *texto, int *linhas_impressas) {
    int margem = calcular_margem_esquerda(LARGURA_PAGINA);
    char prefixo[32];
    snprintf(prefixo, sizeof(prefixo), "[%s] ", versiculo_num);
    int larg_prefixo = comprimento_visivel_utf8(prefixo);

    imprimir_espacos(margem);
    printf("%s%s%s", COR_VERSO, prefixo, COR_RESET);

    int col_atual = larg_prefixo;
    const char *p = texto;

    while (*p != '\0') {
        while (*p == ' ') p++;
        if (*p == '\0') break;

        const char *fim_palavra = p;
        int larg_palavra = 0;
        while (*fim_palavra != '\0' && *fim_palavra != ' ') {
            if ((*fim_palavra & 0xC0) != 0x80) {
                larg_palavra++;
            }
            fim_palavra++;
        }

        if (col_atual > larg_prefixo && (col_atual + 1 + larg_palavra) > LARGURA_PAGINA) {
            putchar('\n');
            (*linhas_impressas)++;
            imprimir_espacos(margem + larg_prefixo);
            col_atual = larg_prefixo;
        } else if (col_atual > larg_prefixo) {
            putchar(' ');
            col_atual++;
        }

        fwrite(p, 1, (size_t)(fim_palavra - p), stdout);
        col_atual += larg_palavra;
        p = fim_palavra;
    }

    printf("\n\n");
    (*linhas_impressas) += 2;
}

void imprimir_subtitulo_formatado(const char *texto, int *linhas_impressas) {
    int margem = calcular_margem_esquerda(LARGURA_PAGINA);
    imprimir_espacos(margem);
    printf("%s%s(%s)%s\n\n", COR_TITULO, COR_ITALICO, texto, COR_RESET);
    (*linhas_impressas) += 2;
}

/* Retorna 1 se leu até o fim (pede ENTER no final), ou 0 se usuário apertou '0' (volta direto) */
int ler_capitulo(const char *nome_livro, const char *pasta_livro, int capitulo) {
    char caminho_ficheiro[200];
    FILE *ficheiro = abrir_arquivo_capitulo(pasta_livro, capitulo, caminho_ficheiro);

    if (ficheiro == NULL) {
        int margem = calcular_margem_esquerda(LARGURA_PAGINA);
        printf("\n");
        imprimir_espacos(margem);
        printf("(Erro: Não foi possível encontrar o arquivo '%s'.)\n", caminho_ficheiro);
        return 1;
    }

    int modo_continuo = 0;

reiniciar_leitura:
    rewind(ficheiro);
    limpar_tela();

    char cabecalho[160];
    snprintf(cabecalho, sizeof(cabecalho), "%s — Capítulo %d", nome_livro, capitulo);

    imprimir_separador(LARGURA_PAGINA, '=');
    printf("%s", COR_TITULO);
    imprimir_linha_centralizada(cabecalho, LARGURA_PAGINA);
    printf("%s", COR_RESET);
    imprimir_separador(LARGURA_PAGINA, '=');
    printf("\n");

    char linha[MAX_LINHA];
    char texto_limpo[MAX_LINHA];
    int linhas_na_pagina = 4;

    while (fgets(linha, sizeof(linha), ficheiro) != NULL) {
        if (strncmp(linha, "---", 3) == 0) {
            break;
        }

        if (linha[0] == '#' || linha[0] == '[') {
            continue;
        }

        int idx = 0;
        while (linha[idx] == '*' || linha[idx] == ' ') {
            idx++;
        }

        if (linha[idx] >= '1' && linha[idx] <= '9') {
            int acao = verificar_pausa_pagina(&linhas_na_pagina, &modo_continuo, nome_livro, capitulo);
            if (acao == 0) {
                fclose(ficheiro);
                return 0;
            }
            if (acao == 2) {
                goto reiniciar_leitura;
            }

            char versiculo_num[20];
            int v_pos = 0;

            while (linha[idx] >= '0' && linha[idx] <= '9' && v_pos < 19) {
                versiculo_num[v_pos++] = linha[idx++];
            }
            versiculo_num[v_pos] = '\0';

            while (linha[idx] == '*' || linha[idx] == ' ') {
                idx++;
            }

            /* Kernel: limpa o Markdown e atualiza a ortografia (linha longa demais fica de fora) */
            if (bk_verso(&linha[idx], texto_limpo, sizeof(texto_limpo)) < 0) continue;
            imprimir_verso_formatado(versiculo_num, texto_limpo, &linhas_na_pagina);
        }
        else if (strncmp(linha, "**", 2) == 0 && linha[idx] != '\0' && linha[idx] != '\n') {
            int acao = verificar_pausa_pagina(&linhas_na_pagina, &modo_continuo, nome_livro, capitulo);
            if (acao == 0) {
                fclose(ficheiro);
                return 0;
            }
            if (acao == 2) {
                goto reiniciar_leitura;
            }

            /* Kernel: limpa o Markdown e atualiza a ortografia (linha longa demais fica de fora) */
            if (bk_verso(&linha[idx], texto_limpo, sizeof(texto_limpo)) < 0) continue;
            imprimir_subtitulo_formatado(texto_limpo, &linhas_na_pagina);
        }
    }

    imprimir_separador(LARGURA_PAGINA, '=');
    fclose(ficheiro);
    return 1;
}

/* -----------------------------------------------------------------------------
- 5. FUNÇÃO PRINCIPAL: main
- ----------------------------------------------------------------------------- */

int main(void) {
    configurar_terminal();

    int opcao_principal = 0;
    int opcao_livro = 0;
    int opcao_capitulo = 0;

    do {
        limpar_tela();
        exibir_data_hora();

        int margem = calcular_margem_esquerda(LARGURA_PAGINA);

        imprimir_separador(LARGURA_PAGINA, '=');
        printf("%s", COR_TITULO);
        imprimir_linha_centralizada("BÍBLIA DIGITAL ALMEIDA 1911 EM PT-BR (DOMÍNIO PÚBLICO)", LARGURA_PAGINA);
        imprimir_linha_centralizada("Atualização Ortográfica e Gramatical realizada em 11/2026", LARGURA_PAGINA);
        printf("%s%s", COR_RESET, COR_DIM);
        imprimir_linha_centralizada("Motor de navegação para Windows  |  Autor: Romulo CSR", LARGURA_PAGINA);
        imprimir_linha_centralizada("Download free: github.com/RomuloCSR", LARGURA_PAGINA);
        imprimir_linha_centralizada("Doação espontânea para a obra via PIX: 21980934118", LARGURA_PAGINA);
        printf("%s", COR_RESET);
        imprimir_separador(LARGURA_PAGINA, '=');
        printf("\n");

        imprimir_espacos(margem + 4); printf("1 - Antigo Testamento\n");
        imprimir_espacos(margem + 4); printf("2 - Novo Testamento\n");
        imprimir_espacos(margem + 4); printf("3 - Sair\n\n");
        imprimir_espacos(margem + 4); printf("%sZoom da fonte: Ctrl + = / - (ou Ctrl + roda do mouse)%s\n\n", COR_DIM, COR_RESET);
        imprimir_espacos(margem + 4); printf("Escolha uma opção: ");

        if (scanf("%d", &opcao_principal) != 1) {
            limpar_buffer_entrada();
            continue;
        }
        limpar_buffer_entrada();

        if (opcao_principal == 1 || opcao_principal == 2) {
            /* Livros do kernel: AT = 0..38, NT = 39..65 */
            int base = (opcao_principal == 1) ? 0 : 39;
            int total_livros = (opcao_principal == 1) ? 39 : 27;

            limpar_tela();
            imprimir_separador(LARGURA_PAGINA, '=');
            printf("%s", COR_TITULO);
            imprimir_linha_centralizada((opcao_principal == 1) ? "ANTIGO TESTAMENTO" : "NOVO TESTAMENTO", LARGURA_PAGINA);
            printf("%s", COR_RESET);
            imprimir_separador(LARGURA_PAGINA, '=');
            printf("\n");

            for (int i = 0; i < total_livros; i++) {
                if (i % 3 == 0) {
                    imprimir_espacos(margem);
                }
                imprimir_coluna(i + 1, bk_livro_nome(base + i));
                if ((i + 1) % 3 == 0) {
                    printf("\n");
                }
            }

            if (total_livros % 3 != 0) {
                printf("\n");
            }

            printf("\n");
            imprimir_espacos(margem); printf(" 0 - Voltar\n");
            imprimir_espacos(margem); printf(" Escolha um livro: ");
            if (scanf("%d", &opcao_livro) != 1) {
                limpar_buffer_entrada();
                continue;
            }
            limpar_buffer_entrada();

            if (opcao_livro >= 1 && opcao_livro <= total_livros) {
                int total_do_livro = bk_livro_capitulos(base + opcao_livro - 1);

                printf("\n");
                imprimir_espacos(margem);
                printf("%s selecionado. Digite o capítulo (1 a %d): ",
                       bk_livro_nome(base + opcao_livro - 1), total_do_livro);

                if (scanf("%d", &opcao_capitulo) == 1 &&
                    opcao_capitulo >= 1 && opcao_capitulo <= total_do_livro) {
                    limpar_buffer_entrada();
                    int leu_ate_o_fim = ler_capitulo(bk_livro_nome(base + opcao_livro - 1), bk_livro_pasta(base + opcao_livro - 1), opcao_capitulo);
                    if (leu_ate_o_fim) {
                        pausar_tela();
                    }
                } else {
                    limpar_buffer_entrada();
                    printf("\n");
                    imprimir_espacos(margem);
                    printf("Capítulo inválido! O livro de %s possui capítulos de 1 a %d.\n",
                           bk_livro_nome(base + opcao_livro - 1), total_do_livro);
                    pausar_tela();
                }
            } else if (opcao_livro != 0) {
                printf("\n");
                imprimir_espacos(margem);
                printf("Opção de livro inválida!\n");
                pausar_tela();
            }

        } else if (opcao_principal == 3) {
            int margem_saida = calcular_margem_esquerda(LARGURA_PAGINA);
            printf("\n");
            imprimir_espacos(margem_saida);
            printf("Saindo do aplicativo...\n");
        } else {
            int margem_inv = calcular_margem_esquerda(LARGURA_PAGINA);
            printf("\n");
            imprimir_espacos(margem_inv);
            printf("Opção inválida! Tente novamente.\n");
            pausar_tela();
        }

    } while (opcao_principal != 3);

    return 0;
}
