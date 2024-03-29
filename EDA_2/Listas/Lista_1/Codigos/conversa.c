#include <stdio.h>
int main () {
  
    int m, n, x, y, k;
    int dir;
    int i;
    int xAtual, yAtual;
    int minutos;
    scanf (" %d %d", &m, &n);
    scanf (" %d %d", &x, &y);
    scanf (" %d", &k);
    minutos = 0;
    xAtual = 0;
    yAtual = 0;
    for (i = 0; i < k; i++){
        scanf (" %d", &dir);
        switch(dir) {
        case 1: 
            yAtual++;
            break;
        case 2:
            yAtual--;
            break;
        case 3:
            xAtual++;
            break;
        case 4:
            xAtual--;
            break;
        }
        if(xAtual >= x - 1 && xAtual <= x + 1 && yAtual >= y - 1 &&  yAtual <= y + 1){
        minutos++;
        }
    }
    printf ("%d\n", minutos);
    return 0;
}