/* =============================================================================
- PROJETO: Bíblia Digital Almeida 1911 em PT-BR (Domínio Público)
-          Atualização Ortográfica e Gramatical realizada em 11/2026
- OBJETIVO: Motor de navegação multiplataforma (Windows 11 / Linux), limpeza
-           Markdown e atualização ortográfica/gramatical completa para PT-BR.
- AUTOR: Romulo CSR (GitHub: RomuloCSR)
- AMBIENTE: Windows 11 (PowerShell / Windows Terminal) & Linux / IDE Geany
- COMPILAR (Windows): gcc -O2 -Wall -Wextra motor.biblia.c -o motor.biblia.exe
- COMPILAR (Linux):   gcc -O2 -Wall -Wextra motor.biblia.c -o motor.biblia
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
- 1. MAPEAMENTO DE DADOS (PASTAS, NOMES E CONTAGEM DE CAPÍTULOS)
- ----------------------------------------------------------------------------- */

const char *pastas_at[39] = {
    "01-GEN", "02-EXO", "03-LEV", "04-NUM", "05-DEU", "06-JOS", "07-JDG", "08-RUT",
    "09-1SA", "10-2SA", "11-1KI", "12-2KI", "13-1CH", "14-2CH", "15-EZR",
    "16-NEH", "17-EST", "18-JOB", "19-PSA", "20-PRO", "21-ECC", "22-SNG",
    "23-ISA", "24-JER", "25-LAM", "26-EZK", "27-DAN", "28-HOS", "29-JOL",
    "30-AMO", "31-OBA", "32-JON", "33-MIC", "34-NAM", "35-HAB", "36-ZEP",
    "37-HAG", "38-ZEC", "39-MAL"
};

const char *pastas_nt[27] = {
    "41-MAT", "42-MRK", "43-LUK", "44-JHN", "45-ACT", "46-ROM", "47-1CO", "48-2CO",
    "49-GAL", "50-EPH", "51-PHP", "52-COL", "53-1TH", "54-2TH",
    "55-1TI", "56-2TI", "57-TIT", "58-PHM", "59-HEB", "60-JAS", "61-1PE", "62-2PE",
    "63-1JN", "64-2JN", "65-3JN", "66-JUD", "67-REV"
};

const char *nomes_at[39] = {
    "Gênesis", "Êxodo", "Levítico", "Números", "Deuteronômio", "Josué", "Juízes", "Rute",
    "1 Samuel", "2 Samuel", "1 Reis", "2 Reis", "1 Crônicas", "2 Crônicas", "Esdras",
    "Neemias", "Ester", "Jó", "Salmos", "Provérbios", "Eclesiastes", "Cânticos",
    "Isaías", "Jeremias", "Lamentações", "Ezequiel", "Daniel", "Oseias", "Joel",
    "Amós", "Obadias", "Jonas", "Miqueias", "Naum", "Habacuque", "Sofonias",
    "Ageu", "Zacarias", "Malaquias"
};

const char *nomes_nt[27] = {
    "Mateus", "Marcos", "Lucas", "João", "Atos", "Romanos", "1 Coríntios", "2 Coríntios",
    "Gálatas", "Efésios", "Filipenses", "Colossenses", "1 Tessalonicenses", "2 Tessalonicenses",
    "1 Timóteo", "2 Timóteo", "Tito", "Filemom", "Hebreus", "Tiago", "1 Pedro", "2 Pedro",
    "1 João", "2 João", "3 João", "Judas", "Apocalipse"
};

const int capitulos_at[39] = {
    50, 40, 27, 36, 34, 24, 21, 4,
    31, 24, 22, 25, 29, 36, 10,
    13, 10, 42, 150, 31, 12, 8,
    66, 52, 5, 48, 12, 14, 3,
    9, 1, 4, 7, 3, 3, 3,
    2, 14, 4
};

const int capitulos_nt[27] = {
    28, 16, 24, 21, 28, 16, 16, 13,
    6, 6, 4, 4, 5, 3,
    6, 4, 3, 1, 13, 5, 5, 3,
    5, 1, 1, 1, 22
};

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
- 3. MOTOR DE LIMPEZA E ATUALIZAÇÃO ORTOGRÁFICA / GRAMATICAL (PT-BR)
- ----------------------------------------------------------------------------- */

void substituir_texto(char *str, const char *antigo, const char *novo) {
    char buffer[MAX_LINHA];
    char *pos;
    size_t tam_antigo = strlen(antigo);
    size_t tam_novo = strlen(novo);
    size_t usado = 0;

    buffer[0] = '\0';
    char *atual = str;

    while ((pos = strstr(atual, antigo)) != NULL) {
        size_t trecho = (size_t)(pos - atual);
        if (usado + trecho + tam_novo >= MAX_LINHA - 1) break;

        memcpy(buffer + usado, atual, trecho);
        usado += trecho;

        memcpy(buffer + usado, novo, tam_novo);
        usado += tam_novo;

        atual = pos + tam_antigo;
    }

    size_t resto = strlen(atual);
    if (usado + resto < MAX_LINHA - 1) {
        memcpy(buffer + usado, atual, resto);
        usado += resto;
    }
    buffer[usado] = '\0';
    strcpy(str, buffer);
}

void substituir_inicio_palavra(char *str, const char *antigo, const char *novo) {
    char buffer[MAX_LINHA];
    char *pos;
    size_t tam_antigo = strlen(antigo);
    size_t tam_novo = strlen(novo);
    size_t usado = 0;

    /* A regra acrescenta acento? (o "novo" tem mais bytes não-ASCII que o "antigo") */
    int nao_ascii_antigo = 0, nao_ascii_novo = 0;
    for (size_t k = 0; k < tam_antigo; k++) if ((unsigned char)antigo[k] >= 0x80) nao_ascii_antigo++;
    for (size_t k = 0; k < tam_novo; k++) if ((unsigned char)novo[k] >= 0x80) nao_ascii_novo++;
    int acrescenta_acento = nao_ascii_novo > nao_ascii_antigo;
    /* Regras que só tiram o "h" antigo (sahi -> saí, trahi -> traí) valem para todo o verbo */
    if (strchr(antigo, 'h') != NULL && strchr(novo, 'h') == NULL) acrescenta_acento = 0;

    buffer[0] = '\0';
    char *atual = str;

    while ((pos = strstr(atual, antigo)) != NULL) {
        int eh_inicio = 0;
        if (pos == str) {
            eh_inicio = 1;
        } else {
            unsigned char prev = (unsigned char)*(pos - 1);
            if (prev < 0x80 && !isalpha(prev)) {
                eh_inicio = 1;
            }
        }

        /* Proteção: se a regra ACRESCENTA acento (ex.: gloria -> glória),
           só vale para a palavra e suas formas nominais (-s, -o, -a, -os, -as).
           Evita "gloriar" -> "glóriar", "continuou" -> "contínuou", "homens" -> "homems". */
        if (eh_inicio && acrescenta_acento) {
            const char *resto_p = pos + tam_antigo;
            int tam_resto = 0;
            while (resto_p[tam_resto] != '\0' &&
                   !((unsigned char)resto_p[tam_resto] < 0x80 && !isalpha((unsigned char)resto_p[tam_resto]))) {
                tam_resto++;
            }
            int resto_ok = (tam_resto == 0) ||
                (tam_resto == 1 && (resto_p[0] == 's' || resto_p[0] == 'o' || resto_p[0] == 'a')) ||
                (tam_resto == 2 && resto_p[1] == 's' && (resto_p[0] == 'o' || resto_p[0] == 'a' || resto_p[0] == 'e'));
            if (!resto_ok) eh_inicio = 0;
        }

        if (!eh_inicio) {
            size_t avanco = (size_t)(pos - atual) + 1;
            if (usado + avanco >= MAX_LINHA - 1) break;
            memcpy(buffer + usado, atual, avanco);
            usado += avanco;
            atual = pos + 1;
            continue;
        }

        size_t trecho = (size_t)(pos - atual);
        if (usado + trecho + tam_novo >= MAX_LINHA - 1) break;

        memcpy(buffer + usado, atual, trecho);
        usado += trecho;

        memcpy(buffer + usado, novo, tam_novo);
        usado += tam_novo;

        atual = pos + tam_antigo;
    }

    size_t resto = strlen(atual);
    if (usado + resto < MAX_LINHA - 1) {
        memcpy(buffer + usado, atual, resto);
        usado += resto;
    }
    buffer[usado] = '\0';
    strcpy(str, buffer);
}

void substituir_palavra_inteira(char *str, const char *antigo, const char *novo) {
    char buffer[MAX_LINHA];
    char *pos;
    size_t tam_antigo = strlen(antigo);
    size_t tam_novo = strlen(novo);
    size_t usado = 0;

    buffer[0] = '\0';
    char *atual = str;

    while ((pos = strstr(atual, antigo)) != NULL) {
        int eh_inicio = 0;
        int eh_fim = 0;

        if (pos == str) {
            eh_inicio = 1;
        } else {
            unsigned char prev = (unsigned char)*(pos - 1);
            if (prev < 0x80 && !isalpha(prev)) {
                eh_inicio = 1;
            }
        }

        unsigned char next = (unsigned char)*(pos + tam_antigo);
        if (next == '\0' || (next < 0x80 && !isalpha(next))) {
            eh_fim = 1;
        }

        if (!eh_inicio || !eh_fim) {
            size_t avanco = (size_t)(pos - atual) + 1;
            if (usado + avanco >= MAX_LINHA - 1) break;
            memcpy(buffer + usado, atual, avanco);
            usado += avanco;
            atual = pos + 1;
            continue;
        }

        size_t trecho = (size_t)(pos - atual);
        if (usado + trecho + tam_novo >= MAX_LINHA - 1) break;

        memcpy(buffer + usado, atual, trecho);
        usado += trecho;

        memcpy(buffer + usado, novo, tam_novo);
        usado += tam_novo;

        atual = pos + tam_antigo;
    }

    size_t resto = strlen(atual);
    if (usado + resto < MAX_LINHA - 1) {
        memcpy(buffer + usado, atual, resto);
        usado += resto;
    }
    buffer[usado] = '\0';
    strcpy(str, buffer);
}

void converter_infinitivo_lusitano_para_gerundio(char *texto) {
    static const char *auxiliares[] = {
        "estava a ", "Estava a ",
        "estavam a ", "Estavam a ",
        "estando a ", "Estando a ",
        "esteve a ", "Esteve a ",
        "estiveram a ", "Estiveram a ",
        "está a ", "Está a ",
        "estão a ", "Estão a ",
        "andava a ", "Andava a ",
        "andavam a ", "Andavam a ",
        "andando a ", "Andando a ",
        "continuava a ", "Continuava a ",
        "continuavam a ", "Continuavam a ",
        "ficou a ", "Ficou a ",
        "ficaram a ", "Ficaram a "
    };

    int total_aux = (int)(sizeof(auxiliares) / sizeof(auxiliares[0]));

    for (int a = 0; a < total_aux; a++) {
        const char *aux = auxiliares[a];
        size_t tam_aux = strlen(aux);
        char *pos = texto;

        while ((pos = strstr(pos, aux)) != NULL) {
            if (pos != texto) {
                unsigned char prev = (unsigned char)*(pos - 1);
                if (!(prev < 0x80 && !isalpha(prev))) {
                    pos++;
                    continue;
                }
            }

            char *verbo = pos + tam_aux;
            int v_len = 0;
            while (verbo[v_len] != '\0' && (unsigned char)verbo[v_len] >= 'A') {
                if ((unsigned char)verbo[v_len] < 0x80 && !isalpha((unsigned char)verbo[v_len])) {
                    break;
                }
                v_len++;
            }

            if (v_len >= 4) {
                char vogal = verbo[v_len - 2];
                char erre = verbo[v_len - 1];
                if (erre == 'r' && (vogal == 'a' || vogal == 'e' || vogal == 'i' || vogal == 'o')) {
                    char aux_sem_a[64];
                    memcpy(aux_sem_a, aux, tam_aux - 2);
                    aux_sem_a[tam_aux - 2] = '\0';

                    char antigo_trecho[192];
                    char novo_trecho[192];

                    if (tam_aux + (size_t)v_len < 180) {
                        memcpy(antigo_trecho, pos, tam_aux + (size_t)v_len);
                        antigo_trecho[tam_aux + (size_t)v_len] = '\0';

                        char verbo_gerundio[128];
                        memcpy(verbo_gerundio, verbo, (size_t)(v_len - 1));
                        verbo_gerundio[v_len - 1] = '\0';
                        strcat(verbo_gerundio, "ndo");

                        sprintf(novo_trecho, "%s%s", aux_sem_a, verbo_gerundio);
                        substituir_texto(texto, antigo_trecho, novo_trecho);
                        pos = texto;
                        continue;
                    }
                }
            }
            pos += tam_aux;
        }
    }
}

int eh_delimitador(unsigned char c) {
    return (c == '\0' || c == ' ' || c == ',' || c == '.' || c == ';' ||
            c == ':' || c == '!' || c == '?' || c == ')' || c == '(' ||
            c == '"' || c == '\n' || c == '\r');
}

