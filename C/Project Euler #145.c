#include <stdio.h>
#include <stdlib.h>

/* Solución al problema #145 de Project Euler
 * "¿Cuántos números reversibles hay por debajo de mil millones (10^9)?"
 * https://projecteuler.net/problem=145       */

int revert(int n);
int isReversible(int n);

int main()
{
    int respuesta = 0;
    for (int i = 1; i <= 1000000000 ; i++){
        if (isReversible(i) == 1) respuesta ++;
    }
    printf("La respuesta es %d \n", respuesta);
    return 0;
}

int revert(int n){ //Invierte input n
    int reverse = 0;
    if (n < 0 || n % 10 == 0) return 0;
    while (n > 0) {
        reverse = reverse * 10 + (n % 10);
        n /= 10;
    }
     return reverse;
}

int isReversible(int n){
    int suma, reversible = 1; //reversible es una variable booleana
    suma = n + revert(n);
    while (suma > 0 && reversible == 1){
        reversible = ((suma % 10) % 2 == 1); //Se evalúa cada dígito uno por uno si son impares
        suma /= 10;
    }
    return reversible;
}
