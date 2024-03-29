#include <stdio.h>
#include <string.h>

int main()
{
    char shel[50];
    char raj[50];
    int igual;
    scanf("%s", shel);
    scanf("%s", raj);
    igual = strcmp(shel, raj);
    if (igual == 0)
    {
        printf("De novo!\n");
    }
    else if ((strcmp(shel, "tesoura") == 0 && strcmp(raj, "papel") == 0) || (strcmp(shel, "papel") == 0 && strcmp(raj, "pedra") == 0) ||
             (strcmp(shel, "pedra") == 0 && strcmp(raj, "lagarto") == 0) || (strcmp(shel, "lagarto") == 0 && strcmp(raj, "Spock") == 0) ||
             (strcmp(shel, "Spock") == 0 && strcmp(raj, "tesoura") == 0) || (strcmp(shel, "tesoura") == 0 && strcmp(raj, "lagarto") == 0) ||
             (strcmp(shel, "lagarto") == 0 && strcmp(raj, "papel") == 0) || (strcmp(shel, "papel") == 0 && strcmp(raj, "Spock") == 0) ||
             (strcmp(shel, "Spock") == 0 && strcmp(raj, "pedra") == 0) || (strcmp(shel, "pedra") == 0 && strcmp(raj, "tesoura") == 0))
    {
        printf("Bazinga!\n");
    }
    else
    {
        printf("Raj trapaceou!\n");
    }
    return 0;
}