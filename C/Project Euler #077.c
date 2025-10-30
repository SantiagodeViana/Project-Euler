#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #77 de Project Euler
 * "¿Cuál es el primer valor que se puede escribir como la suma de números primos de más de cinco mil maneras diferentes?"
 * https://projecteuler.net/problem=77                                  */

int isPrime(int n);
long long int partitions(int n, int k);

int main()
{
    int n = 2, respuesta = -1;
    long long int p;
    while (respuesta < 5000){
        respuesta = partitions(n, n);
        printf("p(%d): %d\n", n, respuesta);
        n++;
    }
    printf("La respuesta es %d \n", respuesta - 1);
    return 0;
}

int isPrime(int n){//Función para determinar si un numero es primo, basada en la Criba de Eratóstenes
    if (n == 1) return 0; ////*Cambiar a 1 o mantener a conveniencia del programa
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

long long int partitions(int n, int k){ //Devuelve el número de particiones de un n mediante un divide y vencerás. Diseñado para PE #76, #77 y #78
    if (n == 0) return 1;
    else if (n < 0 || k == 0) return 0;
    else if (isPrime(k) == 0) return partitions(n, k-1); //Variante de particiones de primos: se descartan las particiones que no lo sean
    else return partitions(n, k-1) + partitions(n-k, k);
}
