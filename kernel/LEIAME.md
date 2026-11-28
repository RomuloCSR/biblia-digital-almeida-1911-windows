# Kernel da Bíblia Almeida ARC-1911 (versão 1.0)

Data: 27/11/2026. Fonte: `motor.biblia.c` do app Windows (commit `15ef5f8`, SHA-256 do arquivo `DF46AC4D34CB59AE901864970E8F8626223E0A08877D55C4EC1CC489A2D6A891`).

O kernel é um arquivo C (`biblia_kernel.c`) com um cabeçalho (`biblia_kernel.h`). Ele limpa o Markdown e atualiza a ortografia de cada versículo. O texto sai **igual ao do motor, byte a byte**, cerca de 12 vezes mais rápido. Ele não tem `printf`, `system`, terminal nem caminho de arquivo, e pode ser chamado de várias threads ao mesmo tempo.

## O que tem nesta pasta

| Arquivo | Para que serve |
|---|---|
| `biblia_kernel.h` | A API: versão, livros, `bk_verso`, `bk_atualizar`, `bk_capitulo` |
| `biblia_kernel.c` | A implementação: trocas rápidas, percurso da tabela, API |
| `gerado/*.inc` | Gerados a partir do motor. **Não edite à mão.** |
| `gerador/gerar_kernel.c` | Lê o `motor.biblia.c` e escreve `gerado/` |
| `teste/` | Teste de regressão, golden, comparação com o motor, varredura |
| `rodar_testes.ps1` / `rodar_testes.sh` | Um comando que gera, compila e roda todos os testes |
| `resultados/` | Saída dos testes de 27/11/2026 (Windows e WSL) |

Para levar para um programa, copie **`biblia_kernel.h`, `biblia_kernel.c` e a pasta `gerado/`** para uma pasta `kernel/` do programa. O resto (gerador e testes) fica só neste repositório.

## Como cada programa usa o kernel

Nos 6 programas a mudança tem dois passos:

1. **Passo 1 (pequeno).**
   - Troque o bloco `extern` das tabelas por `#include "kernel/biblia_kernel.h"`.
   - Troque o par `limpar_texto_verso(&linha[idx], texto_limpo); atualizar_ortografia(texto_limpo);` por `bk_verso(&linha[idx], texto_limpo, sizeof texto_limpo);`. Dá o mesmo texto.
   - Troque as tabelas pelas funções:
     - `nomes_at[i]` vira `bk_livro_nome(i)` e `nomes_nt[i]` vira `bk_livro_nome(39 + i)`;
     - `pastas_*` vira `bk_livro_pasta(...)` e `capitulos_*` vira `bk_livro_capitulos(...)`.
   - Compile `kernel/biblia_kernel.c` no lugar do `motor.biblia.c`.
2. **Passo 2 (opcional).** Troque o laço que lê o capítulo linha por linha por uma chamada de `bk_capitulo(md, tamanho, callback, ctx)`. O kernel lê as linhas como o `ler_capitulo()` do motor. O laço copiado em cada app deixa de existir.

Na partida, cada programa pode conferir a versão com `if (!BK_API_COMPATIVEL()) { ...avisa e sai... }`.

### Terminal Windows, Linux e macOS

- O `motor.biblia.c` do terminal vira `terminal.c`. Apague dele a parte 1 (tabelas) e a parte 3 (motor de texto), que agora estão no kernel. Ficam as partes 2, 4 e 5 (tela, leitura do capítulo, menu).
- Em `ler_capitulo()`, faça o passo 1 nos dois lugares (verso e subtítulo).
- Em `main()`, as linhas `const char **nomes = ... nomes_at : nomes_nt;` viram `int base = (opcao_principal == 1) ? 0 : 39;` e `bk_livro_nome(base + i)`, `bk_livro_pasta(base + i)`, `bk_livro_capitulos(base + i)`.
- Compilar:
  - Windows: `gcc -O2 -Wall -Wextra terminal.c kernel/biblia_kernel.c -o motor.biblia.exe`
  - Linux e macOS: o mesmo, com `-o biblia`. No macOS, `cc` (clang) também serve.

