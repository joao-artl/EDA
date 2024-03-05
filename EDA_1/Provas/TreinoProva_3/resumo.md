## HeapSort
- Complexidade: O(n logn)
- Adaptatividade: não é adaptativo
- Estabilidade: não é estável
- In-Place: é in place


## IntroSort

- Complexidade: O(n logn)
- Adaptatividade: é in-place
- Estabilidade: não é estável
- In-Place: é adaptativo


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


## Fila de prioridades

- fixUp, fixDown, sempre que adiciona ou remove um número
- MaxHeap, MinHeap

3 6 remove 9 1 5 remove 10 2

0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
    5
    8   5
    8   5   3
    8   6   3   5
    6   5   3   
    9   6   3   5
    9   6   3   5
    9   6   3   5    1
    9   6   5   5    1   3
    6   5   5   3    1   
    10   5   6   3   1   5 
    10   5   6   3   1   5  2