#include <stdio.h>

int main(){
    int nx, ny, nz, cx, cy, cz, Comprimento, Largura, Altura, NContainers;
    scanf("%d %d %d", &cx, &cy, &cz);
    scanf("%d %d %d", &nx, &ny, &nz);
    Altura = nz / cz;
    Largura = ny / cy;
    Comprimento = nx / cx;
    NContainers =  Largura * Comprimento * Altura;
    printf("%d\n", NContainers);
    return 0;
}