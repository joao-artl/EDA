#include <stdio.h>
#include <string.h>
void ordenaMatriz(char matriz[][25], int qtd) {
    for (int i = 0; i < qtd; i++) {
        for (int j = i+1; j < qtd; j++) {
            if (strcmp(matriz[i], matriz[j]) < 0) {
                char nome[25];
                strcpy(nome, matriz[i]);
                strcpy(matriz[i], matriz[j]);
                strcpy(matriz[j], nome);
            }
        }
    }
}

int main() {
    int alunos, indice, inst = 1;

    while (scanf("%d", &alunos) != EOF) {
        int menorPonto = 11, pontos, t = 0;
        char turma[alunos][25];

        for(int i = 0; i < alunos; i++) {
            scanf(" %[^\n]s", turma[i]);
        } 
        ordenaMatriz(turma, alunos);
    
        for(int i = 0; i < alunos; i++) {
            t = strlen(turma[i])-1;
            //printf("[%c]\n", turma[i][t]);
            if(turma[i][t-1] == '1')
                pontos = 10;

            if(turma[i][t] >= '0' && turma[i][t] <= '9' && turma[i][t-1] == ' ') 
                pontos = turma[i][t]-'0';

            if(menorPonto > pontos) {
                menorPonto = pontos;
                indice = i;
            }
        }

        t = strlen(turma[indice])-1;
        turma[indice][t-1] = '\0';
        printf("Instancia %d\n%s\n\n", inst, turma[indice]);
        inst++;
    }

return 0;
}