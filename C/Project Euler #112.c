#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #112 de Project Euler
 * Encuentra el menor número para el cual la proporción de números bouncy es exactamente 99%.
 * https://projecteuler.net/problem=112 */

int isIncreasing (int n);
int isDecreasing (int n);
int isBouncy (int n);

int main()
{
    int i;
    double bounces = 0, respuesta;
    for (i = 1; respuesta < 0.99; i++){
        if (isBouncy(i) == 1){
            bounces++;
            respuesta = bounces/i;
            printf("i: %d, respuesta %f (%f)\n", i, respuesta, bounces);
        }
    }
    printf("La respuesta es %d", i-1);
    return 0;
}

int isIncreasing (int n){
    int aux = n % 10, inc = 1;
    while (n >= 10 && inc == 1){
        n /= 10;
        if (n % 10 > aux) inc = 0;
        aux = n % 10;
    }
    return inc;
 }
int isDecreasing (int n){
    int aux = n % 10, dec = 1;
    while (n >= 10 && dec == 1){
        n /= 10;
        if (n % 10 < aux) dec = 0;
        aux = n % 10;
    }
    return dec;
 }
int isBouncy (int n){
    int bounce = 1;
    if (n < 100) bounce = 0; //No hay bouncy numbers menores que 100
    else{
        if (isDecreasing(n) == 1 || isIncreasing(n) == 1) bounce = 0; //Un bouncy number no es ni incremental ni decremental
    }
    return bounce; //La operación también puede hacerse con un solo chequeo, pero el número probablemente deba ser tratado como una cadena
}
