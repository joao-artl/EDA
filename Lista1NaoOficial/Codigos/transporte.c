#include <stdio.h>

int main(){
    int nx, ny, nz, cx, cy, cz, areaC, areaN, NContainers;
    scanf("%d %d %d", &cx, &cy, &cz);
    scanf("%d %d %d", &nx, &ny, &nz);
    areaN = ny * nx;
    areaC = cx * cy;
    NContainers = areaN / areaC;
    NContainers = NContainers * (nz / cz);
    printf("%d\n", NContainers);
    return 0;
}