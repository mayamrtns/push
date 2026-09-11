*This project has been created as part of the 42 curriculum by araissa-, malima-m.*

# push_swap

Um programa em C que ordena uma pilha de inteiros usando apenas duas pilhas (`a` e `b`) e um conjunto restrito de operações, buscando o menor número possível de instruções — e escolhendo entre quatro estratégias de ordenação diferentes conforme o grau de desordem da entrada.

---

## Description

O **push_swap** é um projeto do currículo da 42 cujo objetivo é ordenar, em ordem crescente, uma sequência de números inteiros informada por argumento, usando apenas duas pilhas (`stack_a` e `stack_b`) e 11 operações permitidas (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). O programa imprime na saída padrão a sequência de operações necessária para deixar a `stack_a` ordenada.

O grande desafio do projeto não é ordenar — é ordenar **com o menor número possível de operações**, o que obriga a entender e comparar complexidades algorítmicas reais, medidas em número de operações geradas (e não em complexidade teórica de algoritmos clássicos baseados em array).

Este projeto vai além do mínimo pedido e implementa **quatro estratégias de ordenação distintas**, selecionáveis por flag ou automaticamente pelo modo adaptativo:

| Estratégia | Classe de complexidade | Flag |
| :--- | :--- | :--- |
| Simple (seleção) | O(n²) | `--simple` |
| Medium (chunks) | O(n√n) | `--medium` |
| Complex (radix) | O(n log n) | `--complex` |
| Adaptive (escolhe conforme a desordem) | O(n²) / O(n√n) / O(n log n) | `--adaptive` (padrão) |

### Estrutura do projeto

| Pasta / Arquivo | Função |
| :--- | :--- |
| `srcs/main.c` | Ponto de entrada: inicializa contexto, chama parsing, calcula desordem, dispara a ordenação e o modo `--bench`. |
| `srcs/main_utils.c` | Reconhecimento de flags de modo (`is_mode_flag`), seleção de modo (`parse_mode`) e dispatch da estratégia (`run_sort`). |
| `srcs/parsing.c` | Conversão dos argumentos em números, detecção de duplicatas e montagem da `stack_a`. |
| `srcs/stack_utils.c` | Estrutura de pilha em lista duplamente encadeada: criação, inserção no fim e liberação. |
| `srcs/analysis.c` | Cálculo da **desordem** (`compute_disorder`), indexação da pilha (`index_stack`) e checagem se está ordenada (`is_sorted`). |
| `srcs/utils.c` | Validação numérica (`is_number`), impressão de erro e contagem/impressão de cada operação executada. |
| `srcs/bench_utils.c`, `bench_print.c`, `bench_strategy.c` | Formatação e impressão do relatório `--bench` (desordem, estratégia usada, contagem de operações). |
| `operations/` | As 11 operações da linguagem push_swap (`ft_swap`, `ft_push`, `ft_rotate`, `ft_rerotate` e seus wrappers `sa`/`sb`/`ss`/`pa`/`pb`/`ra`/`rb`/`rr`/`rra`/`rrb`/`rrr`). |
| `sort/sort_base.c` | Casos de base: `sort_two`, `sort_three` (comparações diretas) e `sort_five` (usa `stack_b` como apoio). |
| `sort/sort_dispatch.c` | `handle_small_sort`: atalho para pilhas com 5 elementos ou menos, comum a todas as estratégias. |
| `sort/selection_sort.c` | Estratégia **Simple** (O(n²)). |
| `sort/chunk_sort.c`, `chunk_utils.c` | Estratégia **Medium** (O(n√n)), por divisão em blocos (*chunks*). |
| `sort/radix_sort.c` | Estratégia **Complex** (O(n log n)), radix sort bit a bit sobre os índices. |
| `sort/adaptive_sort.c` | Estratégia **Adaptive**: escolhe internamente Simple, Medium ou Complex conforme a desordem medida. |
| `libft/` | Biblioteca própria (`ft_atol`, `ft_split`, `ft_itoa`, `ft_strjoin`, etc.), usada para parsing e formatação de strings sem `printf`/`atoi` da libc. |

---

## Instructions

### Pré-requisitos

- Um compilador C (`cc`)
- `make`

