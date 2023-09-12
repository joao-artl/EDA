#include <stdio.h>

int main(){
    int distancia, distanciaPedagio, custoKM, valorPedagio,custoTotal;
    scanf("%d %d", &distancia, &distanciaPedagio);
    scanf("%d %d",&custoKM, &valorPedagio);
    custoTotal = ((distancia/distanciaPedagio)*valorPedagio + (distancia*custoKM));
    printf("%d\n", custoTotal);
    return 0;
}