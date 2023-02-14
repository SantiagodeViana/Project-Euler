#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #10 de Project Euler
 * "Encuentra la suma de todos los números primos inferiores a dos millones."
 * https://projecteuler.net/problem=10            */

int esPrimo(long long int n);

int main()
{
    long long int respuesta = 0;
    for (long long int i = 2; i <= 2000000; i++){
        if  (esPrimo(i) == 1) respuesta += i;
    }

    printf("La respuesta es:%lld\n", respuesta);
    return 0;
}

int esPrimo(long long int n){//Función para determinar si un numero es primo, basada en la Criba de Eratóstenes
    if (n == 1) return 1; ////*Cambiar a 0 o mantener a conveniencia del programa
    else if (n < 4) return 1; //Si son menores de 4, son primos
    else if (n % 2 == 0) return 0; //Si son pares, no son primos
    else if (n < 9) return 1; //Si son menores de 9 e impares, son primos
    else if (n % 3 == 0) return 0; //Si son múltiplos de 3, no son primos
    else{
        int r = floor(sqrt(n));
        int f = 5;
        while (f <= r){
            if (n % f == 0) return 0;
            else if (n % (f + 2) == 0) return 0;
            else f += 6;
        }
        return 1;
    }
}
