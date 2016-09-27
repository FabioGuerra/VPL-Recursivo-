/*  VPL.c

    Autor: Fabio Rodrigues Guerra
    Objetivo: Estudar recursao, utilizando o cálculo de VPL como motivador.

*/

#include<stdio.h>

float pot(int x, float y){

	if (x == 0) return 1.0;
	return (y*pot(x-1,y));
}

float NPV(int n, float presentValue, float i){
    if (n==0) return presentValue;
    float futureValue;
    printf("Enter the Future Value referring to the period n %d\n",n);
    scanf("%f",&futureValue);
    return ((futureValue/(pot(n,1+i)))+NPV(n-1,presentValue,i));
}

int main(){
    float i = 0.05; //12 %
    int n = 5; // 12 months
    float PV = -100; // R$ 10.000
    printf("Net present value = %.2f",NPV(n,PV,i));
	return 0;
}
