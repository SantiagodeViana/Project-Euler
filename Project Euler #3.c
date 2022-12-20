#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int  esPrimo(long long int n);

int main()
{
    /* Solución para el problema #3 de Project Euler
     * "¿Cuál es el mayor factor primo del número 600851475143?"
     * https://projecteuler.net/problem=3            
     * La versión actual del código alcanza la solución, pero no termina el bucle; considerar corrección  */

    long long int respuesta = 1;
    for (long long int i = 1; i < 600851475143; i++){
        if ((esPrimo(i) == 1) && (600851475143 % i == 0)){
            respuesta = i; //Escoger los mayores factores primos
            printf("El factor primo mayor de 600851475143 es: %lld\n", respuesta);
        }
    }
    printf("El factor primo mayor de 600851475143 es: %lld\n", respuesta);
    return 0;
}

long long int esPrimo(long long int n){//Función para determinar si un numero es primo, basada en la Criba de Eratóstenes
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