### Compilação

```bash
make
```

O `Makefile` compila primeiro a `libft` (via seu próprio Makefile) e depois o `push_swap`, com as flags `-Wall -Wextra -Werror`, sem relinkagem desnecessária.

```bash
make clean   # remove os .o
make fclean  # remove .o e o binário push_swap
make re      # fclean + make
```

### Como usar

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] N1 N2 N3 ...
```

- Os números podem ser passados como argumentos separados **ou** entre aspas separados por espaço (ex: `"1 2 3"`), graças ao `ft_split` usado no parsing.
- Sem argumentos, o programa não imprime nada e simplesmente encerra.
- Em caso de entrada inválida (não numérico, fora do intervalo de `int`, ou duplicata), o programa imprime `Error` na saída de erro (`stderr`) e encerra.

**Exemplo 1 — ordenação simples:**

```bash
./push_swap 2 1 3 6 5 8
```
```
sa
pb
pb
pb
ra
rb
rra
rrb
sa
pa
pa
pa
```

**Exemplo 2 — forçando uma estratégia:**

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --complex 4 67 3 87 23
```

**Exemplo 3 — modo benchmark (relatório em `stderr`, operações em `stdout`):**

```bash
./push_swap --bench $(shuf -i 0-9999 -n 500) 2> bench.txt 1> /dev/null
cat bench.txt
```
```
[bench] disorder: 47.85%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 8674
[bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500
[bench] ra: 5000 rb: 1294 rr: 0 rra: 0 rrb: 1380 rrr: 0
```


---

## Algoritmo utilizado

O núcleo do projeto é a métrica de **desordem** (`compute_disorder`, em `srcs/analysis.c`): para cada par de elementos da `stack_a`, conta-se uma "falha" sempre que um valor maior aparece antes de um menor; o resultado é `falhas / total_de_pares`, um número entre `0` (ordenada) e `1` (pior ordem possível). Essa medição é feita **antes** de qualquer operação, exatamente como exige o subject.

A partir da desordem, o modo `--adaptive` (padrão) escolhe uma das três estratégias:

1. **Simple — O(n²) (`sort/selection_sort.c`)**
   Usada quando `disorder < 0.2`. É uma adaptação de *selection sort*: `push_chunk` empurra **todos** os elementos de `stack_a` para `stack_b` num único bloco (`low = 0`, `high = size - 1`), e `push_back` traz de volta, um a um, sempre o maior elemento de `stack_b` (`find_big`), escolhendo `rb`/`rrb` conforme a posição mais curta até o topo. Como para cada um dos `n` elementos é feita uma busca linear pelo maior em `stack_b`, o custo é O(n²) operações — adequado para entradas quase ordenadas, onde não compensa a complexidade extra de um algoritmo mais sofisticado.

2. **Medium — O(n√n) (`sort/chunk_sort.c`, `chunk_utils.c`)**
   Usada quando `0.2 ≤ disorder < 0.5`. Antes de tudo, `index_stack` converte os valores reais em índices `0..n-1` (necessário para os algoritmos baseados em faixas/bits). O tamanho de cada bloco é `get_chunk_size(n) = 2 * ceil(sqrt(n))`, e a pilha é dividida em `⌈n / chunk_size⌉` blocos (`push_chunk`), dos maiores índices para os menores, empurrando para `stack_b` apenas o que pertence à faixa `[low, high]` da vez. Ao final de cada bloco, `push_back` devolve os elementos daquele intervalo já na posição correta relativa. Isso mantém o custo em torno de O(n√n) operações — o clássico *trade-off* entre O(n²) e O(n log n) para o modelo de duas pilhas.

3. **Complex — O(n log n) (`sort/radix_sort.c`)**
   Usada quando `disorder ≥ 0.5`. É um *radix sort* LSD binário: para cada bit (de `0` até `get_max_bits(n)`, ou seja, `⌈log₂(n)⌉` bits), todo elemento cujo bit correspondente do **índice** é `0` vai para `stack_b` (`pb`), o restante roda em `stack_a` (`ra`); ao final da passada, tudo volta para `stack_a` (`pa`). Como cada uma das `⌈log₂ n⌉` passadas custa O(n) operações, o total é O(n log n) — a melhor classe de complexidade suportada, ideal para entradas muito embaralhadas.

