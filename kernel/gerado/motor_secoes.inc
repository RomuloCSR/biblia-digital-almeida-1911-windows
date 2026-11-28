/* =============================================================================
 * motor_secoes.inc — GERADO por gerador/gerar_kernel.c. NÃO EDITE À MÃO.
 *
 * O que é: as partes 1 (tabelas de livros) e 3 (limpeza do Markdown, gerúndio,
 *          sufixos/ênclises) do motor.biblia.c, copiadas como estão, com "static"
 *          na frente de cada definição (assim não brigam com outra cópia do motor).
 *          Ficaram de fora substituir_texto, substituir_inicio_palavra,
 *          substituir_palavra_inteira e atualizar_ortografia: no kernel elas viram a
 *          tabela regras_tabela.inc e as trocas rápidas de biblia_kernel.c.
 * Por quê: o kernel usa exatamente o mesmo código do motor nessas partes; mudou o
 *          motor, rode o gerador de novo e esta cópia acompanha.
 * Formato criado em 27/11/2026. Fonte: motor.biblia.c
 *          (SHA-256 do motor: DF46AC4D34CB59AE901864970E8F8626223E0A08877D55C4EC1CC489A2D6A891)
 * ============================================================================= */

#define MAX_LINHA 8192

/* -----------------------------------------------------------------------------
- 1. MAPEAMENTO DE DADOS (PASTAS, NOMES E CONTAGEM DE CAPÍTULOS)
- ----------------------------------------------------------------------------- */

static const char *pastas_at[39] = {
    "01-GEN", "02-EXO", "03-LEV", "04-NUM", "05-DEU", "06-JOS", "07-JDG", "08-RUT",
    "09-1SA", "10-2SA", "11-1KI", "12-2KI", "13-1CH", "14-2CH", "15-EZR",
    "16-NEH", "17-EST", "18-JOB", "19-PSA", "20-PRO", "21-ECC", "22-SNG",
    "23-ISA", "24-JER", "25-LAM", "26-EZK", "27-DAN", "28-HOS", "29-JOL",
    "30-AMO", "31-OBA", "32-JON", "33-MIC", "34-NAM", "35-HAB", "36-ZEP",
    "37-HAG", "38-ZEC", "39-MAL"
};

static const char *pastas_nt[27] = {
    "41-MAT", "42-MRK", "43-LUK", "44-JHN", "45-ACT", "46-ROM", "47-1CO", "48-2CO",
    "49-GAL", "50-EPH", "51-PHP", "52-COL", "53-1TH", "54-2TH",
    "55-1TI", "56-2TI", "57-TIT", "58-PHM", "59-HEB", "60-JAS", "61-1PE", "62-2PE",
    "63-1JN", "64-2JN", "65-3JN", "66-JUD", "67-REV"
};

static const char *nomes_at[39] = {
    "Gênesis", "Êxodo", "Levítico", "Números", "Deuteronômio", "Josué", "Juízes", "Rute",
    "1 Samuel", "2 Samuel", "1 Reis", "2 Reis", "1 Crônicas", "2 Crônicas", "Esdras",
    "Neemias", "Ester", "Jó", "Salmos", "Provérbios", "Eclesiastes", "Cânticos",
    "Isaías", "Jeremias", "Lamentações", "Ezequiel", "Daniel", "Oseias", "Joel",
    "Amós", "Obadias", "Jonas", "Miqueias", "Naum", "Habacuque", "Sofonias",
    "Ageu", "Zacarias", "Malaquias"
};

static const char *nomes_nt[27] = {
    "Mateus", "Marcos", "Lucas", "João", "Atos", "Romanos", "1 Coríntios", "2 Coríntios",
    "Gálatas", "Efésios", "Filipenses", "Colossenses", "1 Tessalonicenses", "2 Tessalonicenses",
    "1 Timóteo", "2 Timóteo", "Tito", "Filemom", "Hebreus", "Tiago", "1 Pedro", "2 Pedro",
    "1 João", "2 João", "3 João", "Judas", "Apocalipse"
};

static const int capitulos_at[39] = {
    50, 40, 27, 36, 34, 24, 21, 4,
    31, 24, 22, 25, 29, 36, 10,
    13, 10, 42, 150, 31, 12, 8,
    66, 52, 5, 48, 12, 14, 3,
    9, 1, 4, 7, 3, 3, 3,
    2, 14, 4
};

static const int capitulos_nt[27] = {
    28, 16, 24, 21, 28, 16, 16, 13,
    6, 6, 4, 4, 5, 3,
    6, 4, 3, 1, 13, 5, 5, 3,
    5, 1, 1, 1, 22
};

/* -----------------------------------------------------------------------------
- 3. MOTOR DE LIMPEZA E ATUALIZAÇÃO ORTOGRÁFICA / GRAMATICAL (PT-BR)
- ----------------------------------------------------------------------------- */

/* REVISÃO DO KERNEL (27/11/2026) — feita com Claude Opus 5.5 e testada na Bíblia inteira.
   Segurança: as funções substituir_* e atualizar_sufixos_e_enclises não cortam nem estouram
   mais o texto: se uma troca não couber em MAX_LINHA, o texto fica como estava. Regra vazia é
   ignorada. O gerúndio troca no lugar, sem buffer (antes podia estourar com palavra enorme).
   Texto: mesóclise -hei/-hão depois de pronome, fôssemos/fôsseis, acento de hiato em -i-lo-á,
   variantes de maiúscula, ordem de regras e o gerúndio que trocava "ficou a mulher".
   Teste: AddressSanitizer + UBSan sem erros; 120 versículos corrigidos, nenhum outro mudou.
   Relatórios: biblia-build/kernel_rev/relatorio_seguranca.md e relatorio_texto.md.
   Texto: buffer de pelo menos MAX_LINHA bytes; o texto pode crescer até MAX_LINHA - 2. */

