#include <stdio.h>

char *pV = NULL;
int contV = 0;
int contX = 0;

int ajustarVetor(char strN[], int contV, int contX)
{

    if(contX == 0){
        pV = strN;
        strN[contV] = '\0';
        return 0;
    }
    else{
        strN[contV] = 'x';
        contV++;
        contX--;
        return ajustarVetor(strN, contV, contX);
    }
}

int analiseString(char strN[], int cont)
{
    static char semX[1001];

    if (strN[cont] == 'x')
    {
        contX++;
    }
    else
    {
        if (strN[cont] == '\0')
        {
            return ajustarVetor(semX, contV, contX);
        }
        else
        {
            semX[contV] = strN[cont];
            contV++;
        }
    }

    cont++;
    return analiseString(strN, cont);
}

int main()
{

    char str[1001];
    int cont = 0;

    scanf("%[^\n]", str);

    analiseString(str, cont);

    printf("%s\n", *&pV);

    return 0;
}