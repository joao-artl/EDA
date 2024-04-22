## CountingSort

- Complexidade: O(n)
- Adaptatividade: é adaptativo
- Estabilidade: é estavel
- In-Place: não é in-place


## RadixSort

- Complexidade:  O(n)
- Adaptatividade: é adaptativo
- Estabilidade: é estavel
- In-Place: pode ser in-place


## InsertionSort

- Complexidade: O(n²), melhor caso: O(n²)
- Adaptatividade: É adaptativo
- Estabilidade: É estável
- In-Place: É In-Place
- Melhor em vetores pequenos


## MergeSort

- Complexidade: O(nlogn)
- Adaptatividade: Não é adaptativo
- Estabilidade: É estável (lessEq)
- In-Place: Não é In-Place
- Dividir e Conquistar
- Otimização: nos subvetores InsertionSort


## QuickSort

- Complexidade: O(nlogn), pior caso: O(n²)
- Adaptatividade: Não é adaptativo
- Estabilidade: Não é estável
- In-Place: É In-Place


## QuickSelect

- Complexidade: O(n), pode virar O(n²)
- Ordena parcialmente
- Derivado do quickSort


## Busca Binária

- Complexidade: O(logn)
- Vetor deve estar ordenado


## Tabela Hash

- Complexidade: Varia, em média O(1) para inserção, busca e remoção
- Adaptatividade: Não é adaptativa
- Estabilidade: Não é estável
- In-Place: Não é in-Place
- Eficiente para operações de busca, inserção e remoção
- Usa funções de hash para mapear chaves a índices em um vetor

### Tratamento de Colisões

- **Endereçamento Separado:**
  - Cada índice do vetor hash pode armazenar uma lista ligada.
  - Todas as chaves mapeadas para o mesmo índice são armazenadas nesta lista.
  - Isso permite que várias chaves coexistam no mesmo índice sem substituição.
  - Desvantagem: Pode haver uma degradação no tempo de busca se muitas chaves colidirem no mesmo índice.

- **Sondagem Linear/Endereçamento Aberto:**
  - Se ocorrer uma colisão, a tabela hash tentará encontrar o próximo índice livre usando um intervalo fixo (geralmente 1).
  - Continua sondando até encontrar um índice vazio ou até ter sondado todos os índices possíveis.
  - Desvantagem: Tendência à aglomeração primária, onde grupos de entradas ocupadas crescem, aumentando o tempo de busca e inserção.
