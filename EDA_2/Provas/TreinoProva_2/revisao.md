# Revisão

## Árvores Binárias

- Cada nó possui no máximo dois filhos.
- Raiz representa nível 0.
- Nível K pode ter no máximo 2^K elementos.
- Altura lg(n).
- Filho a esquerda é sempre menor e filho a direita é sempre maior.
- Profundidade é distancia até a raiz.
- Balanceada se subarvores esquerda e direita possuem mesma altura, folhas possuem a mesma profundidade e altura = lg(n).
- Três percursos(usar bolinhas pra percorrer):
    - Pré-ordem: Raiz, Esquerda, Direita.
    - Em-ordem: Esquerda, Raiz, Direita.
    - Pós-ordem: Esquerda, Direita, Raiz.
- Árvore Binária de Busca é similar a busca binária.
- Inserção é similar a busca.
- Remoção: procura pelo menor dos maiores ou maior dos menores, troco de posição e removo o nó.

## Árvore Rubro-Negra Esquerdista

- Todo nó é vermelho ou preto
- A raiz e as folhas(NULL) são pretas
- Um nó só é preto se:
    - For filho esquerdo de seu pai
    - Seus filhos são vermelhos
- Altura negra(BH) é a quantidade de nós pretos até a folha desconsiderando a raiz
- Operações de correção:
    - Rotação à esquerda: filho direito de um nó preto com irmão preto ou filho direito de um nó vermelho
    - Rotação à direita: filho esquerdo de um nó vermelho(rotação no pai e avo)
    - Subida de cor: irmão vermelho
    