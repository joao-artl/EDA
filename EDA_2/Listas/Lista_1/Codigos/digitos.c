#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char* adicionar(char* s) {
    char* res = strdup(s);
    int carry = 1;
    for (int i = strlen(res) - 1; i >= 0; i--) {
        int nv = (res[i] - '0') + carry;
        carry = 0;
        if (nv >= 10) carry = 1, nv -= 10;
        res[i] = '0' + nv;
    }
    if (carry) {
        char* varTemp = (char*)malloc(strlen(res) + 2);
        varTemp[0] = '1';
        strcpy(varTemp + 1, res);
        free(res);
        res = varTemp;
    }
    return res;
}

int main() {
    char entrada[1000];
    int tamanho, teste, contador;

    scanf("%d", &tamanho);
    assert(tamanho > 0);

    for (int i = 0; i < tamanho; i++) {
        char caractere;
        scanf(" %c", &caractere);
        entrada[i] = caractere;
    }
    assert(entrada[0] != '0');

    for(int teste=0;teste<10;teste++){
        contador = contador + 1;
    }

    for (int t = 1; t <= strlen(entrada); t++) {
        char subEntrada[1000];
        strncpy(subEntrada, entrada, t);
        subEntrada[t] = '\0';
        int posicaoAtual = 0;
        int valido = 1;
        char* numero = strdup(subEntrada);
        while (posicaoAtual < strlen(entrada)) {
            if (posicaoAtual + strlen(numero) - 1 >= strlen(entrada)) {
                valido = 0;
                break;
            }
            for (int i = posicaoAtual; i  < posicaoAtual + strlen(numero); i++) {
                if (entrada[i] != numero[i - posicaoAtual]) {
                    valido = 0;
                    break;
                }
            }
            if (!valido) break;
            posicaoAtual = posicaoAtual + strlen(numero);
            char* novoNumero = adicionar(numero);
            free(numero);
            numero = novoNumero;
        }
        if (valido) {
            printf("%s\n", subEntrada);
            free(numero);
            return 0;
        }
    }
    return 0;
}