### App Windows (WebView2, `src/app.cpp`)

- Troque o bloco `extern "C" { ... }` das linhas 30 a 39 por `#include "../kernel/biblia_kernel.h"`. O cabeçalho já tem `extern "C"`.
- Linhas 167–168 e 178–179: faça o passo 1.
- No passo 2, `capitulo_json()` chama `bk_capitulo(conteudo.data(), conteudo.size(), item_json, &saida)`. O callback monta o JSON de cada verso ou subtítulo. Assim saem os `static char linha[]` e `texto_limpo[]` das linhas 141–142, que não aguentam duas threads.
- Em `compilar.ps1`, o passo 1 vira:
  `gcc -O2 -Wall -Wextra -c "kernel\biblia_kernel.c" -o "build\kernel.o"`
  No passo 3, use `build\kernel.o` no lugar de `build\motor.o`. O `-Dmain=motor_main_terminal` deixa de ser preciso.

### App Linux (GTK, `src/app_linux.c`)

- Faça o mesmo do app Windows: o bloco `extern` das linhas 23 a 30 vira `#include "../kernel/biblia_kernel.h"`, e as linhas 134–135 e 142–143 recebem o passo 1.
- No passo 2: `g_file_get_contents(caminho, &md, &n, NULL); bk_capitulo(md, n, item_json, s); g_free(md);`
- Em `compilar.sh`:
  `gcc -O2 -Wall -Wextra -c kernel/biblia_kernel.c -o build/kernel.o`
  Na linha final, use `build/kernel.o` no lugar de `build/motor.o`.
- O GTK chama `setlocale()`. Num locale UTF-8 isso não muda o texto (veja o aviso em `biblia_kernel.h`).

### Android (JNI, `app/src/main/cpp/native-lib.cpp`)

- O bloco `extern "C"` das linhas 9 a 18 vira `#include "kernel/biblia_kernel.h"`. As linhas 137–138 e 146–147 recebem o passo 1.
- No passo 2, o asset já está inteiro em `conteudo`. Basta `bk_capitulo(conteudo.data(), (size_t)tamanho, item_android, &saida)`.
- No `CMakeLists.txt`, troque `motor.biblia.c` por `kernel/biblia_kernel.c` e acrescente:
  `target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/kernel)`
  O `__ANDROID_APP__` deixa de ser preciso para o kernel.

## Como mudar uma regra e gerar a tabela de novo

As regras continuam sendo escritas no `motor.biblia.c`, dentro de `atualizar_ortografia()`, como hoje.

1. Mude a regra no motor.
2. Rode `powershell -File rodar_testes.ps1 -Gerar` no Windows, ou `sh rodar_testes.sh <pasta do motor> <pasta textos> --gerar` no Linux. Isso compila `gerador/gerar_kernel.c`, regrava `gerado/` e roda os testes.
3. Se a mudança muda o texto de propósito, o teste de regressão vai falhar e mostrar o **primeiro versículo diferente**. Confira se a mudança é a esperada e então:
   - rode `teste_regressao <textos> teste/golden/todos_versos.golden.tsv --atualizar`;
   - revise `git diff -- teste/golden/` (cada linha mudada é um versículo);
   - ponha o SHA novo em `BK_GOLDEN_SHA256` e a data em `BK_REGRAS_VERSAO` (`biblia_kernel.c`);
   - commite o golden junto com a regra.
4. Copie `gerado/` (e `biblia_kernel.c`, se mudou) para a pasta `kernel/` de cada programa.

O gerador só conhece as formas de regra que o motor usa hoje:

- as 3 funções `substituir_*` com literais, variáveis ou itens de tabela;
- tabelas `static const char *X[]`, `X[][2]` e `struct {...} X[]`;
- `for` com `i++`, `if`/`else` e `snprintf(buf, sizeof(buf), "%s…", …)`;
- as chamadas de sufixos e de gerúndio.