int eh_vogal_simples(char c) {
    c = (char)tolower((unsigned char)c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void normalizar_composto_hifen(char *palavra) {
    char *hifen = strchr(palavra, '-');
    if (hifen == NULL) return;

    int pos_hifen = (int)(hifen - palavra);
    char radical[128];
    char sufixo[128];

    if (pos_hifen <= 0 || pos_hifen >= 120) return;
    memcpy(radical, palavra, (size_t)pos_hifen);
    radical[pos_hifen] = '\0';
    strcpy(sufixo, hifen);

    if (pos_hifen >= 3 && radical[pos_hifen - 2] == 'a' && radical[pos_hifen - 1] == 'e') {
        radical[pos_hifen - 1] = 'i';
    }
    else if (strcmp(radical, "pôz") == 0 || strcmp(radical, "poz") == 0) {
        strcpy(radical, "pôs");
    } else if (strcmp(radical, "Pôz") == 0 || strcmp(radical, "Poz") == 0) {
        strcpy(radical, "Pôs");
    } else if (strcmp(radical, "quiz") == 0) {
        strcpy(radical, "quis");
    } else if (strcmp(radical, "poude") == 0) {
        strcpy(radical, "pôde");
    } else if (strcmp(radical, "sahi") == 0) {
        strcpy(radical, "saí");
    } else if (strcmp(radical, "cahi") == 0) {
        strcpy(radical, "caí");
    } else if (strcmp(radical, "trahi") == 0) {
        strcpy(radical, "traí");
    } else if (strcmp(radical, "attrahi") == 0) {
        strcpy(radical, "atraí");
    } else if (strcmp(radical, "distrahi") == 0) {
        strcpy(radical, "distraí");
    }

    sprintf(palavra, "%s%s", radical, sufixo);
}

void atualizar_sufixos_e_enclises(char *str) {
    char buffer[MAX_LINHA];
    int i = 0, pos = 0;

    while (str[i] != '\0' && pos < MAX_LINHA - 16) {
        if (eh_delimitador((unsigned char)str[i])) {
            buffer[pos++] = str[i++];
            continue;
        }

        int inicio = i;
        while (!eh_delimitador((unsigned char)str[i])) {
            i++;
        }
        int len = i - inicio;
        char palavra[256];
        if (len >= 250) {
            memcpy(buffer + pos, str + inicio, (size_t)len);
            pos += len;
            continue;
        }
        memcpy(palavra, str + inicio, (size_t)len);
        palavra[len] = '\0';

        normalizar_composto_hifen(palavra);
        len = (int)strlen(palavra);

        struct RegraSufixo {
            const char *antigo;
            const char *novo;
            int min_raiz;
        };

        static const struct RegraSufixo regras[] = {
            {"al-o-hei", "á-lo-ei", 1}, {"al-a-hei", "á-la-ei", 1},
            {"al-os-hei", "á-los-ei", 1}, {"al-as-hei", "á-las-ei", 1},
            {"el-o-hei", "ê-lo-ei", 1}, {"el-a-hei", "ê-la-ei", 1},
            {"el-os-hei", "ê-los-ei", 1}, {"el-as-hei", "ê-las-ei", 1},
            {"ôl-o-hei", "ô-lo-ei", 1}, {"ol-o-hei", "ô-lo-ei", 1},
            {"il-o-hei", "i-lo-ei", 1}, {"il-a-hei", "i-la-ei", 1},
            {"al-o-hão", "á-lo-ão", 1}, {"al-a-hão", "á-la-ão", 1},
            {"al-os-hão", "á-los-ão", 1}, {"al-as-hão", "á-las-ão", 1},
            {"al-o-ha", "á-lo-á", 1}, {"al-a-ha", "á-la-á", 1},
            {"el-o-hão", "ê-lo-ão", 1}, {"el-a-hão", "ê-la-ão", 1},
            {"el-os-hão", "ê-los-ão", 1}, {"el-as-hão", "ê-las-ão", 1},
            {"el-o-ha", "ê-lo-á", 1}, {"el-a-ha", "ê-la-á", 1},
            {"il-o-hão", "i-lo-ão", 1}, {"il-a-hão", "i-la-ão", 1},
            {"il-o-ha", "i-lo-á", 1}, {"il-a-ha", "i-la-á", 1},
            {"-se-ha", "-se-á", 2}, {"-se-hão", "-se-ão", 2},
            {"-lhe-ha", "-lhe-á", 2}, {"-lhe-hão", "-lhe-ão", 2},
            {"-lhes-ha", "-lhes-á", 2}, {"-lhes-hão", "-lhes-ão", 2},

            {"nol-o", "no-lo", 0}, {"nol-a", "no-la", 0}, {"nol-os", "no-los", 0}, {"nol-as", "no-las", 0},
            {"vol-o", "vo-lo", 0}, {"vol-a", "vo-la", 0}, {"vol-os", "vo-los", 0}, {"vol-as", "vo-las", 0},
            {"al-o", "á-lo", 1}, {"al-a", "á-la", 1}, {"al-os", "á-los", 1}, {"al-as", "á-las", 1},
            {"el-o", "ê-lo", 1}, {"el-a", "ê-la", 1}, {"el-os", "ê-los", 1}, {"el-as", "ê-las", 1},
            {"ôl-o", "ô-lo", 1}, {"ôl-a", "ô-la", 1}, {"ôl-os", "ô-los", 1}, {"ôl-as", "ô-las", 1},
            {"ol-o", "ô-lo", 1}, {"ol-a", "ô-la", 1}, {"ol-os", "ô-los", 1}, {"ol-as", "ô-las", 1},

            {"ámos", "amos", 2},
            {"áras", "aras", 2},
            {"ára", "ara", 2},
            {"êras", "eras", 2},
            {"êra", "era", 2},
            {"aes", "ais", 1},
            {"ae", "ai", 1},

            {"avamos", "ávamos", 2},
            {"iamos", "íamos", 2},
            {"ieis", "íeis", 2},
            {"assemos", "ássemos", 2},
            {"essemos", "êssemos", 2},
            {"issemos", "íssemos", 2},
            {"asseis", "ásseis", 2},
            {"esseis", "êsseis", 2},
            {"isseis", "ísseis", 2},

            {"aveis", "áveis", 2},
            {"iveis", "íveis", 2},
            {"avel", "ável", 2},
            {"ivel", "ível", 2},
            {"issimos", "íssimos", 2},
            {"issimas", "íssimas", 2},
            {"issimo", "íssimo", 2},
            {"issima", "íssima", 2},
            {"encias", "ências", 2},
            {"encia", "ência", 2},
            {"ancias", "âncias", 0},
            {"ancia", "ância", 0}
        };

        int aplicado = 0;
        int total_regras = (int)(sizeof(regras) / sizeof(regras[0]));

        for (int r = 0; r < total_regras; r++) {
            int tam_ant = (int)strlen(regras[r].antigo);
            if (len >= tam_ant + regras[r].min_raiz &&
                strcmp(palavra + len - tam_ant, regras[r].antigo) == 0) {
                palavra[len - tam_ant] = '\0';
                strcat(palavra, regras[r].novo);
                aplicado = 1;
                break;
            }
        }

        if (!aplicado && len >= 5) {
            const char *suf_il[] = {"il-o", "il-a", "il-os", "il-as"};
            const char *rep_hiato[] = {"í-lo", "í-la", "í-los", "í-las"};
            const char *rep_cons[] = {"i-lo", "i-la", "i-los", "i-las"};

            for (int k = 0; k < 4; k++) {
                int tam_s = (int)strlen(suf_il[k]);
                if (len > tam_s && strcmp(palavra + len - tam_s, suf_il[k]) == 0) {
                    char antes = palavra[len - tam_s - 1];
                    palavra[len - tam_s] = '\0';
                    strcat(palavra, eh_vogal_simples(antes) ? rep_hiato[k] : rep_cons[k]);
                    break;
                }
            }
        }

        int novo_len = (int)strlen(palavra);
        memcpy(buffer + pos, palavra, (size_t)novo_len);
        pos += novo_len;
    }

    buffer[pos] = '\0';
    strcpy(str, buffer);
}

void atualizar_ortografia(char *texto) {
    // 1. Padroniza apóstrofo curvo UTF-8 (’) para apóstrofo simples (')
    substituir_texto(texto, "\xE2\x80\x99", "'");

    // 2. Contrações antigas com apóstrofo (formas aglutinadas)
    substituir_inicio_palavra(texto, "d'elle", "dele");      substituir_inicio_palavra(texto, "D'elle", "Dele");
    substituir_inicio_palavra(texto, "d'ella", "dela");      substituir_inicio_palavra(texto, "D'ella", "Dela");
    substituir_inicio_palavra(texto, "d'elles", "deles");    substituir_inicio_palavra(texto, "D'elles", "Deles");
    substituir_inicio_palavra(texto, "d'ellas", "delas");    substituir_inicio_palavra(texto, "D'ellas", "Delas");
    substituir_inicio_palavra(texto, "n'elle", "nele");      substituir_inicio_palavra(texto, "N'elle", "Nele");
    substituir_inicio_palavra(texto, "n'ella", "nela");      substituir_inicio_palavra(texto, "N'ella", "Nela");
    substituir_inicio_palavra(texto, "n'elles", "neles");    substituir_inicio_palavra(texto, "N'elles", "Neles");
    substituir_inicio_palavra(texto, "n'ellas", "nelas");    substituir_inicio_palavra(texto, "N'ellas", "Nelas");
    substituir_inicio_palavra(texto, "d'este", "deste");     substituir_inicio_palavra(texto, "D'este", "Deste");
    substituir_inicio_palavra(texto, "d'esta", "desta");     substituir_inicio_palavra(texto, "D'esta", "Desta");
    substituir_inicio_palavra(texto, "d'estes", "destes");   substituir_inicio_palavra(texto, "d'estas", "destas");
    substituir_inicio_palavra(texto, "n'este", "neste");     substituir_inicio_palavra(texto, "n'esta", "nesta");
    substituir_inicio_palavra(texto, "n'estes", "nestes");   substituir_inicio_palavra(texto, "n'estas", "nestas");
    substituir_inicio_palavra(texto, "d'isto", "disto");     substituir_inicio_palavra(texto, "n'isto", "nisto");
    substituir_inicio_palavra(texto, "d'isso", "disso");     substituir_inicio_palavra(texto, "n'isso", "nisso");
    substituir_inicio_palavra(texto, "d'aquillo", "daquilo");substituir_inicio_palavra(texto, "n'aquillo", "naquilo");
    substituir_inicio_palavra(texto, "d'um", "dum");         substituir_inicio_palavra(texto, "d'uma", "duma");
    substituir_inicio_palavra(texto, "d'uns", "duns");       substituir_inicio_palavra(texto, "d'umas", "dumas");
    substituir_inicio_palavra(texto, "n'um", "num");         substituir_inicio_palavra(texto, "n'uma", "numa");
    substituir_inicio_palavra(texto, "n'uns", "nuns");       substituir_inicio_palavra(texto, "n'umas", "numas");
    substituir_inicio_palavra(texto, "d'aquelle", "daquele");substituir_inicio_palavra(texto, "d'aquella", "daquela");
    substituir_inicio_palavra(texto, "n'aquelle", "naquele");substituir_inicio_palavra(texto, "n'aquella", "naquela");
    substituir_inicio_palavra(texto, "aquell'outro", "aqueloutro");
    substituir_inicio_palavra(texto, "d'aqui", "daqui");     substituir_inicio_palavra(texto, "d'alli", "dali");
    substituir_inicio_palavra(texto, "d'ali", "dali");
    substituir_inicio_palavra(texto, "d'onde", "donde");     substituir_inicio_palavra(texto, "D'onde", "Donde");
    substituir_inicio_palavra(texto, "lh'o", "lho");         substituir_inicio_palavra(texto, "lh'a", "lha");
    substituir_inicio_palavra(texto, "lh'os", "lhos");       substituir_inicio_palavra(texto, "lh'as", "lhas");

    /* Contrações com maiúscula e outras que faltavam (antes: "N'aquelle" -> "Em aquele") */
    substituir_inicio_palavra(texto, "N'aquelles", "Naqueles"); substituir_inicio_palavra(texto, "N'aquellas", "Naquelas");
    substituir_inicio_palavra(texto, "N'aquelle", "Naquele");   substituir_inicio_palavra(texto, "N'aquella", "Naquela");
    substituir_inicio_palavra(texto, "N'aquillo", "Naquilo");   substituir_inicio_palavra(texto, "D'aquillo", "Daquilo");
    substituir_inicio_palavra(texto, "D'aquelle", "Daquele");   substituir_inicio_palavra(texto, "D'aquella", "Daquela");
    substituir_inicio_palavra(texto, "D'aquelles", "Daqueles"); substituir_inicio_palavra(texto, "D'aquellas", "Daquelas");
    substituir_inicio_palavra(texto, "d'aquelles", "daqueles"); substituir_inicio_palavra(texto, "d'aquellas", "daquelas");
    substituir_inicio_palavra(texto, "n'aquelles", "naqueles"); substituir_inicio_palavra(texto, "n'aquellas", "naquelas");
    substituir_inicio_palavra(texto, "N'isto", "Nisto");        substituir_inicio_palavra(texto, "N'isso", "Nisso");
    substituir_inicio_palavra(texto, "D'isto", "Disto");        substituir_inicio_palavra(texto, "D'isso", "Disso");
    substituir_inicio_palavra(texto, "N'este", "Neste");        substituir_inicio_palavra(texto, "N'esta", "Nesta");
    substituir_inicio_palavra(texto, "N'estes", "Nestes");      substituir_inicio_palavra(texto, "N'estas", "Nestas");
    substituir_inicio_palavra(texto, "N'esse", "Nesse");        substituir_inicio_palavra(texto, "N'essa", "Nessa");
    substituir_inicio_palavra(texto, "n'esse", "nesse");        substituir_inicio_palavra(texto, "n'essa", "nessa");
    substituir_inicio_palavra(texto, "n'esses", "nesses");      substituir_inicio_palavra(texto, "n'essas", "nessas");
    substituir_inicio_palavra(texto, "d'esse", "desse");        substituir_inicio_palavra(texto, "d'essa", "dessa");
    substituir_inicio_palavra(texto, "N'um", "Num");            substituir_inicio_palavra(texto, "N'uma", "Numa");
    substituir_inicio_palavra(texto, "n'algum", "nalgum");      substituir_inicio_palavra(texto, "n'alguma", "nalguma");
    substituir_inicio_palavra(texto, "n'alguns", "nalguns");    substituir_inicio_palavra(texto, "n'algumas", "nalgumas");
    substituir_inicio_palavra(texto, "n'outro", "noutro");      substituir_inicio_palavra(texto, "n'outra", "noutra");
    substituir_inicio_palavra(texto, "n'outros", "noutros");    substituir_inicio_palavra(texto, "n'outras", "noutras");
    /* Pronome depois de hífen: "ataram-n'o" -> "ataram-no" (antes virava "ataram-em o") */
    substituir_texto(texto, "-n'os", "-nos");                   substituir_texto(texto, "-n'as", "-nas");
    substituir_texto(texto, "-n'o", "-no");                     substituir_texto(texto, "-n'a", "-na");
    /* me/te + o/a: "m'o" -> "mo", "t'a" -> "ta" */
    substituir_inicio_palavra(texto, "m'os", "mos");            substituir_inicio_palavra(texto, "m'as", "mas");
    substituir_inicio_palavra(texto, "m'o", "mo");              substituir_inicio_palavra(texto, "m'a", "ma");
    substituir_inicio_palavra(texto, "t'os", "tos");            substituir_inicio_palavra(texto, "t'as", "tas");
    substituir_inicio_palavra(texto, "t'o", "to");              substituir_inicio_palavra(texto, "t'a", "ta");

    substituir_inicio_palavra(texto, "d'", "de ");
    substituir_inicio_palavra(texto, "D'", "De ");
    substituir_inicio_palavra(texto, "n'", "em ");
    substituir_inicio_palavra(texto, "N'", "Em ");

    // 3. Crase antiga com acento agudo e locuções
    substituir_texto(texto, " á ", " à ");
    substituir_texto(texto, " ás ", " às ");
    substituir_inicio_palavra(texto, "Á ", "À ");
    substituir_inicio_palavra(texto, "Ás ", "Às ");
    substituir_inicio_palavra(texto, "áquel", "àquel");
    substituir_inicio_palavra(texto, "Áquel", "Àquel");
    substituir_inicio_palavra(texto, "ámanhã", "amanhã");
    substituir_inicio_palavra(texto, "Ámanhã", "Amanhã");
    substituir_inicio_palavra(texto, "áparte", "à parte");
    substituir_inicio_palavra(texto, "áquem", "aquém");
    substituir_inicio_palavra(texto, "ácerca", "acerca");
    substituir_inicio_palavra(texto, "Ácerca", "Acerca");
    substituir_texto(texto, "afim de", "a fim de");

    // 4. Regras críticas ANTES da simplificação de consoantes dobradas
    substituir_inicio_palavra(texto, "sabbado", "sábado");
    substituir_inicio_palavra(texto, "Sabbado", "Sábado");
    substituir_inicio_palavra(texto, "SABBADO", "SÁBADO");
    substituir_inicio_palavra(texto, "attrahi", "atraí");
    substituir_inicio_palavra(texto, "Attrahi", "Atraí");
    substituir_inicio_palavra(texto, "attrahe", "atrai");
    substituir_inicio_palavra(texto, "ressurg", "ressurg");
    substituir_inicio_palavra(texto, "resvall", "resval");

    // 5. Dígrafos antigos (Ph, Th, Y) e consoantes dobradas (maiúsculas e minúsculas)
    substituir_texto(texto, "PH", "F");
    substituir_texto(texto, "Ph", "F");
    substituir_texto(texto, "ph", "f");
    substituir_texto(texto, "TH", "T");
    substituir_texto(texto, "Th", "T");
    substituir_texto(texto, "th", "t");
    substituir_texto(texto, "Y", "I");
    substituir_texto(texto, "y", "i");

    substituir_texto(texto, "ll", "l"); substituir_texto(texto, "LL", "L");
    substituir_texto(texto, "mm", "m"); substituir_texto(texto, "MM", "M");
    substituir_texto(texto, "nn", "n"); substituir_texto(texto, "NN", "N");
    substituir_texto(texto, "ff", "f"); substituir_texto(texto, "FF", "F");
    substituir_texto(texto, "pp", "p"); substituir_texto(texto, "PP", "P");
    substituir_texto(texto, "tt", "t"); substituir_texto(texto, "TT", "T");
    substituir_texto(texto, "cc", "c"); substituir_texto(texto, "CC", "C");
    substituir_texto(texto, "dd", "d"); substituir_texto(texto, "DD", "D");
    substituir_texto(texto, "bb", "b"); substituir_texto(texto, "BB", "B");
    substituir_texto(texto, "gg", "g"); substituir_texto(texto, "GG", "G");

    // 6. Grupos consonantais mudos (cç, ct, pt, mn, gm, ch -> c/qu)
    substituir_texto(texto, "cç", "ç");
    substituir_inicio_palavra(texto, "CHRIST", "CRIST");
    substituir_inicio_palavra(texto, "Christ", "Crist");
    substituir_inicio_palavra(texto, "christ", "crist");
    substituir_inicio_palavra(texto, "chronic", "crônic");
    substituir_inicio_palavra(texto, "archanjo", "arcanjo");
    substituir_inicio_palavra(texto, "architecto", "arquiteto");
    substituir_inicio_palavra(texto, "sepulchr", "sepulcr");
    substituir_inicio_palavra(texto, "patriarch", "patriarc");
    substituir_inicio_palavra(texto, "tetrarch", "tetrarc");
    substituir_inicio_palavra(texto, "eunuch", "eunuc");
    substituir_inicio_palavra(texto, "mechanic", "mecânic");
    substituir_inicio_palavra(texto, "paschoa", "Páscoa");
    substituir_inicio_palavra(texto, "Paschoa", "Páscoa");
    substituir_inicio_palavra(texto, "chalcedonia", "calcedônia");
    substituir_inicio_palavra(texto, "Chaldea", "Caldeia");
    substituir_inicio_palavra(texto, "chaldeo", "caldeu");

    substituir_texto(texto, "fruct", "frut");
    substituir_texto(texto, "Fruct", "Frut");
    substituir_inicio_palavra(texto, "sanct", "sant");
    substituir_inicio_palavra(texto, "Sanct", "Sant");
    substituir_inicio_palavra(texto, "SANCT", "SANT");
    substituir_inicio_palavra(texto, "afflict", "aflit");
    substituir_inicio_palavra(texto, "victima", "vítima");
    substituir_inicio_palavra(texto, "victoria", "vitória");
    substituir_inicio_palavra(texto, "victorios", "vitorios");
    substituir_inicio_palavra(texto, "luct", "lut");
    substituir_inicio_palavra(texto, "Luct", "Lut");
    substituir_inicio_palavra(texto, "nocturn", "noturn");
    substituir_inicio_palavra(texto, "delict", "delit");
    substituir_inicio_palavra(texto, "edict", "édit");
    substituir_inicio_palavra(texto, "distinct", "distint");
    substituir_inicio_palavra(texto, "extinct", "extint");
    substituir_inicio_palavra(texto, "contract", "contrat");
    substituir_inicio_palavra(texto, "detractor", "detrator");
    substituir_inicio_palavra(texto, "predilect", "predilet");
    substituir_inicio_palavra(texto, "rectidão", "retidão");
    substituir_inicio_palavra(texto, "rectamente", "retamente");
    substituir_inicio_palavra(texto, "rectaguarda", "retaguarda");
    substituir_inicio_palavra(texto, "object", "objet");
    substituir_inicio_palavra(texto, "project", "projet");
    substituir_inicio_palavra(texto, "Project", "Projet");
    substituir_inicio_palavra(texto, "product", "produt");
    substituir_inicio_palavra(texto, "exact", "exat");
    substituir_inicio_palavra(texto, "acto", "ato");
    substituir_inicio_palavra(texto, "actos", "atos");
    substituir_texto(texto, "escript", "escrit");
    substituir_texto(texto, "Escript", "Escrit");
    substituir_inicio_palavra(texto, "captiv", "cativ");
    substituir_inicio_palavra(texto, "prompt", "pront");
    substituir_inicio_palavra(texto, "assump", "assun");
    substituir_inicio_palavra(texto, "presump", "presun");
    substituir_inicio_palavra(texto, "redemp", "reden");
    substituir_inicio_palavra(texto, "Redemp", "Reden");
    substituir_inicio_palavra(texto, "exempt", "isent");
    substituir_inicio_palavra(texto, "bapt", "bat");
    substituir_inicio_palavra(texto, "Bapt", "Bat");
    substituir_inicio_palavra(texto, "sceptr", "cetr");
    substituir_inicio_palavra(texto, "inscrip", "inscri");
    substituir_inicio_palavra(texto, "descrip", "descri");
    substituir_inicio_palavra(texto, "prescrip", "prescri");
    substituir_inicio_palavra(texto, "augment", "aument");
    substituir_inicio_palavra(texto, "Augment", "Aument");
    substituir_inicio_palavra(texto, "condemn", "conden");
    substituir_inicio_palavra(texto, "Condemn", "Conden");
    substituir_inicio_palavra(texto, "solemn", "solen");
    substituir_inicio_palavra(texto, "Solemn", "Solen");
    substituir_inicio_palavra(texto, "damn", "dan");
    substituir_inicio_palavra(texto, "somno", "sono");
    substituir_inicio_palavra(texto, "hymno", "hino");
    substituir_inicio_palavra(texto, "alumno", "aluno");
    substituir_inicio_palavra(texto, "calumni", "calúni");    /* calúnia(s) */
    substituir_inicio_palavra(texto, "calumni", "caluni");    /* caluniar, caluniador... */
    substituir_inicio_palavra(texto, "columna", "coluna");
    substituir_inicio_palavra(texto, "Omnipotente", "Onipotente");
    substituir_inicio_palavra(texto, "omnipotente", "onipotente");
    substituir_inicio_palavra(texto, "signa", "sina");
    substituir_inicio_palavra(texto, "signal", "sinal");
    substituir_inicio_palavra(texto, "assign", "assin");
    substituir_inicio_palavra(texto, "Assign", "Assin");
    substituir_inicio_palavra(texto, "psalm", "salm");
    substituir_inicio_palavra(texto, "Psalm", "Salm");
    substituir_inicio_palavra(texto, "sciencia", "ciência");

    // 7. Aplica regras morfológicas de sufixos, ênclises, mesóclises e compostos com hífen
    /* "eil-o" -> "ei-lo" (sem acento); precisa vir antes das ênclises */
    substituir_palavra_inteira(texto, "eil-o", "ei-lo");     substituir_palavra_inteira(texto, "Eil-o", "Ei-lo");
    substituir_palavra_inteira(texto, "eil-a", "ei-la");     substituir_palavra_inteira(texto, "Eil-a", "Ei-la");
    substituir_palavra_inteira(texto, "eil-os", "ei-los");   substituir_palavra_inteira(texto, "Eil-os", "Ei-los");
    substituir_palavra_inteira(texto, "eil-as", "ei-las");   substituir_palavra_inteira(texto, "Eil-as", "Ei-las");

    atualizar_sufixos_e_enclises(texto);

    // 8. Flexões irregulares e vocabulário histórico de 1911
    substituir_texto(texto, " he ", " é ");
    substituir_inicio_palavra(texto, "He ", "É ");
    substituir_texto(texto, " ha ", " há ");
    substituir_inicio_palavra(texto, "hum ", "um ");
    substituir_inicio_palavra(texto, "huma ", "uma ");
    substituir_inicio_palavra(texto, "huns ", "uns ");
    substituir_inicio_palavra(texto, "humas ", "umas ");
    substituir_inicio_palavra(texto, "hontem", "ontem");
    substituir_inicio_palavra(texto, "Hontem", "Ontem");
    substituir_inicio_palavra(texto, "hombro", "ombro");
    substituir_inicio_palavra(texto, "hombreira", "ombreira");
    substituir_inicio_palavra(texto, "humidade", "umidade");
    substituir_inicio_palavra(texto, "humedecem", "umedecem");
    substituir_inicio_palavra(texto, "vehemen", "veemen");
    substituir_inicio_palavra(texto, "cohorte", "coorte");

    substituir_inicio_palavra(texto, "creou", "criou");       substituir_inicio_palavra(texto, "Creou", "Criou");
    substituir_inicio_palavra(texto, "crear", "criar");       substituir_inicio_palavra(texto, "creara", "criara");
    substituir_inicio_palavra(texto, "creará", "criará");     substituir_inicio_palavra(texto, "crearam", "criaram");
    substituir_inicio_palavra(texto, "crearão", "criarão");   substituir_inicio_palavra(texto, "creaste", "criaste");
    substituir_inicio_palavra(texto, "creado", "criado");     substituir_inicio_palavra(texto, "creada", "criada");
    substituir_inicio_palavra(texto, "Creador", "Criador");   substituir_inicio_palavra(texto, "creação", "criação");
    substituir_inicio_palavra(texto, "creatura", "criatura"); substituir_inicio_palavra(texto, "creança", "criança");
    substituir_inicio_palavra(texto, "creancinha", "criancinha");

    substituir_inicio_palavra(texto, "veiu", "veio");         substituir_inicio_palavra(texto, "Veiu", "Veio");
    substituir_inicio_palavra(texto, "quiz", "quis");
    substituir_inicio_palavra(texto, "poude", "pôde");
    substituir_inicio_palavra(texto, "podera", "pudera");     substituir_inicio_palavra(texto, "poderam", "puderam");
    substituir_inicio_palavra(texto, "podesse", "pudesse");   substituir_inicio_palavra(texto, "podessem", "pudessem");
    substituir_inicio_palavra(texto, "podeste", "pudeste");   substituir_inicio_palavra(texto, "podestes", "pudestes");
    substituir_inicio_palavra(texto, "puz", "pus");           substituir_inicio_palavra(texto, "Puz", "Pus");
    substituir_inicio_palavra(texto, "pozer", "puser");       substituir_inicio_palavra(texto, "pozemos", "pusemos");
    substituir_inicio_palavra(texto, "pozesse", "pusesse");   substituir_inicio_palavra(texto, "pozeste", "puseste");
    substituir_inicio_palavra(texto, "Pozeste", "Puseste");   substituir_inicio_palavra(texto, "pozestes", "pusestes");
    substituir_texto(texto, " poz ", " pôs ");                substituir_texto(texto, " poz,", " pôs,");
    substituir_texto(texto, " poz.", " pôs.");                substituir_texto(texto, " poz;", " pôs;");
    substituir_inicio_palavra(texto, "Poz ", "Pôs ");         substituir_inicio_palavra(texto, "pôz", "pôs");
    substituir_inicio_palavra(texto, "compoz", "compôs");     substituir_inicio_palavra(texto, "depoz", "depôs");
    substituir_inicio_palavra(texto, "Depoz", "Depôs");       substituir_inicio_palavra(texto, "dispoz", "dispôs");
    substituir_inicio_palavra(texto, "expoz", "expôs");       substituir_inicio_palavra(texto, "impoz", "impôs");
    substituir_inicio_palavra(texto, "interpoz", "interpôs"); substituir_inicio_palavra(texto, "oppoz", "opôs");
    substituir_inicio_palavra(texto, "propoz", "propôs");     substituir_inicio_palavra(texto, "Propoz", "Propôs");
    substituir_inicio_palavra(texto, "propuz", "propus");     substituir_inicio_palavra(texto, "Propuz", "Propus");

    substituir_inicio_palavra(texto, "sahi", "saí");          substituir_inicio_palavra(texto, "Sahi", "Saí");
    substituir_inicio_palavra(texto, "sahia", "saía");        substituir_inicio_palavra(texto, "sahis", "saís");
    substituir_inicio_palavra(texto, "cahi", "caí");          substituir_inicio_palavra(texto, "Cahi", "Caí");
    substituir_inicio_palavra(texto, "cahia", "caía");
    substituir_inicio_palavra(texto, "trahi", "traí");        substituir_inicio_palavra(texto, "trahir", "trair");
    substituir_inicio_palavra(texto, "distrahi", "distraí");
    substituir_inicio_palavra(texto, "trahe", "trai");

    substituir_inicio_palavra(texto, "bemaventurad", "bem-aventurad");
    substituir_inicio_palavra(texto, "Bemaventurad", "Bem-aventurad");
    substituir_inicio_palavra(texto, "bemaventuranç", "bem-aventuranç");
    substituir_inicio_palavra(texto, "Bemaventuranç", "Bem-aventuranç");
    substituir_inicio_palavra(texto, "Bem-Aventurad", "Bem-aventurad");
    substituir_inicio_palavra(texto, "Bem-Aventuranç", "Bem-aventuranç");

    /* Só a palavra "aza(s)"; antes estragava nomes: Azarias -> Asarias */
    substituir_palavra_inteira(texto, "aza", "asa");          substituir_palavra_inteira(texto, "azas", "asas");
    substituir_palavra_inteira(texto, "Azas", "Asas");
    substituir_inicio_palavra(texto, "vasia", "vazia");       substituir_inicio_palavra(texto, "vasio", "vazio");
    substituir_inicio_palavra(texto, "abraza", "abrasa");     substituir_inicio_palavra(texto, "abraze", "abrase");
    substituir_inicio_palavra(texto, "abrazou", "abrasou");   substituir_inicio_palavra(texto, "arraza", "arrasa");
    substituir_inicio_palavra(texto, "atraz", "atrás");       substituir_inicio_palavra(texto, "detraz", "detrás");
    substituir_inicio_palavra(texto, "apoz", "após");         substituir_inicio_palavra(texto, "Apoz", "Após");
    substituir_inicio_palavra(texto, "defeza", "defesa");     substituir_inicio_palavra(texto, "despeza", "despesa");
    substituir_inicio_palavra(texto, "princeza", "princesa"); substituir_inicio_palavra(texto, "Princeza", "Princesa");
    substituir_inicio_palavra(texto, "turqueza", "turquesa");
    substituir_inicio_palavra(texto, "dezeseis", "dezesseis");substituir_inicio_palavra(texto, "dezesete", "dezessete");
    substituir_inicio_palavra(texto, "enteza", "entesa");     substituir_inicio_palavra(texto, "pezo", "peso");
    substituir_inicio_palavra(texto, "Pezo", "Peso");         substituir_inicio_palavra(texto, "peza", "pesa");
    substituir_inicio_palavra(texto, "apezar", "apesar");     substituir_inicio_palavra(texto, "piza", "pisa");
    substituir_inicio_palavra(texto, "pizei", "pisei");       substituir_inicio_palavra(texto, "pizem", "pisem");
    substituir_inicio_palavra(texto, "pizou", "pisou");       substituir_inicio_palavra(texto, "pesquiza", "pesquisa");
    substituir_inicio_palavra(texto, "visinh", "vizinh");
    substituir_inicio_palavra(texto, "organisad", "organizad");
    substituir_inicio_palavra(texto, "atemoris", "atemoriz");
    substituir_inicio_palavra(texto, "aterroris", "aterroriz");
    substituir_inicio_palavra(texto, "cauteris", "cauteriz");
    substituir_inicio_palavra(texto, "encoleris", "encoleriz");
    substituir_inicio_palavra(texto, "penalis", "penaliz");
    substituir_inicio_palavra(texto, "realis", "realiz");
    substituir_inicio_palavra(texto, "paralys", "paralis");
    substituir_inicio_palavra(texto, "paralyt", "paralít");
    substituir_inicio_palavra(texto, "alcans", "alcanç");     substituir_inicio_palavra(texto, "Alcans", "Alcanç");
    substituir_inicio_palavra(texto, "cança", "cansa");       substituir_inicio_palavra(texto, "Cança", "Cansa");
    substituir_inicio_palavra(texto, "cance", "canse");       substituir_inicio_palavra(texto, "cançou", "cansou");
    substituir_inicio_palavra(texto, "descanç", "descans");   substituir_inicio_palavra(texto, "Descanç", "Descans");
    substituir_inicio_palavra(texto, "descanc", "descans");
    substituir_inicio_palavra(texto, "arremeç", "arremess");
    substituir_inicio_palavra(texto, "soceg", "sosseg");
    substituir_inicio_palavra(texto, "resuscit", "ressuscit");substituir_inicio_palavra(texto, "Resuscit", "Ressuscit");
    substituir_inicio_palavra(texto, "resurreição", "ressurreição");
    substituir_inicio_palavra(texto, "sanguesuga", "sanguessuga");
    substituir_inicio_palavra(texto, "outrosim", "outrossim");substituir_inicio_palavra(texto, "Outrosim", "Outrossim");

    substituir_inicio_palavra(texto, "adeante", "adiante");   substituir_inicio_palavra(texto, "deante", "diante");
    substituir_inicio_palavra(texto, "edade", "idade");       substituir_inicio_palavra(texto, "edosos", "idosos");
    substituir_inicio_palavra(texto, "egreja", "igreja");
    substituir_inicio_palavra(texto, "egual", "igual");       substituir_inicio_palavra(texto, "Egual", "Igual");
    substituir_inicio_palavra(texto, "eguais", "iguais");     substituir_inicio_palavra(texto, "desegua", "desigua");
    substituir_inicio_palavra(texto, "emquanto", "enquanto"); substituir_inicio_palavra(texto, "Emquanto", "Enquanto");
    substituir_inicio_palavra(texto, "comtanto", "contanto");
    substituir_inicio_palavra(texto, "comtudo", "contudo");   substituir_inicio_palavra(texto, "Comtudo", "Contudo");
    substituir_inicio_palavra(texto, "commigo", "comigo");    substituir_inicio_palavra(texto, "comnosco", "conosco");
    substituir_inicio_palavra(texto, "comsigo", "consigo");   substituir_inicio_palavra(texto, "comtigo", "contigo");
    substituir_inicio_palavra(texto, "Comtigo", "Contigo");   substituir_inicio_palavra(texto, "comvosco", "convosco");
    substituir_inicio_palavra(texto, "bemdiz", "bendiz");     substituir_inicio_palavra(texto, "Bemdiz", "Bendiz");
    substituir_inicio_palavra(texto, "bemdit", "bendit");     substituir_inicio_palavra(texto, "Bemdit", "Bendit");
    substituir_inicio_palavra(texto, "bemdiss", "bendiss");   substituir_inicio_palavra(texto, "bemdig", "bendig");
    substituir_inicio_palavra(texto, "bemdir", "bendir");
    substituir_inicio_palavra(texto, "circum", "circun");     substituir_inicio_palavra(texto, "Circum", "Circun");
    substituir_inicio_palavra(texto, "cincoenta", "cinquenta");substituir_inicio_palavra(texto, "Cincoenta", "Cinquenta");
    substituir_inicio_palavra(texto, "logar", "lugar");       substituir_inicio_palavra(texto, "herva", "erva");
    substituir_inicio_palavra(texto, "Herva", "Erva");        substituir_inicio_palavra(texto, "similh", "semelh");
    substituir_inicio_palavra(texto, "Similh", "Semelh");     substituir_inicio_palavra(texto, "quasi", "quase");
    substituir_inicio_palavra(texto, "Quasi", "Quase");       substituir_inicio_palavra(texto, "peior", "pior");
    substituir_inicio_palavra(texto, "engul", "engol");       substituir_inicio_palavra(texto, "Engul", "Engol");
    substituir_inicio_palavra(texto, "cubriram", "cobriram"); substituir_inicio_palavra(texto, "cubriu", "cobriu");
    substituir_inicio_palavra(texto, "inimisade", "inimizade");
    substituir_inicio_palavra(texto, "magestade", "majestade");substituir_inicio_palavra(texto, "Magestade", "Majestade");
    substituir_inicio_palavra(texto, "mangedoura", "manjedoura");
    substituir_inicio_palavra(texto, "engeita", "enjeita");   substituir_inicio_palavra(texto, "hereje", "herege");
    substituir_inicio_palavra(texto, "lisonge", "lisonje");   substituir_inicio_palavra(texto, "bozin", "buzin");
    /* Só "tribu(s)"; antes estragava tributo, tribuno, tribunal */
    substituir_palavra_inteira(texto, "tribu", "tribo");      substituir_palavra_inteira(texto, "tribus", "tribos");
    substituir_inicio_palavra(texto, "thesoiro", "tesouro");
    substituir_inicio_palavra(texto, "taboado", "tabuado");   substituir_inicio_palavra(texto, "taboinha", "tabuinha");
    substituir_inicio_palavra(texto, "taboa", "tábua");       substituir_inicio_palavra(texto, "taboas", "tábuas");
    substituir_inicio_palavra(texto, "sobaco", "sovaco");     substituir_inicio_palavra(texto, "gloton", "gluton");
    substituir_inicio_palavra(texto, "dextra", "destra");     substituir_inicio_palavra(texto, "Dextra", "Destra");
    substituir_inicio_palavra(texto, "euro-aquilão", "euroaquilão");
    substituir_inicio_palavra(texto, "comprehend", "compreend");
    substituir_inicio_palavra(texto, "reprehens", "repreens");
    substituir_inicio_palavra(texto, "reprehend", "repreend");substituir_inicio_palavra(texto, "Reprehend", "Repreend");
    substituir_inicio_palavra(texto, "surprehend", "surpreend");substituir_inicio_palavra(texto, "Surprehend", "Surpreend");
    substituir_inicio_palavra(texto, "emprehend", "empreend");
    substituir_inicio_palavra(texto, "incomprehens", "incompreens");
    substituir_inicio_palavra(texto, "ideia", "idea");        substituir_inicio_palavra(texto, "passeia", "passea");
    substituir_inicio_palavra(texto, "receia", "recea");      substituir_inicio_palavra(texto, "rodeia", "rodea");
    substituir_inicio_palavra(texto, "recreia", "recrea");    substituir_inicio_palavra(texto, "refreia", "refrea");
    substituir_inicio_palavra(texto, "ceiar", "cear");

    // 9. Acentuação moderna (remoção de acentos antigos e inclusão dos atuais)
    substituir_inicio_palavra(texto, "crêem", "creem");       substituir_inicio_palavra(texto, "dêem", "deem");
    substituir_inicio_palavra(texto, "Dêem", "Deem");         substituir_inicio_palavra(texto, "lêem", "leem");
    substituir_inicio_palavra(texto, "vêem", "veem");         substituir_inicio_palavra(texto, "Vêem", "Veem");
    substituir_inicio_palavra(texto, "vôo", "voo");           substituir_inicio_palavra(texto, "vôa", "voa");
    substituir_inicio_palavra(texto, "vôem", "voem");         substituir_inicio_palavra(texto, "abençô", "abenço");
    substituir_inicio_palavra(texto, "Abençô", "Abenço");     substituir_inicio_palavra(texto, "abençõe", "abençoe");
    substituir_inicio_palavra(texto, "apregô", "aprego");     substituir_inicio_palavra(texto, "entôa", "entoa");
    substituir_inicio_palavra(texto, "perdô", "perdo");       substituir_inicio_palavra(texto, "Perdô", "Perdo");
    substituir_inicio_palavra(texto, "magõe", "magoe");       substituir_inicio_palavra(texto, "povôem", "povoem");
    substituir_inicio_palavra(texto, "assembléa", "assembleia");
    substituir_inicio_palavra(texto, "balêa", "baleia");      substituir_inicio_palavra(texto, "pavêa", "paveia");
    substituir_inicio_palavra(texto, "têa", "teia");          substituir_inicio_palavra(texto, "côr", "cor");
    substituir_inicio_palavra(texto, "cór", "cor");           substituir_inicio_palavra(texto, "dôr", "dor");
    substituir_inicio_palavra(texto, "Dôr", "Dor");           substituir_inicio_palavra(texto, "flôr", "flor");
    substituir_inicio_palavra(texto, "fôr", "for");           substituir_inicio_palavra(texto, "fóra", "fora");
    substituir_inicio_palavra(texto, "Fóra", "Fora");         substituir_inicio_palavra(texto, "fôra", "fora");
    substituir_inicio_palavra(texto, "Fôra", "Fora");         substituir_inicio_palavra(texto, "afóra", "afora");
    substituir_inicio_palavra(texto, "Afóra", "Afora");       substituir_inicio_palavra(texto, "fórma", "forma");
    substituir_inicio_palavra(texto, "fórmo", "formo");       substituir_inicio_palavra(texto, "sómente", "somente");
    substituir_inicio_palavra(texto, "Sómente", "Somente");   substituir_inicio_palavra(texto, "sósinho", "sozinho");
    substituir_inicio_palavra(texto, "páo", "pau");           substituir_inicio_palavra(texto, "páu", "pau");
    substituir_inicio_palavra(texto, "máu", "mau");           substituir_inicio_palavra(texto, "váo", "vau");
    substituir_inicio_palavra(texto, "náo", "nau");           substituir_inicio_palavra(texto, "náu", "nau");
    substituir_inicio_palavra(texto, "degráu", "degrau");     substituir_inicio_palavra(texto, "póde", "pode");
    substituir_inicio_palavra(texto, "pódes", "podes");       substituir_inicio_palavra(texto, "préga", "prega");
    substituir_inicio_palavra(texto, "prég", "preg");         substituir_inicio_palavra(texto, "Prég", "Preg");
    substituir_inicio_palavra(texto, "crêr", "crer");         substituir_inicio_palavra(texto, "lêr", "ler");
    substituir_inicio_palavra(texto, "vêr", "ver");           substituir_inicio_palavra(texto, "crêde", "crede");
    substituir_inicio_palavra(texto, "Crêde", "Crede");       substituir_inicio_palavra(texto, "crêdes", "credes");
    substituir_inicio_palavra(texto, "Crêdes", "Credes");     substituir_inicio_palavra(texto, "crêmos", "cremos");
    substituir_inicio_palavra(texto, "crêste", "creste");     substituir_inicio_palavra(texto, "lêde", "lede");
    substituir_inicio_palavra(texto, "lêstes", "lestes");     substituir_inicio_palavra(texto, "vêde", "vede");
    substituir_inicio_palavra(texto, "Vêde", "Vede");         substituir_inicio_palavra(texto, "vêdes", "vedes");
    substituir_inicio_palavra(texto, "Vêdes", "Vedes");       substituir_inicio_palavra(texto, "dér", "der");
    substituir_inicio_palavra(texto, "dés", "des");           substituir_inicio_palavra(texto, "désse", "desse");
    substituir_inicio_palavra(texto, "déste", "deste");       substituir_inicio_palavra(texto, "Déste", "Deste");
    substituir_inicio_palavra(texto, "démos", "demos");       substituir_inicio_palavra(texto, "podér", "poder");
    substituir_inicio_palavra(texto, "podémos", "podemos");   substituir_inicio_palavra(texto, "têem", "têm");
    substituir_inicio_palavra(texto, "teem", "têm");          substituir_inicio_palavra(texto, "Teem", "Têm");
    substituir_inicio_palavra(texto, "detêem", "detêm");      substituir_inicio_palavra(texto, "deteem", "detêm");
    substituir_inicio_palavra(texto, "mantêem", "mantêm");    substituir_inicio_palavra(texto, "manteem", "mantêm");
    substituir_inicio_palavra(texto, "convêem", "convêm");    substituir_inicio_palavra(texto, "conveem", "convêm");
    substituir_inicio_palavra(texto, "sobrevêem", "sobrevêm");substituir_inicio_palavra(texto, "sobreveem", "sobrevêm");
    substituir_inicio_palavra(texto, "sêde", "sede");         substituir_inicio_palavra(texto, "Sêde", "Sede");
    substituir_inicio_palavra(texto, "convem", "convém");     substituir_inicio_palavra(texto, "Convem", "Convém");
    substituir_inicio_palavra(texto, "detem", "detém");       substituir_inicio_palavra(texto, "mantem", "mantém");
    substituir_inicio_palavra(texto, "sobrevem", "sobrevém");
    substituir_inicio_palavra(texto, "véla", "vela");         substituir_inicio_palavra(texto, "vélas", "velas");
    substituir_inicio_palavra(texto, "pátriarca", "patriarca");
    substituir_inicio_palavra(texto, "fábricador", "fabricador");
    substituir_texto(texto, "aos pães e às mães", "aos pais e às mães");
    /* Só a palavra "ahi" (= aí); antes estragava nomes: Ahimaas -> Aímaas */
    substituir_palavra_inteira(texto, "ahi", "aí");           substituir_palavra_inteira(texto, "Ahi", "Aí");
    substituir_inicio_palavra(texto, "alli", "ali");          substituir_inicio_palavra(texto, "nú", "nu");
    substituir_inicio_palavra(texto, "núa", "nua");           substituir_inicio_palavra(texto, "nús", "nus");
    /* Só a palavra inteira; antes "homens" virava "homems" (1158 vezes) */
    substituir_palavra_inteira(texto, "joven", "jovem");      substituir_palavra_inteira(texto, "homen", "homem");
    substituir_inicio_palavra(texto, "algums", "alguns");     substituir_palavra_inteira(texto, "mez", "mês");
    substituir_inicio_palavra(texto, "mezes", "meses");       substituir_inicio_palavra(texto, "tres", "três");
    substituir_inicio_palavra(texto, "Tres", "Três");         substituir_inicio_palavra(texto, "paiz", "país");
    substituir_inicio_palavra(texto, "paizes", "países");     substituir_inicio_palavra(texto, "Satanaz", "Satanás");
    substituir_inicio_palavra(texto, "anneis", "anéis");      substituir_inicio_palavra(texto, "anzoes", "anzóis");
    substituir_inicio_palavra(texto, "lençoes", "lençóis");   substituir_inicio_palavra(texto, "crueis", "cruéis");
    substituir_inicio_palavra(texto, "infieis", "infiéis");   substituir_inicio_palavra(texto, "fieis", "fiéis");
    substituir_inicio_palavra(texto, "chapeus", "chapéus");   substituir_inicio_palavra(texto, "arpéos", "arpéus");
    substituir_inicio_palavra(texto, "parabens", "parabéns"); substituir_inicio_palavra(texto, "refens", "reféns");
    substituir_inicio_palavra(texto, "armazens", "armazéns");

    // Vocabulário com acentuação moderna
    substituir_inicio_palavra(texto, "principio", "princípio");   substituir_inicio_palavra(texto, "Principio", "Princípio");
    substituir_inicio_palavra(texto, "Espirito", "Espírito");     substituir_inicio_palavra(texto, "espirito", "espírito");
    substituir_inicio_palavra(texto, "agua", "água");             substituir_inicio_palavra(texto, "Agua", "Água");
    substituir_inicio_palavra(texto, "arvore", "árvore");         substituir_inicio_palavra(texto, "Arvore", "Árvore");
    substituir_inicio_palavra(texto, "especie", "espécie");       substituir_inicio_palavra(texto, "reptil", "réptil");
    substituir_inicio_palavra(texto, "reptis", "répteis");        substituir_inicio_palavra(texto, "femea", "fêmea");
    substituir_inicio_palavra(texto, "gemeos", "gêmeos");         substituir_inicio_palavra(texto, "frutifera", "frutífera");
    substituir_inicio_palavra(texto, "oleo", "óleo");             substituir_inicio_palavra(texto, "calix", "cálice");
    substituir_inicio_palavra(texto, "gravida", "grávida");       substituir_inicio_palavra(texto, "gravido", "grávido");
    substituir_inicio_palavra(texto, "unigenito", "unigênito");   substituir_inicio_palavra(texto, "Unigenito", "Unigênito");
    substituir_inicio_palavra(texto, "folego", "fôlego");         substituir_inicio_palavra(texto, "Folego", "Fôlego");
    substituir_inicio_palavra(texto, "bdelio", "bdélio");         substituir_inicio_palavra(texto, "carcere", "cárcere");
    substituir_inicio_palavra(texto, "jubilo", "júbilo");         substituir_inicio_palavra(texto, "Jubilo", "Júbilo");
    substituir_inicio_palavra(texto, "licito", "lícito");         substituir_inicio_palavra(texto, "ilicito", "ilícito");
    substituir_inicio_palavra(texto, "unanime", "unânime");       substituir_inicio_palavra(texto, "Unanime", "Unânime");
    substituir_inicio_palavra(texto, "incomod", "incômod");       substituir_inicio_palavra(texto, "ancora", "âncora");
    substituir_inicio_palavra(texto, "imovel", "imóvel");         substituir_inicio_palavra(texto, "imoveis", "imóveis");
    substituir_inicio_palavra(texto, "mutua", "mútua");           substituir_inicio_palavra(texto, "mutuo", "mútuo");
    substituir_inicio_palavra(texto, "quadrupede", "quadrúpede"); substituir_inicio_palavra(texto, "imundicia", "imundícia");
    substituir_inicio_palavra(texto, "malicia", "malícia");       substituir_inicio_palavra(texto, "Malicia", "Malícia");
    substituir_inicio_palavra(texto, "seculo", "século");         substituir_inicio_palavra(texto, "Seculo", "Século");
    substituir_inicio_palavra(texto, "incredul", "incrédul");     substituir_inicio_palavra(texto, "Incredul", "Incrédul");
    substituir_inicio_palavra(texto, "proselit", "prosélit");     substituir_inicio_palavra(texto, "arabes", "árabes");
    substituir_inicio_palavra(texto, "arido", "árido");           substituir_inicio_palavra(texto, "arida", "árida");
    substituir_inicio_palavra(texto, "Amen", "Amém");             substituir_inicio_palavra(texto, "amen", "amém");
    substituir_inicio_palavra(texto, "alguem", "alguém");         substituir_inicio_palavra(texto, "Alguem", "Alguém");
    substituir_inicio_palavra(texto, "ninguem", "ninguém");       substituir_inicio_palavra(texto, "Ninguem", "Ninguém");
    substituir_inicio_palavra(texto, "tambem", "também");         substituir_inicio_palavra(texto, "Tambem", "Também");
    substituir_inicio_palavra(texto, "decima", "décima");         substituir_inicio_palavra(texto, "decimo", "décimo");
    substituir_inicio_palavra(texto, "discipulo", "discípulo");   substituir_inicio_palavra(texto, "Discipulo", "Discípulo");
    substituir_inicio_palavra(texto, "discipula", "discípula");
    substituir_inicio_palavra(texto, "judeo", "judeu");           substituir_inicio_palavra(texto, "Judeo", "Judeu");
    substituir_inicio_palavra(texto, "galileo", "galileu");       substituir_inicio_palavra(texto, "Galileo", "Galileu");
    substituir_inicio_palavra(texto, "fariseo", "fariseu");       substituir_inicio_palavra(texto, "Fariseo", "Fariseu");
    substituir_inicio_palavra(texto, "sadduceo", "saduceu");
    substituir_inicio_palavra(texto, "gloria", "glória");         substituir_inicio_palavra(texto, "Gloria", "Glória");
    substituir_inicio_palavra(texto, "misericordia", "misericórdia");substituir_inicio_palavra(texto, "Misericordia", "Misericórdia");
    substituir_inicio_palavra(texto, "juizo", "juízo");           substituir_inicio_palavra(texto, "paraiso", "paraíso");
    substituir_inicio_palavra(texto, "Paraiso", "Paraíso");       substituir_inicio_palavra(texto, "saude", "saúde");
    substituir_inicio_palavra(texto, "saudes", "saúdes");         substituir_inicio_palavra(texto, "saudo", "saúdo");
    substituir_inicio_palavra(texto, "saudam", "saúdam");         substituir_inicio_palavra(texto, "Saudam", "Saúdam");
    substituir_inicio_palavra(texto, "viuva", "viúva");           substituir_inicio_palavra(texto, "Viuva", "Viúva");
    substituir_inicio_palavra(texto, "ruina", "ruína");           substituir_inicio_palavra(texto, "raizes", "raízes");
    substituir_inicio_palavra(texto, "faisca", "faísca");         substituir_inicio_palavra(texto, "miuda", "miúda");
    substituir_inicio_palavra(texto, "miudo", "miúdo");           substituir_inicio_palavra(texto, "moido", "moído");
    substituir_inicio_palavra(texto, "roida", "roída");           substituir_inicio_palavra(texto, "saida", "saída");
    substituir_inicio_palavra(texto, "saido", "saído");           substituir_inicio_palavra(texto, "caida", "caída");
    substituir_inicio_palavra(texto, "caido", "caído");           substituir_inicio_palavra(texto, "destruida", "destruída");
    substituir_inicio_palavra(texto, "destruido", "destruído");   substituir_inicio_palavra(texto, "possuida", "possuída");
    substituir_inicio_palavra(texto, "possuido", "possuído");     substituir_inicio_palavra(texto, "restituida", "restituída");
    substituir_inicio_palavra(texto, "restituido", "restituído"); substituir_inicio_palavra(texto, "instruida", "instruída");
    substituir_inicio_palavra(texto, "instruido", "instruído");   substituir_inicio_palavra(texto, "construido", "construído");
    substituir_inicio_palavra(texto, "instituido", "instituído"); substituir_inicio_palavra(texto, "constituido", "constituído");
    substituir_inicio_palavra(texto, "concluido", "concluído");   substituir_inicio_palavra(texto, "excluido", "excluído");
    substituir_inicio_palavra(texto, "diminuido", "diminuído");   substituir_inicio_palavra(texto, "attribue", "atribui");
    substituir_inicio_palavra(texto, "constitue", "constitui");   substituir_inicio_palavra(texto, "diminue", "diminui");
    substituir_inicio_palavra(texto, "exclue", "exclui");         substituir_inicio_palavra(texto, "instrue", "instrui");
    substituir_inicio_palavra(texto, "possue", "possui");         substituir_inicio_palavra(texto, "restitue", "restitui");
    substituir_inicio_palavra(texto, "retribue", "retribui");     substituir_inicio_palavra(texto, "destroe", "destrói");
    substituir_inicio_palavra(texto, "Destroe", "Destrói");       substituir_inicio_palavra(texto, "obstroe", "obstrói");
    substituir_inicio_palavra(texto, "orfão", "órfão");           substituir_inicio_palavra(texto, "orphão", "órfão");
    substituir_inicio_palavra(texto, "Orphãos", "Órfãos");       substituir_inicio_palavra(texto, "orgão", "órgão");
    substituir_inicio_palavra(texto, "apostolo", "apóstolo");     substituir_inicio_palavra(texto, "diacono", "diácono");
    substituir_inicio_palavra(texto, "exercito", "exército");     substituir_inicio_palavra(texto, "Exercito", "Exército");
    substituir_inicio_palavra(texto, "sacrificio", "sacrifício"); substituir_inicio_palavra(texto, "Sacrificio", "Sacrifício");
    substituir_inicio_palavra(texto, "santuario", "santuário");   substituir_inicio_palavra(texto, "Santuario", "Santuário");
    substituir_inicio_palavra(texto, "tabernaculo", "tabernáculo");
    substituir_inicio_palavra(texto, "sinhedrio", "sinédrio");
    substituir_inicio_palavra(texto, "adulterio", "adultério");   substituir_inicio_palavra(texto, "Adulterio", "Adultério");
    substituir_inicio_palavra(texto, "homicidio", "homicídio");   substituir_inicio_palavra(texto, "fornicario", "fornicário");
    substituir_inicio_palavra(texto, "idolo", "ídolo");           substituir_inicio_palavra(texto, "idolatras", "idólatras");
    substituir_inicio_palavra(texto, "demonio", "demônio");       substituir_inicio_palavra(texto, "misterio", "mistério");
    substituir_inicio_palavra(texto, "Misterio", "Mistério");     substituir_inicio_palavra(texto, "ministerio", "ministério");
    substituir_inicio_palavra(texto, "epistola", "epístola");     substituir_inicio_palavra(texto, "cantico", "cântico");
    substituir_inicio_palavra(texto, "Cantico", "Cântico");       substituir_inicio_palavra(texto, "proverbio", "provérbio");
    substituir_inicio_palavra(texto, "Proverbio", "Provérbio");   substituir_inicio_palavra(texto, "sabio", "sábio");
    substituir_inicio_palavra(texto, "nescio", "néscio");         substituir_inicio_palavra(texto, "Nescio", "Néscio");
    substituir_inicio_palavra(texto, "impio", "ímpio");           substituir_inicio_palavra(texto, "iniquo", "iníquo");
    substituir_inicio_palavra(texto, "principe", "príncipe");     substituir_inicio_palavra(texto, "Principe", "Príncipe");
    substituir_inicio_palavra(texto, "palacio", "palácio");       substituir_inicio_palavra(texto, "edificio", "edifício");
    substituir_inicio_palavra(texto, "atrio", "átrio");           substituir_inicio_palavra(texto, "vestibulo", "vestíbulo");
    substituir_inicio_palavra(texto, "pinaculo", "pináculo");     substituir_inicio_palavra(texto, "portico", "pórtico");
    substituir_inicio_palavra(texto, "marmore", "mármore");       substituir_inicio_palavra(texto, "fabrica", "fábrica");
    substituir_inicio_palavra(texto, "lampada", "lâmpada");       substituir_inicio_palavra(texto, "perola", "pérola");
    substituir_inicio_palavra(texto, "covados", "côvados");       substituir_inicio_palavra(texto, "tunica", "túnica");
    substituir_inicio_palavra(texto, "sandalo", "sândalo");       substituir_inicio_palavra(texto, "ambar", "âmbar");
    substituir_inicio_palavra(texto, "antimonio", "antimônio");   substituir_inicio_palavra(texto, "onix", "ônix");
    substituir_inicio_palavra(texto, "Onix", "Ônix");             substituir_inicio_palavra(texto, "topazio", "topázio");
    substituir_inicio_palavra(texto, "sardio", "sárdio");         substituir_inicio_palavra(texto, "sardonia", "sardônia");
    substituir_inicio_palavra(texto, "sardonica", "sardônica");   substituir_inicio_palavra(texto, "crisolito", "crisólito");
    substituir_inicio_palavra(texto, "crisopraso", "crisópraso"); substituir_inicio_palavra(texto, "Omega", "Ômega");
    substituir_inicio_palavra(texto, "aguia", "águia");           substituir_inicio_palavra(texto, "passaro", "pássaro");
    substituir_inicio_palavra(texto, "vibora", "víbora");         substituir_inicio_palavra(texto, "aspide", "áspide");
    substituir_inicio_palavra(texto, "bufalo", "búfalo");         substituir_inicio_palavra(texto, "antilope", "antílope");
    substituir_inicio_palavra(texto, "dromedario", "dromedário"); substituir_inicio_palavra(texto, "unicornio", "unicórnio");
    substituir_inicio_palavra(texto, "lirio", "lírio");           substituir_inicio_palavra(texto, "aloes", "aloés");
    substituir_inicio_palavra(texto, "alamo", "álamo");           substituir_inicio_palavra(texto, "amendoas", "amêndoas");
    substituir_inicio_palavra(texto, "sicomoro", "sicômoro");     substituir_inicio_palavra(texto, "terebintho", "terebinto");
    substituir_inicio_palavra(texto, "hipocrita", "hipócrita");   substituir_inicio_palavra(texto, "Hipocrita", "Hipócrita");
    substituir_inicio_palavra(texto, "blasfemia", "blasfêmia");   substituir_inicio_palavra(texto, "perfidia", "perfídia");
    substituir_inicio_palavra(texto, "perfido", "pérfido");       substituir_inicio_palavra(texto, "barbaro", "bárbaro");
    substituir_inicio_palavra(texto, "bebado", "bêbado");         substituir_inicio_palavra(texto, "bebedo", "bêbedo");
    substituir_inicio_palavra(texto, "ebrios", "ébrios");         substituir_inicio_palavra(texto, "lunatico", "lunático");
    substituir_inicio_palavra(texto, "hidropico", "hidrópico");   substituir_inicio_palavra(texto, "pustula", "pústula");
    substituir_inicio_palavra(texto, "cadaver", "cadáver");       substituir_inicio_palavra(texto, "feretro", "féretro");
    substituir_inicio_palavra(texto, "relogio", "relógio");       substituir_inicio_palavra(texto, "salario", "salário");
    substituir_inicio_palavra(texto, "denario", "denário");       substituir_inicio_palavra(texto, "drachma", "dracma");
    substituir_inicio_palavra(texto, "didrachma", "didracma");    substituir_inicio_palavra(texto, "obolos", "óbolos");
    substituir_inicio_palavra(texto, "státer", "estáter");        substituir_inicio_palavra(texto, "adversario", "adversário");
    substituir_inicio_palavra(texto, "mercenario", "mercenário"); substituir_inicio_palavra(texto, "operario", "operário");
    substituir_inicio_palavra(texto, "boticario", "boticário");   substituir_inicio_palavra(texto, "secretario", "secretário");
    substituir_inicio_palavra(texto, "usurario", "usurário");     substituir_inicio_palavra(texto, "voluntario", "voluntário");
    substituir_inicio_palavra(texto, "tributario", "tributário"); substituir_inicio_palavra(texto, "hereditari", "hereditári");
    substituir_inicio_palavra(texto, "necessari", "necessári");   substituir_inicio_palavra(texto, "Necessari", "Necessári");
    substituir_inicio_palavra(texto, "ordinaria", "ordinária");   substituir_inicio_palavra(texto, "extraordinaria", "extraordinária");
    substituir_inicio_palavra(texto, "transitori", "transitóri"); substituir_inicio_palavra(texto, "momentanea", "momentânea");
    substituir_inicio_palavra(texto, "corporea", "corpórea");     substituir_inicio_palavra(texto, "idoneo", "idôneo");
    substituir_inicio_palavra(texto, "aspero", "áspero");         substituir_inicio_palavra(texto, "candido", "cândido");
    substituir_inicio_palavra(texto, "timido", "tímido");         substituir_inicio_palavra(texto, "sordido", "sórdido");
    substituir_inicio_palavra(texto, "sobrio", "sóbrio");         substituir_inicio_palavra(texto, "proprio", "próprio");
    substituir_inicio_palavra(texto, "propria", "própria");       substituir_inicio_palavra(texto, "proximo", "próximo");
    substituir_inicio_palavra(texto, "proxima", "próxima");       substituir_inicio_palavra(texto, "insipido", "insípido");
    substituir_inicio_palavra(texto, "ultimo", "último");         substituir_inicio_palavra(texto, "minimo", "mínimo");
    substituir_inicio_palavra(texto, "minimas", "mínimas");       substituir_inicio_palavra(texto, "intimo", "íntimo");
    substituir_inicio_palavra(texto, "continuo", "contínuo");     substituir_inicio_palavra(texto, "perpetuo", "perpétuo");
    substituir_inicio_palavra(texto, "contrario", "contrário");   substituir_inicio_palavra(texto, "vario", "vário");
    substituir_inicio_palavra(texto, "solitari", "solitári");     substituir_inicio_palavra(texto, "maritima", "marítima");
    substituir_inicio_palavra(texto, "domestico", "doméstico");   substituir_inicio_palavra(texto, "rustico", "rústico");
    substituir_inicio_palavra(texto, "magico", "mágico");         substituir_inicio_palavra(texto, "magnifico", "magnífico");
    substituir_inicio_palavra(texto, "pessimo", "péssimo");       substituir_inicio_palavra(texto, "atonito", "atônito");
    substituir_inicio_palavra(texto, "longanimo", "longânimo");   substituir_inicio_palavra(texto, "solicito", "solícito");
    substituir_inicio_palavra(texto, "temerario", "temerário");   substituir_inicio_palavra(texto, "propinquo", "propínquo");
    substituir_inicio_palavra(texto, "setima", "sétima");         substituir_inicio_palavra(texto, "setimo", "sétimo");
    substituir_inicio_palavra(texto, "undecim", "undécim");       substituir_inicio_palavra(texto, "duodecim", "duodécim");
    substituir_inicio_palavra(texto, "vigesim", "vigésim");       substituir_inicio_palavra(texto, "trigesim", "trigésim");
    substituir_inicio_palavra(texto, "quadragesim", "quadragésim");substituir_inicio_palavra(texto, "quinquagesim", "quinquagésim");
    substituir_inicio_palavra(texto, "lingua", "língua");         substituir_inicio_palavra(texto, "mingua", "míngua");
    substituir_inicio_palavra(texto, "argúe", "argui");           substituir_inicio_palavra(texto, "redargue", "redargui");
    substituir_inicio_palavra(texto, "beneficio", "benefício");   substituir_inicio_palavra(texto, "maleficio", "malefício");
    substituir_inicio_palavra(texto, "exercicio", "exercício");   substituir_inicio_palavra(texto, "officio", "ofício");
    substituir_inicio_palavra(texto, "desperdicio", "desperdício");substituir_inicio_palavra(texto, "precipicio", "precipício");
    substituir_inicio_palavra(texto, "prejuizo", "prejuízo");     substituir_inicio_palavra(texto, "prepucio", "prepúcio");
    substituir_inicio_palavra(texto, "negocio", "negócio");       substituir_inicio_palavra(texto, "sacerdocio", "sacerdócio");
    substituir_inicio_palavra(texto, "sacrilegio", "sacrilégio"); substituir_inicio_palavra(texto, "imperio", "império");
    substituir_inicio_palavra(texto, "dominio", "domínio");       substituir_inicio_palavra(texto, "testiculo", "testículo");
    substituir_inicio_palavra(texto, "musculo", "músculo");       substituir_inicio_palavra(texto, "musico", "músico");
    substituir_inicio_palavra(texto, "cimbalo", "címbalo");       substituir_inicio_palavra(texto, "salterio", "saltério");
    substituir_inicio_palavra(texto, "pulpito", "púlpito");       substituir_inicio_palavra(texto, "auditorio", "auditório");
    substituir_inicio_palavra(texto, "concilio", "concílio");     substituir_inicio_palavra(texto, "pretorio", "pretório");
    substituir_inicio_palavra(texto, "territorio", "território"); substituir_inicio_palavra(texto, "provincia", "província");
    substituir_inicio_palavra(texto, "planicie", "planície");     substituir_inicio_palavra(texto, "superficie", "superfície");
    substituir_inicio_palavra(texto, "vespera", "véspera");       substituir_inicio_palavra(texto, "vigilia", "vigília");
    substituir_inicio_palavra(texto, "memoria", "memória");       substituir_inicio_palavra(texto, "familia", "família");
    substituir_inicio_palavra(texto, "patria", "pátria");         substituir_inicio_palavra(texto, "materia", "matéria");
    substituir_inicio_palavra(texto, "miseria", "miséria");       substituir_inicio_palavra(texto, "lagrima", "lágrima");
    substituir_inicio_palavra(texto, "reliquia", "relíquia");     substituir_inicio_palavra(texto, "remedio", "remédio");
    substituir_inicio_palavra(texto, "refrigerio", "refrigério"); substituir_inicio_palavra(texto, "oprobrio", "opróbrio");
    substituir_inicio_palavra(texto, "vituperio", "vitupério");   substituir_inicio_palavra(texto, "escarnio", "escárnio");
    substituir_inicio_palavra(texto, "escarneo", "escárnio");     substituir_inicio_palavra(texto, "tedio", "tédio");
    substituir_inicio_palavra(texto, "odio", "ódio");             substituir_inicio_palavra(texto, "incendio", "incêndio");
    substituir_inicio_palavra(texto, "naufragio", "naufrágio");   substituir_inicio_palavra(texto, "prodigio", "prodígio");
    substituir_inicio_palavra(texto, "designio", "desígnio");     substituir_inicio_palavra(texto, "equilibrio", "equilíbrio");
    substituir_inicio_palavra(texto, "comercio", "comércio");     substituir_inicio_palavra(texto, "comodo", "cômodo");
    substituir_inicio_palavra(texto, "colera", "cólera");         substituir_inicio_palavra(texto, "colerico", "colérico");
    substituir_inicio_palavra(texto, "angulo", "ângulo");         substituir_inicio_palavra(texto, "animo", "ânimo");
    substituir_inicio_palavra(texto, "camara", "câmara");         substituir_inicio_palavra(texto, "cantaro", "cântaro");
    substituir_inicio_palavra(texto, "genero", "gênero");         substituir_inicio_palavra(texto, "craneo", "crânio");
    substituir_inicio_palavra(texto, "crepusculo", "crepúsculo"); substituir_inicio_palavra(texto, "espetaculo", "espetáculo");
    substituir_inicio_palavra(texto, "estadio", "estádio");       substituir_inicio_palavra(texto, "esteril", "estéril");
    substituir_inicio_palavra(texto, "facil", "fácil");           substituir_inicio_palavra(texto, "fertil", "fértil");
    substituir_inicio_palavra(texto, "fragil", "frágil");         substituir_inicio_palavra(texto, "habil", "hábil");
    substituir_inicio_palavra(texto, "util", "útil");             substituir_inicio_palavra(texto, "Util", "Útil");
    substituir_inicio_palavra(texto, "debil", "débil");           substituir_inicio_palavra(texto, "nivel", "nível");
    substituir_inicio_palavra(texto, "vacuo", "vácuo");           substituir_inicio_palavra(texto, "residuo", "resíduo");
    substituir_inicio_palavra(texto, "vomito", "vômito");         substituir_inicio_palavra(texto, "nadegas", "nádegas");
    substituir_inicio_palavra(texto, "palpebras", "pálpebras");   substituir_inicio_palavra(texto, "pateo", "pátio");
    substituir_inicio_palavra(texto, "alviçaras", "alvíssaras");  substituir_inicio_palavra(texto, "arruido", "arruído");
    substituir_inicio_palavra(texto, "arroido", "arruído");       substituir_inicio_palavra(texto, "vaevens", "vaivéns");
    substituir_inicio_palavra(texto, "vergonteas", "vergônteas"); substituir_inicio_palavra(texto, "violencia", "violência");
    substituir_inicio_palavra(texto, "Violencia", "Violência");   substituir_inicio_palavra(texto, "modestia", "modéstia");
    substituir_inicio_palavra(texto, "molestia", "moléstia");     substituir_inicio_palavra(texto, "estulticia", "estultícia");
    substituir_inicio_palavra(texto, "infamia", "infâmia");       substituir_inicio_palavra(texto, "concordia", "concórdia");
    substituir_inicio_palavra(texto, "primicia", "primícia");     substituir_inicio_palavra(texto, "primogenit", "primogênit");
    substituir_inicio_palavra(texto, "proposito", "propósito");   substituir_inicio_palavra(texto, "beneplacito", "beneplácito");
    substituir_inicio_palavra(texto, "emprestimo", "empréstimo"); substituir_inicio_palavra(texto, "artifice", "artífice");
    substituir_inicio_palavra(texto, "astrologo", "astrólogo");   substituir_inicio_palavra(texto, "dormitorio", "dormitório");
    substituir_inicio_palavra(texto, "incensario", "incensário"); substituir_inicio_palavra(texto, "luminaria", "luminária");
    substituir_inicio_palavra(texto, "propiciatorio", "propiciatório");
    substituir_inicio_palavra(texto, "decrepito", "decrépito");   substituir_inicio_palavra(texto, "efigie", "efígie");
    substituir_inicio_palavra(texto, "emissario", "emissário");   substituir_inicio_palavra(texto, "lapidario", "lapidário");
    substituir_inicio_palavra(texto, "natalicio", "natalício");   substituir_inicio_palavra(texto, "neofito", "neófito");
    substituir_inicio_palavra(texto, "reprobo", "réprobo");       substituir_inicio_palavra(texto, "satiro", "sátiro");
    substituir_inicio_palavra(texto, "serodia", "serôdia");       substituir_inicio_palavra(texto, "similes", "símiles");
    substituir_inicio_palavra(texto, "porfiro", "pórfiro");       substituir_inicio_palavra(texto, "setestrello", "Sete-Estrelo");
    substituir_inicio_palavra(texto, "Setestrello", "Sete-Estrelo");
    substituir_inicio_palavra(texto, "Todo-poderoso", "Todo-Poderoso");
    substituir_inicio_palavra(texto, "refugio", "refúgio");
    substituir_inicio_palavra(texto, "angustia", "angústia");
    substituir_inicio_palavra(texto, "angustias", "angústias");
    substituir_texto(texto, "-ha ", "-á ");                       substituir_texto(texto, "-ha.", "-á.");
    substituir_texto(texto, "-ha,", "-á,");

    // 10. Padronização de nomes próprios bíblicos e geográficos (pt-BR)
    substituir_inicio_palavra(texto, "Abrahão", "Abraão");
    substituir_inicio_palavra(texto, "Sarah", "Sara");
    substituir_inicio_palavra(texto, "David", "Davi");
    substituir_inicio_palavra(texto, "Jacob", "Jacó");
    substituir_inicio_palavra(texto, "Isaac", "Isaque");
    substituir_inicio_palavra(texto, "Rachab", "Raabe");
    substituir_inicio_palavra(texto, "Rahab", "Raabe");
    substituir_inicio_palavra(texto, "Rut", "Rute");
    substituir_inicio_palavra(texto, "Obed", "Obede");
    substituir_inicio_palavra(texto, "Josafat", "Josafá");
    substituir_inicio_palavra(texto, "Achaz", "Acaz");
    substituir_inicio_palavra(texto, "Amon", "Amom");
    substituir_inicio_palavra(texto, "Jechonias", "Jeconias");
    substituir_inicio_palavra(texto, "Eliakim", "Eliaquim");
    substituir_inicio_palavra(texto, "Sadoc", "Sadoque");
    substituir_inicio_palavra(texto, "Achim", "Aquim");
    substituir_inicio_palavra(texto, "Eliud", "Eliúde");
    substituir_inicio_palavra(texto, "Matan", "Matã");
    substituir_inicio_palavra(texto, "Emmanuel", "Emanuel");
    substituir_inicio_palavra(texto, "EMMANUEL", "EMANUEL");
    substituir_inicio_palavra(texto, "Gideon", "Gideão");
    substituir_inicio_palavra(texto, "Jefte", "Jefté");
    substituir_inicio_palavra(texto, "Zacharias", "Zacarias");
    substituir_inicio_palavra(texto, "Poncio", "Pôncio");
    substituir_inicio_palavra(texto, "Iturea", "Itureia");
    substituir_inicio_palavra(texto, "Abilinia", "Abilene");
    substituir_inicio_palavra(texto, "Eden", "Éden");
    substituir_inicio_palavra(texto, "Aristarcho", "Aristarco");
    substituir_inicio_palavra(texto, "macedonio", "macedônio");
    substituir_inicio_palavra(texto, "Fenix", "Fênix");
    substituir_inicio_palavra(texto, "Adriatico", "Adriático");
    substituir_inicio_palavra(texto, "Moises", "Moisés");
    substituir_inicio_palavra(texto, "Jehovah", "Jeová");         substituir_inicio_palavra(texto, "JEHOVAH", "JEOVÁ");
    substituir_inicio_palavra(texto, "Egipto", "Egito");
    substituir_inicio_palavra(texto, "egipci", "egípci");         substituir_inicio_palavra(texto, "Egipci", "Egípci");
    substituir_inicio_palavra(texto, "Jerusalem", "Jerusalém");
    substituir_inicio_palavra(texto, "Betlehem", "Belém");        substituir_inicio_palavra(texto, "Bethlehem", "Belém");
    substituir_inicio_palavra(texto, "Nazaret", "Nazaré");
    substituir_inicio_palavra(texto, "Galilea", "Galileia");      substituir_inicio_palavra(texto, "Galiléa", "Galileia");
    substituir_inicio_palavra(texto, "Judea", "Judeia");          substituir_inicio_palavra(texto, "Judéa", "Judeia");
    substituir_inicio_palavra(texto, "Laodicea", "Laodiceia");    substituir_inicio_palavra(texto, "Laodicéa", "Laodiceia");
    substituir_inicio_palavra(texto, "Cesarea", "Cesareia");      substituir_inicio_palavra(texto, "Berea", "Bereia");
    substituir_inicio_palavra(texto, "Betania", "Betânia");
    substituir_inicio_palavra(texto, "Getsemane", "Getsêmani");   substituir_inicio_palavra(texto, "Golgota", "Gólgota");
    substituir_inicio_palavra(texto, "Timoteo", "Timóteo");
    substituir_inicio_palavra(texto, "Bartolomeo", "Bartolomeu");
    substituir_inicio_palavra(texto, "Teofilo", "Teófilo");
    substituir_inicio_palavra(texto, "Enoch", "Enoque");
    substituir_inicio_palavra(texto, "Henoch", "Enoque");
    substituir_inicio_palavra(texto, "Lamech", "Lameque");
    substituir_inicio_palavra(texto, "Melquisedec", "Melquisedeque");
    substituir_inicio_palavra(texto, "Abimelech", "Abimeleque");
    substituir_inicio_palavra(texto, "Elimelech", "Elimeleque");
    substituir_inicio_palavra(texto, "Baruch", "Baruque");
    substituir_inicio_palavra(texto, "Eliseo", "Eliseu");
    substituir_inicio_palavra(texto, "Zaqueo", "Zaqueu");
    substituir_inicio_palavra(texto, "Mardoqueo", "Mardoqueu");
    substituir_inicio_palavra(texto, "Isaias", "Isaías");
    substituir_inicio_palavra(texto, "Oseas", "Oseias");
    substituir_inicio_palavra(texto, "Miqueas", "Miqueias");
    substituir_inicio_palavra(texto, "Ageo", "Ageu");
    substituir_inicio_palavra(texto, "corintios", "coríntios");
    substituir_inicio_palavra(texto, "Tessalonica", "Tessalônica");
    substituir_inicio_palavra(texto, "Iconio", "Icônio");
    substituir_inicio_palavra(texto, "Tiquico", "Tíquico");
    substituir_inicio_palavra(texto, "Onesiforo", "Onesíforo");
    substituir_inicio_palavra(texto, "Diotrefes", "Diótrefes");
    substituir_inicio_palavra(texto, "Demetrio", "Demétrio");
    substituir_inicio_palavra(texto, "Cornelio", "Cornélio");
    substituir_inicio_palavra(texto, "Sergio", "Sérgio");
    substituir_inicio_palavra(texto, "Claudio", "Cláudio");
    substituir_inicio_palavra(texto, "Julio", "Júlio");
    substituir_inicio_palavra(texto, "Felix", "Félix");
    substituir_inicio_palavra(texto, "Tiberio", "Tibério");
    substituir_inicio_palavra(texto, "Cesar", "César");
    substituir_inicio_palavra(texto, "Fenicia", "Fenícia");
    substituir_inicio_palavra(texto, "Frigia", "Frígia");
    substituir_inicio_palavra(texto, "Panfilia", "Panfília");
    substituir_inicio_palavra(texto, "Licia", "Lícia");
    substituir_inicio_palavra(texto, "Licaonia", "Licaônia");
    substituir_inicio_palavra(texto, "Misia", "Mísia");
    substituir_inicio_palavra(texto, "Bitinia", "Bitínia");
    substituir_inicio_palavra(texto, "Capadocia", "Capadócia");
    substituir_inicio_palavra(texto, "Cilicia", "Cilícia");
    substituir_inicio_palavra(texto, "Galacia", "Galácia");
    substituir_inicio_palavra(texto, "Macedonia", "Macedônia");
    substituir_inicio_palavra(texto, "Ilirico", "Ilírico");
    substituir_inicio_palavra(texto, "Italia", "Itália");
    substituir_inicio_palavra(texto, "ciprio", "cíprio");
    substituir_inicio_palavra(texto, "Libia", "Líbia");
    substituir_inicio_palavra(texto, "Etiopia", "Etiópia");       substituir_inicio_palavra(texto, "etiope", "etíope");
    substituir_inicio_palavra(texto, "Mesopotamia", "Mesopotâmia");
    substituir_inicio_palavra(texto, "Assiria", "Assíria");       substituir_inicio_palavra(texto, "assirios", "assírios");
    substituir_inicio_palavra(texto, "Babilonia", "Babilônia");   substituir_inicio_palavra(texto, "babilonios", "babilônios");
    substituir_inicio_palavra(texto, "Persia", "Pérsia");
    substituir_inicio_palavra(texto, "Grecia", "Grécia");
    substituir_inicio_palavra(texto, "Siquem", "Siquém");
    substituir_inicio_palavra(texto, "sidonios", "sidônios");     substituir_inicio_palavra(texto, "tirios", "tírios");
    substituir_inicio_palavra(texto, "Libano", "Líbano");
    substituir_inicio_palavra(texto, "Siao", "Sião");
    substituir_inicio_palavra(texto, "Moriah", "Moriá");
    substituir_inicio_palavra(texto, "hebreo", "hebreu");         substituir_inicio_palavra(texto, "Hebreo", "Hebreu");
    substituir_inicio_palavra(texto, "caldeo", "caldeu");         substituir_inicio_palavra(texto, "Caldeo", "Caldeu");
    substituir_inicio_palavra(texto, "cananeo", "cananeu");       substituir_inicio_palavra(texto, "Cananeo", "Cananeu");
    substituir_inicio_palavra(texto, "idumeo", "idumeu");         substituir_inicio_palavra(texto, "Idumeo", "Idumeu");
    substituir_inicio_palavra(texto, "amoreo", "amorreu");        substituir_inicio_palavra(texto, "Amoreo", "Amorreu");
    substituir_inicio_palavra(texto, "heteo", "heteu");           substituir_inicio_palavra(texto, "heveo", "heveu");
    substituir_inicio_palavra(texto, "Heveo", "Heveu");           substituir_inicio_palavra(texto, "jebuseo", "jebuseu");
    substituir_inicio_palavra(texto, "Jebuseo", "Jebuseu");       substituir_inicio_palavra(texto, "pereseo", "perizeu");
    substituir_inicio_palavra(texto, "fereseo", "perizeu");       substituir_inicio_palavra(texto, "Fereseus", "Perizeus");
    substituir_inicio_palavra(texto, "filisteo", "filisteu");     substituir_inicio_palavra(texto, "sabeo", "sabeu");
    substituir_inicio_palavra(texto, "sidoneo", "sidônio");

    // 11. Adaptação lexical e sintática para o leitor do Brasil (PT-BR)
    substituir_palavra_inteira(texto, "rapariga", "moça");
    substituir_palavra_inteira(texto, "Rapariga", "Moça");
    substituir_palavra_inteira(texto, "raparigas", "moças");
    substituir_palavra_inteira(texto, "Raparigas", "Moças");
    substituir_palavra_inteira(texto, "rapariguinha", "mocinha");
    substituir_palavra_inteira(texto, "Rapariguinha", "Mocinha");

    substituir_palavra_inteira(texto, "mancebo", "jovem");
    substituir_palavra_inteira(texto, "Mancebo", "Jovem");
    substituir_palavra_inteira(texto, "mancebos", "jovens");
    substituir_palavra_inteira(texto, "Mancebos", "Jovens");

    substituir_palavra_inteira(texto, "cachopa", "menina");
    substituir_palavra_inteira(texto, "Cachopa", "Menina");
    substituir_palavra_inteira(texto, "cachopas", "meninas");
    substituir_palavra_inteira(texto, "Cachopas", "Meninas");
    substituir_palavra_inteira(texto, "cachopo", "menino");
    substituir_palavra_inteira(texto, "Cachopo", "Menino");
    substituir_palavra_inteira(texto, "cachopos", "meninos");
    substituir_palavra_inteira(texto, "Cachopos", "Meninos");

    substituir_palavra_inteira(texto, "varões", "homens");
    substituir_palavra_inteira(texto, "Varões", "Homens");

    substituir_palavra_inteira(texto, "ósculo", "beijo");
    substituir_palavra_inteira(texto, "Ósculo", "Beijo");
    substituir_palavra_inteira(texto, "ósculos", "beijos");
    substituir_palavra_inteira(texto, "Ósculos", "Beijos");

    substituir_palavra_inteira(texto, "lume", "luz");
    substituir_palavra_inteira(texto, "Lume", "Luz");

    substituir_palavra_inteira(texto, "púcaro", "jarro");
    substituir_palavra_inteira(texto, "Púcaro", "Jarro");
    substituir_palavra_inteira(texto, "púcaros", "jarros");
    substituir_palavra_inteira(texto, "púcara", "jarra");
    substituir_palavra_inteira(texto, "Púcara", "Jarra");
    substituir_palavra_inteira(texto, "púcaras", "jarras");

    substituir_palavra_inteira(texto, "azorrague", "chicote");
    substituir_palavra_inteira(texto, "Azorrague", "Chicote");
    substituir_palavra_inteira(texto, "azorragues", "chicotes");
    substituir_palavra_inteira(texto, "alfaias", "utensílios");
    substituir_palavra_inteira(texto, "algibeira", "bolso");
    substituir_palavra_inteira(texto, "algibeiras", "bolsos");
    substituir_palavra_inteira(texto, "postigo", "janela");
    substituir_palavra_inteira(texto, "regato", "riacho");
    substituir_palavra_inteira(texto, "regatos", "riachos");
    substituir_palavra_inteira(texto, "verdugo", "carrasco");
    substituir_palavra_inteira(texto, "verdugos", "carrascos");

    substituir_palavra_inteira(texto, "Físico", "Médico");
    substituir_palavra_inteira(texto, "outrossim", "também");
    substituir_palavra_inteira(texto, "Outrossim", "Também");
    substituir_palavra_inteira(texto, "sobremaneira", "muito");
    substituir_palavra_inteira(texto, "Sobremaneira", "Muito");
    substituir_palavra_inteira(texto, "amiúde", "frequentemente");
    substituir_palavra_inteira(texto, "Amiúde", "Frequentemente");
    substituir_palavra_inteira(texto, "porventura", "acaso");
    substituir_palavra_inteira(texto, "Porventura", "Acaso");
    substituir_palavra_inteira(texto, "porquanto", "porque");
    substituir_palavra_inteira(texto, "Porquanto", "Porque");
    substituir_palavra_inteira(texto, "conquanto", "embora");
    substituir_palavra_inteira(texto, "Conquanto", "Embora");
    substituir_palavra_inteira(texto, "postoque", "embora");
    substituir_palavra_inteira(texto, "Postoque", "Embora");
    substituir_texto(texto, "de sorte que", "de modo que");
    substituir_texto(texto, "De sorte que", "De modo que");

// 12. Revisão complementar pós-varredura e leitura (Lote 1 - Nov/2026)
 // 12.1 Ditongos antigos (oi -> ou) e consoantes mudas (ct, pt)
 substituir_inicio_palavra(texto, "oiro", "ouro");
 substituir_inicio_palavra(texto, "Oiro", "Ouro");
 substituir_inicio_palavra(texto, "coiro", "couro");
 substituir_inicio_palavra(texto, "toiro", "touro");
 substituir_inicio_palavra(texto, "calaboiço", "calabouço");
 substituir_palavra_inteira(texto, "oiça", "ouça");
 substituir_palavra_inteira(texto, "oiçam", "ouçam");
 substituir_inicio_palavra(texto, "hemorrhoid", "hemorroid");

 substituir_inicio_palavra(texto, "recto", "reto");
 substituir_inicio_palavra(texto, "Recto", "Reto");
 substituir_inicio_palavra(texto, "recta", "reta");
 substituir_inicio_palavra(texto, "Recta", "Reta");
 substituir_inicio_palavra(texto, "esculptur", "escultur");
 substituir_inicio_palavra(texto, "auctor", "autor");
 /* "aspecto" e "expectação" ficam como estão: no PT-BR o "c" se mantém */
 substituir_inicio_palavra(texto, "incorruptibil", "incorrutibil");
 substituir_inicio_palavra(texto, "incorruptivel", "incorrutível");
 substituir_inicio_palavra(texto, "corruptivel", "corrutível");
 substituir_inicio_palavra(texto, "corruptor", "corrutor");
 substituir_inicio_palavra(texto, "corrupto", "corruto");
 substituir_inicio_palavra(texto, "excepto", "exceto");
 substituir_inicio_palavra(texto, "tecto", "teto");
 substituir_inicio_palavra(texto, "inspector", "inspetor");
 substituir_inicio_palavra(texto, "dictado", "ditado");
 substituir_inicio_palavra(texto, "espectaculo", "espetáculo");
 substituir_inicio_palavra(texto, "facto", "fato");
 substituir_inicio_palavra(texto, "aprompt", "apront");
 substituir_inicio_palavra(texto, "districto", "distrito");
 substituir_inicio_palavra(texto, "jactancia", "jactância");
 substituir_inicio_palavra(texto, "interdicto", "interdito");
 substituir_inicio_palavra(texto, "aqueducto", "aqueduto");
 substituir_inicio_palavra(texto, "estructur", "estrutur");
 substituir_inicio_palavra(texto, "indirect", "indiret");
 substituir_inicio_palavra(texto, "conductor", "condutor");

 // 12.2 Acentuação gráfica e vocabulário revisado
 substituir_inicio_palavra(texto, "talamo", "tálamo");
 substituir_inicio_palavra(texto, "heroe", "herói");
 substituir_inicio_palavra(texto, "simplices", "símplices");
 substituir_inicio_palavra(texto, "diluvio", "dilúvio");
 substituir_inicio_palavra(texto, "silencio", "silêncio");
 substituir_inicio_palavra(texto, "auxilio", "auxílio");
 substituir_inicio_palavra(texto, "notorio", "notório");
 substituir_inicio_palavra(texto, "psalterio", "saltério");
 substituir_inicio_palavra(texto, "artificio", "artifício");
 substituir_inicio_palavra(texto, "labio", "lábio");
 substituir_inicio_palavra(texto, "divorcio", "divórcio");
 substituir_inicio_palavra(texto, "premio", "prêmio");
 substituir_inicio_palavra(texto, "sanguinario", "sanguinário");
 substituir_inicio_palavra(texto, "repudio", "repúdio");
 substituir_inicio_palavra(texto, "cilicio", "cilício");
 substituir_inicio_palavra(texto, "arabio", "arábio");
 substituir_inicio_palavra(texto, "vicio", "vício");
 substituir_inicio_palavra(texto, "sitio", "sítio");
 substituir_inicio_palavra(texto, "habitavel", "habitável");
 substituir_inicio_palavra(texto, "historia", "história");
 substituir_inicio_palavra(texto, "ante-hontem", "anteontem");
 substituir_inicio_palavra(texto, "Hespanha", "Espanha");
 substituir_palavra_inteira(texto, "alumia", "ilumina");
 substituir_palavra_inteira(texto, "expurga-me", "limpa-me");
 substituir_palavra_inteira(texto, "assenhoreiem", "tomem posse");

 // 12.3 Nomes próprios e gentílicos bíblicos padronizados
 substituir_inicio_palavra(texto, "Zebedeo", "Zebedeu");
 substituir_inicio_palavra(texto, "amorrheo", "amorreu");
 substituir_inicio_palavra(texto, "nazireo", "nazireu");
 substituir_inicio_palavra(texto, "arameo", "arameu");
 substituir_inicio_palavra(texto, "keneo", "queneu");
 substituir_inicio_palavra(texto, "Keneo", "Queneu");
 substituir_inicio_palavra(texto, "kenezeo", "quenezeu");
 substituir_inicio_palavra(texto, "horeo", "horeu");
 substituir_inicio_palavra(texto, "Hebron", "Hebrom");
 substituir_inicio_palavra(texto, "Haman", "Hamã");
 substituir_inicio_palavra(texto, "Hesbon", "Hesbom");
 substituir_inicio_palavra(texto, "Hilkias", "Hilquias");
 substituir_inicio_palavra(texto, "Haran", "Harã");
 substituir_inicio_palavra(texto, "Horeb", "Horebe");
 substituir_inicio_palavra(texto, "Heman", "Hemã");
 substituir_inicio_palavra(texto, "Hezron", "Hezrom");
 substituir_inicio_palavra(texto, "Hanun", "Hanum");
 substituir_inicio_palavra(texto, "Habacuc", "Habacuque");

    /* 9. Acertos finais da revisão de 11/2026 (só grafia, sem trocar palavras) */
    substituir_texto(texto, "irreprehens", "irrepreens");
    substituir_palavra_inteira(texto, "Siria", "Síria");         substituir_palavra_inteira(texto, "siros", "sírios");
    substituir_palavra_inteira(texto, "Efeso", "Éfeso");         substituir_palavra_inteira(texto, "Tarsis", "Társis");
    substituir_palavra_inteira(texto, "aflicto", "aflito");      substituir_palavra_inteira(texto, "aflicta", "aflita");
    substituir_palavra_inteira(texto, "aflictos", "aflitos");    substituir_palavra_inteira(texto, "aflictas", "aflitas");
    substituir_palavra_inteira(texto, "mirrha", "mirra");
    substituir_palavra_inteira(texto, "oficio", "ofício");       substituir_palavra_inteira(texto, "oficios", "ofícios");
    substituir_palavra_inteira(texto, "paralitico", "paralítico"); substituir_palavra_inteira(texto, "paraliticos", "paralíticos");
    substituir_palavra_inteira(texto, "saduceos", "saduceus");
    substituir_palavra_inteira(texto, "aneis", "anéis");
    substituir_palavra_inteira(texto, "dificil", "difícil");     substituir_palavra_inteira(texto, "eficacia", "eficácia");
    substituir_palavra_inteira(texto, "geteo", "geteu");
    substituir_palavra_inteira(texto, "traír", "trair");         substituir_palavra_inteira(texto, "atraír", "atrair");
    substituir_palavra_inteira(texto, "saír", "sair");           substituir_palavra_inteira(texto, "caír", "cair");
    substituir_palavra_inteira(texto, "distraír", "distrair");
    /* saiu, caiu, traiu, saindo, atrairei: sem acento */
    substituir_texto(texto, "aíu", "aiu");                       substituir_texto(texto, "aíndo", "aindo");
    substituir_texto(texto, "aírei", "airei");                   substituir_texto(texto, "aíremos", "airemos");
    substituir_texto(texto, "aíria", "airia");
    /* Leitura de 25/11/2026 (Gn 6, Mt 2) */
    substituir_palavra_inteira(texto, "covado", "côvado");
    substituir_palavra_inteira(texto, "dadiva", "dádiva");       substituir_palavra_inteira(texto, "dadivas", "dádivas");
    substituir_texto(texto, "eis-que", "eis que");               substituir_texto(texto, "Eis-que", "Eis que");
    substituir_palavra_inteira(texto, "Judah", "Judá");
    /* Mesóclise antiga: far-lhe-has -> far-lhe-ás, dar-lhe-hemos -> dar-lhe-emos.
       Palavra inteira depois do hífen, para não tocar nomes como Maher-shalal-hash-baz. */
    substituir_palavra_inteira(texto, "has", "ás");              substituir_palavra_inteira(texto, "hemos", "emos");
    substituir_palavra_inteira(texto, "heis", "eis");            substituir_palavra_inteira(texto, "hia", "ia");
    substituir_palavra_inteira(texto, "hias", "ias");            substituir_palavra_inteira(texto, "hiam", "iam");
    {
        /* Pronome no meio: leval-o-ás -> levá-lo-ás, restituil-os-ás -> restituí-los-ás */
        static const char *pron[] = {"o", "a", "os", "as"};
        static const char *fim[] = {"ás", "eis", "emos", "ia", "ias", "iam"};
        static const char *rad_ant[] = {"uil-", "al-", "el-", "ôl-", "ol-", "il-"};
        static const char *rad_nov[] = {"uí-l", "á-l", "ê-l", "ô-l", "ô-l", "i-l"};
        for (int r = 0; r < 6; r++) {
            for (int p = 0; p < 4; p++) {
                for (int f = 0; f < 6; f++) {
                    char ant[32], nov[32];
                    snprintf(ant, sizeof(ant), "%s%s-%s", rad_ant[r], pron[p], fim[f]);
                    snprintf(nov, sizeof(nov), "%s%s-%s", rad_nov[r], pron[p], fim[f]);
                    substituir_texto(texto, ant, nov);
                }
            }
        }
    }

    /* Derivados de pôr: impozeram -> impuseram, propozera -> propusera */
    substituir_texto(texto, "poze", "puse");
    /* caluniar: o acento é só no substantivo "calúnia" */
    substituir_texto(texto, "calúniad", "caluniad");             substituir_texto(texto, "calúniam", "caluniam");
    substituir_texto(texto, "calúniando", "caluniando");         substituir_texto(texto, "calúnies", "calunies");
    substituir_palavra_inteira(texto, "quiseramos", "quiséramos");
    substituir_palavra_inteira(texto, "infíeis", "infiéis");     substituir_palavra_inteira(texto, "fíeis", "fiéis");
    /* -iar no presente não leva acento: confiamos, gloriamos, desvieis */
    substituir_palavra_inteira(texto, "confíamos", "confiamos"); substituir_palavra_inteira(texto, "gloríamos", "gloriamos");
    substituir_palavra_inteira(texto, "desvíeis", "desvieis");
    /* Pretérito forte leva acento agudo: tivésseis, tivéssemos */
    substituir_texto(texto, "tivêss", "tivéss");                 substituir_texto(texto, "Tivêss", "Tivéss");
    substituir_texto(texto, "estivêss", "estivéss");             substituir_texto(texto, "houvêss", "houvéss");
    substituir_texto(texto, "soubêss", "soubéss");               substituir_texto(texto, "quisêss", "quiséss");
    substituir_texto(texto, "fizêss", "fizéss");                 substituir_texto(texto, "pusêss", "puséss");
    substituir_texto(texto, "dissêss", "disséss");               substituir_texto(texto, "trouxêss", "trouxéss");
    substituir_texto(texto, "pudêss", "pudéss");                 substituir_texto(texto, "coubêss", "coubéss");

    converter_infinitivo_lusitano_para_gerundio(texto);
}

void limpar_texto_verso(const char *origem, char *destino) {
    int i = 0;
    int pos = 0;

    while (origem[i] != '\0' && origem[i] != '\n' && origem[i] != '\r') {
        if (origem[i] == '*') {
            i++;
            continue;
        }

        if (origem[i] == '[') {
            int j = i + 1;
            if (origem[j] == '[' || origem[j] == '^' || isdigit((unsigned char)origem[j])) {
                while (origem[j] != '\0' && origem[j] != ']') j++;
                if (origem[j] == ']') j++;
                if (origem[j] == ']') j++;

                if (origem[j] == '(') {
                    while (origem[j] != '\0' && origem[j] != ')') j++;
                    if (origem[j] == ')') j++;
                }

                if (pos > 0 && destino[pos - 1] == ' ' && origem[j] == ' ') {
                    j++;
                }

                i = j;
                continue;
            }
        }

        destino[pos++] = origem[i++];
    }
    destino[pos] = '\0';
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

            limpar_texto_verso(&linha[idx], texto_limpo);
            atualizar_ortografia(texto_limpo);
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

            limpar_texto_verso(&linha[idx], texto_limpo);
            atualizar_ortografia(texto_limpo);
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
        imprimir_linha_centralizada("Colabore espontaneamente com esta obra via PIX: 21980934118", LARGURA_PAGINA);
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
            const char **nomes = (opcao_principal == 1) ? nomes_at : nomes_nt;
            const char **pastas = (opcao_principal == 1) ? pastas_at : pastas_nt;
            const int *max_caps = (opcao_principal == 1) ? capitulos_at : capitulos_nt;
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
                imprimir_coluna(i + 1, nomes[i]);
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
                int total_do_livro = max_caps[opcao_livro - 1];

                printf("\n");
                imprimir_espacos(margem);
                printf("%s selecionado. Digite o capítulo (1 a %d): ",
                       nomes[opcao_livro - 1], total_do_livro);

                if (scanf("%d", &opcao_capitulo) == 1 &&
                    opcao_capitulo >= 1 && opcao_capitulo <= total_do_livro) {
                    limpar_buffer_entrada();
                    int leu_ate_o_fim = ler_capitulo(nomes[opcao_livro - 1], pastas[opcao_livro - 1], opcao_capitulo);
                    if (leu_ate_o_fim) {
                        pausar_tela();
                    }
                } else {
                    limpar_buffer_entrada();
                    printf("\n");
                    imprimir_espacos(margem);
                    printf("Capítulo inválido! O livro de %s possui capítulos de 1 a %d.\n",
                           nomes[opcao_livro - 1], total_do_livro);
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
