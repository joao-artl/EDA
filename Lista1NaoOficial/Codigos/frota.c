#include <stdio.h>

int main(){
    double PAlcool, PGasolina, RAlcool, RGasolina,VAlcool,VGasolina;
    scanf("%lf %lf %lf %lf", &PAlcool, &PGasolina, &RAlcool, &RGasolina);
    VAlcool = PAlcool / RAlcool;
    VGasolina = PGasolina / RGasolina;
    if(VAlcool < VGasolina){
        printf("A\n");
    }
    else{
        printf("G\n");
    }
    return 0;
}