Qualquer outra instrução faz o gerador **parar com erro** e mostrar a linha. Assim nenhuma regra fica de fora sem ninguém ver.

Duas outras proteções avisam quando o motor muda de um jeito que pede revisão:

- Se alguém mudar `substituir_texto`, `substituir_inicio_palavra` ou `substituir_palavra_inteira`, o kernel **não compila**. A mensagem pede para revisar `bk_troca_*`, porque a cópia rápida tem de fazer o mesmo que o motor. Depois, troque `BK_TROCAS_REVISADAS`.
- Se a parte 1 ou a parte 3 do motor ganhar `printf`, arquivo, `malloc` ou uma variável `static` sem `const`, o gerador para.

## Provas (27/11/2026)

- Referência: `biblia-build\todos_versos.tsv`, SHA-256 `A1F2DE1C654560A27A81169C8995A254D71F8004A77590102F8B5DC4F061DE7F`, igual a `kernel_rev\fix_todos_versos.tsv`.
- Golden: `teste/golden/todos_versos.golden.tsv`. É a referência com fim de linha LF: 31.104 linhas, 4.303.426 bytes, SHA-256 `C37979A1F09A0219E3A2F465DFBE8A94BD71A3ED2C90997A859DE9F5F3E3949A`.
- `teste_regressao` deu **PASSOU** com o kernel (e 8 threads com o mesmo SHA) e com o motor original.
- `varredura_kernel` gera os 4 arquivos da `varredura.c`. Todos saem **iguais** aos da referência:
  - `todos_versos.tsv` `A1F2DE1C…`
  - `versos.tsv` `D637A143…`
  - `palavras.tsv` `F06B6443…`
  - `resumo.txt` `4D0EE096…`

  Isso cobre os 31.104 versos e as 31.025 palavras únicas.
- `comparar` deu 0 diferenças em 7 conjuntos: versos, palavras, maiúsculas, iniciais, linhas cruas, textos longos até 8.191 bytes e `bk_verso`.
- `conferir_tabela`: as 5.150 regras da tabela são as 5.150 chamadas do motor, na mesma ordem, com os mesmos bytes e o mesmo flag de acento.
- Tudo isso passou com gcc 15.2 `-O2` no Windows. No WSL Ubuntu (gcc 15.2), passou com `-O2` e com `-fsanitize=address,undefined` (sem erro nem vazamento).
- O kernel compila sem aviso com `-std=c99 -Wall -Wextra -pedantic`.

| Tempo (Ryzen 5 8500G) | Motor | Kernel |
|---|---|---|
| Só a ortografia, 31.104 versos (melhor de 3) | 8,3 s (268 µs/verso) | 0,75 s (24 µs/verso): **11,2×** |
| Só a ortografia, 31.025 palavras | 5,4 s | 0,07 s: **81×** |
| `varredura` completa (Windows) | 14,8 a 15,4 s | 1,22 a 1,26 s: **12×** |
| Ortografia no WSL, 31.104 versos | 8,6 s | 0,66 s: **13×** |

## Limites

- Os sufixos e ênclises (`atualizar_sufixos_e_enclises`) usam o código do motor sem mudança. Eles levam cerca de 9,7 µs dos 24 µs de cada versículo. Uma versão mais rápida dessa função daria uns 17×, mas seria uma segunda cópia para manter igual. Não entrou.
- Não foi testado em Android (NDK/ARM), macOS de verdade nem MSVC. No MSVC, `bk_ctz64` usa `_BitScanForward64`, mas não foi compilado.
- `bk_capitulo` lê as linhas como o `ler_capitulo()` do motor atual: tira o BOM e descarta o resto de uma linha longa demais. A `varredura.c` antiga não faz essas duas coisas. Com os `.md` de hoje (sem BOM, sem linha longa, sem `\r` e sem tab) as duas dão o mesmo resultado.
