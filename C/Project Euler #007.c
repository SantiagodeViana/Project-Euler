#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #7 de Project Euler
 * "¿Cuál es el 10 001º número primo?"
 * https://projecteuler.net/problem=7            */

int esPrimo(int n);

int main()
{
    int n = 1, respuesta = 1;
    while (respuesta <= 10001){
        n++;
        if (esPrimo(n)) respuesta++;
    }
    printf("\nLa respuesta es %d\n", n); //La respuesta es 104743
    return 0;
}

int esPrimo(int n){ //Función para determinar si un numero es primo, basada en la Criba de Eratóstenes
    if (n == 1) return 1; //Cambiar a 0 o mantener a conveniencia del programa
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
