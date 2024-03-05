#include <stdio.h>

int main(){
    int distInicioX,distInicioY,distFimX,distFimY,distX,distY, distanciaTotal;
    scanf("%d %d %d %d", &distInicioX, &distInicioY, &distFimX, &distFimY);
    distX = (distFimX - distInicioX);
    distY = (distFimY - distInicioY);
    if(distX < 0){
        distX = distX * (-1);
    }
    if(distY < 0){
        distY = distY * (-1);
    }
    distanciaTotal = distX + distY;
    printf("%d\n", distanciaTotal);
    return 0;
}