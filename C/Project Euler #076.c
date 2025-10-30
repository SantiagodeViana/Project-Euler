#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #76 de Project Euler
 * "¿De cuántas formas diferentes se puede escribir el número cien como suma de al menos dos números enteros positivos?"
 * https://projecteuler.net/problem=76                             */
 
long long int partitions(int n, int k); //Devuelve el número de particiones de un n mediante un divide y vencerás. Diseñado para PE #76, #77 y #78

int main()
{
    int n = 100
    long long int p, respuesta = 0;
    p = partitions(n, n);
    respuesta += p;
    printf("p(%d): %d, respuesta: %d \n", n, p, respuesta - 1);
    printf("La respuesta es %d \n", respuesta - 1);
    return 0;
}

long long int partitions(int n, int k){ 
    if (n == 0) return 1;
    else if (n < 0 || k == 0) return 0;
    else return partitions(n, k-1) + partitions(n-k, k);
}