4. **Adaptive (`sort/adaptive_sort.c`)**
   Não é um algoritmo novo, e sim um despachante: mede a desordem uma única vez e delega para Simple, Medium ou Complex conforme os limiares acima, registrando em `context->strategy_used` qual delas foi de fato usada (visível no `--bench`).

**Casos de base comuns a todas as estratégias** (`sort/sort_dispatch.c`, `srcs/sort_base.c`): pilhas de `0` ou `1` elemento já estão ordenadas; `2` elementos usam uma comparação e, no máximo, um `sa`; `3` elementos usam uma tabela de 6 casos fixos (`sort_three`); `4` e `5` elementos usam `sort_five`, que empurra para `stack_b` o(s) menor(es) elemento(s) da pilha, ordena os 3 restantes com `sort_three` e traz tudo de volta com `pa`. Isso evita o custo de um algoritmo genérico para entradas pequenas, onde ele seria proporcionalmente caro.

### Por que esses limiares (0.2 / 0.5)?

- **`disorder < 0.2`**: a pilha está majoritariamente ordenada; o custo de uma busca linear repetida (Simple/O(n²)) permanece baixo na prática, pois poucos elementos realmente precisam se mover, e evita a sobrecarga extra de calcular blocos ou bits.
- **`0.2 ≤ disorder < 0.5`**: desordem intermediária — nem compensa pagar o preço quadrático do Simple, nem é tão caótica a ponto de precisar da granularidade bit a bit do radix. O particionamento em `√n` blocos equilibra o número de comparações com o número de deslocamentos.
- **`disorder ≥ 0.5`**: entrada próxima do pior caso; o radix sort garante um teto de O(n log n) operações independentemente de quão embaralhada a pilha esteja, evitando a degradação que Simple e Medium sofreriam nesse regime.

### Complexidade de espaço

Todas as estratégias operam sobre a mesma lista duplamente encadeada (`t_node`) alocada durante o parsing; nenhuma estrutura auxiliar de tamanho O(n) adicional é criada durante a ordenação (buscas como `find_big` e `find_min_position` percorrem a pilha existente em O(1) de espaço extra). O espaço total usado pelo programa é, portanto, O(n) — o mínimo necessário para armazenar os próprios elementos.

---

## Resources

### Documentação consultada

- Subject oficial do projeto **push_swap** (42 School)
- Conceitos de *Big-O notation* e classes de complexidade (O(n²), O(n√n), O(n log n))
- Documentação sobre listas duplamente encadeadas em C

### Uso de IA

A IA (Claude, Anthropic) foi utilizada como ferramenta de apoio para:

- Revisar a lógica dos algoritmos já implementados (chunk sort, radix sort, sort adaptativo) e discutir a justificativa de complexidade de cada um;
- Ajudar na organização, estruturação e formatação deste arquivo `README.md`.

A IA **não** foi utilizada como substituto do subject do projeto nem para gerar as funções de ordenação. Toda a implementação do código-fonte foi desenvolvida pela dupla com base no subject oficial do push_swap e nas normas da escola.

---

## Contribuições

> Seção obrigatória pelo subject (projeto em dupla). A divisão abaixo foi inferida a partir dos cabeçalhos `By:` de cada arquivo — **revisem e ajustem conforme a divisão real de trabalho antes de entregar**.

| Login | Áreas principais |
| :--- | :--- |
| **araissa-** | `libft` completa, parsing (`is_number`, `has_duplicate`),  operações `ft_rotate`/ módulo `--bench` (`bench_utils.c`, `bench_print.c`, `bench_strategy.c`), `Makefile`. |
| **malima-m** | `sort_base.c`, `sort_dispatch.c`, estratégias Medium/Complex (`chunk_sort.c`, `radix_sort.c`), `parsing.c`, `, operações `ft_rerotate`/`ft_swap` / `ft_push`. |
| **Ambos** | `push_swap.h`, `main_utils.c`, `main.c`, `analysis.c` (desordem/indexação), `stack_utils.c`, `adaptive_sort.c`  / arquivos criados por um e revisados/editados pelo outro. |