/* [kernel] substituir_texto() do motor não é copiada aqui: a cópia rápida e fiel dela é bk_troca_texto()/bk_troca_palavra() em biblia_kernel.c */


/* [kernel] substituir_inicio_palavra() do motor não é copiada aqui: a cópia rápida e fiel dela é bk_troca_texto()/bk_troca_palavra() em biblia_kernel.c */


/* [kernel] substituir_palavra_inteira() do motor não é copiada aqui: a cópia rápida e fiel dela é bk_troca_texto()/bk_troca_palavra() em biblia_kernel.c */


static void converter_infinitivo_lusitano_para_gerundio(char *texto) {
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

            static const char *nao_verbos[] = {"mulher", "senhor", "Senhor", "amor", "temor", "favor",
                                               "louvor", "clamor", "pastor", "lugar", "altar", "pomar", "manjar", "suor", NULL};
            int eh_nome = 0;
            for (int s = 0; nao_verbos[s] != NULL; s++)
                if ((int)strlen(nao_verbos[s]) == v_len && strncmp(verbo, nao_verbos[s], (size_t)v_len) == 0) eh_nome = 1;

            if (v_len >= 4 && !eh_nome) {
                char vogal = verbo[v_len - 2];
                char erre = verbo[v_len - 1];
                if (erre == 'r' && (vogal == 'a' || vogal == 'e' || vogal == 'i' || vogal == 'o')) {
                    /* "estava a falar" -> "estava falando": mesmo numero de bytes
                       (tira "a " e troca "r" por "ndo"). Troca so esta ocorrencia, no lugar. */
                    memmove(pos + tam_aux - 2, verbo, (size_t)(v_len - 1));
                    memcpy(pos + tam_aux - 2 + (v_len - 1), "ndo", 3);
                    pos = texto;
                    continue;
                }
            }
            pos += tam_aux;
        }
    }
}

static int eh_delimitador(unsigned char c) {
    return (c == '\0' || c == ' ' || c == ',' || c == '.' || c == ';' ||
            c == ':' || c == '!' || c == '?' || c == ')' || c == '(' ||
            c == '"' || c == '\n' || c == '\r');
}

static int eh_vogal_simples(char c) {
    c = (char)tolower((unsigned char)c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

static void normalizar_composto_hifen(char *palavra) {
    char *hifen = strchr(palavra, '-');
    if (hifen == NULL) return;

    int pos_hifen = (int)(hifen - palavra);
    char radical[128];
    char sufixo[256];

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

static void atualizar_sufixos_e_enclises(char *str) {
    char buffer[MAX_LINHA];
    int i = 0, pos = 0;

    while (str[i] != '\0') {
        if (eh_delimitador((unsigned char)str[i])) {
            if (pos >= MAX_LINHA - 1) return; /* nao cabe: texto fica como estava */
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
            if (pos + len >= MAX_LINHA - 1) return; /* nao cabe: texto fica como estava */
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
                /* "il-o-hei", "il-o-ha"...: depois de vogal leva acento (restituil-o-ha -> restituí-lo-á),
                   menos no "gu"/"qu" (seguil-o-hão -> segui-lo-ão) */
                const char *novo_suf = regras[r].novo;
                char novo_hiato[32];
                int ini = len - tam_ant;
                if (regras[r].antigo[0] == 'i' && regras[r].antigo[1] == 'l' && ini >= 1 &&
                    eh_vogal_simples(palavra[ini - 1]) &&
                    !(ini >= 2 && palavra[ini - 1] == 'u' && (palavra[ini - 2] == 'g' || palavra[ini - 2] == 'q'))) {
                    snprintf(novo_hiato, sizeof(novo_hiato), "í%s", regras[r].novo + 1);
                    novo_suf = novo_hiato;
                }
                palavra[ini] = '\0';
                strcat(palavra, novo_suf);
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
                    char antes2 = len - tam_s - 2 >= 0 ? palavra[len - tam_s - 2] : ' ';
                    int hiato = eh_vogal_simples(antes) && !(antes == 'u' && (antes2 == 'g' || antes2 == 'q'));
                    strcat(palavra, hiato ? rep_hiato[k] : rep_cons[k]);
                    break;
                }
            }
        }

        int novo_len = (int)strlen(palavra);
        if (pos + novo_len >= MAX_LINHA - 1) return; /* nao cabe: texto fica como estava */
        memcpy(buffer + pos, palavra, (size_t)novo_len);
        pos += novo_len;
    }

    buffer[pos] = '\0';
    strcpy(str, buffer);
}

/* [kernel] atualizar_ortografia() do motor não é copiada aqui: as regras dela estão em regras_tabela.inc, na mesma ordem, e quem as aplica é bk_atualizar_no_lugar() */


static void limpar_texto_verso(const char *origem, char *destino) {
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
                if (origem[j] == '\0') {          /* '[' sem ']': mantem o texto */
                    destino[pos++] = origem[i++];
                    continue;
                }
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

