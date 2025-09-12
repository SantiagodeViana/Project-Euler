#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #78 de Project Euler
 * https://projecteuler.net/problem=78
 */

long long int partitions(int n, int k);

int main()
{
    int n = 1, p, respuesta = -1;
    while (respuesta == -1){
        p = partitions(n, n);
        if (p % 1000000 == 0) respuesta = n;
        else n++;
        printf("p(%d): %d, respuesta: %d \n", n, p, respuesta);
    }
    respuesta = partitions(n, n);
    printf("La respuesta es %d \n", respuesta);
    return 0;
}

long long int partitions(int n, int k){ //Devuelve el número de particiones de un n mediante un divide y vencerás. Diseñado para PE #76, #77 y #78
    if (n == 0) return 1;
    else if (n < 0 || k == 0) return 0;
    else return (partitions(n, k - 1) + partitions(n - k, k));
}
