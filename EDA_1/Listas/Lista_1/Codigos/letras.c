#include <stdio.h>

int main(){
    char frase[1000];
    char letra;
    double palavrasLetra = 0, letraEncontrada = 0;
    double porcentagem;
    scanf(" %c", &letra);
    getchar();
    fgets(frase, sizeof(frase), stdin);
    int Npalavras = 1;

    for (int i = 0; frase[i] != '\0'; i++){
        if (frase[i] == ' '){
            Npalavras++;
        }   
        if(frase[i] == letra){
            letraEncontrada++;
        }
        if(frase[i] == ' ' && letraEncontrada > 0){
            palavrasLetra++;
            letraEncontrada = 0;
        }
    }
    if(letraEncontrada > 0){
        palavrasLetra++;
    }

    porcentagem = (palavrasLetra/Npalavras)*100;
    printf("%.1lf\n", porcentagem);
    return 0;
}