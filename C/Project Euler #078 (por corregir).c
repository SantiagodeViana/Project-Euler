#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #78 de Project Euler
 * https://projecteuler.net/problem=78
 */

long long int partitions(int n, int k, long long int memo[][100]);
long long int partitionsAux(int n);

int main()
{
    int n = 2, respuesta = -1;
    long long int p, memo[100][100];
    while (respuesta == -1){
        p = partitions(n, n, memo);
        if (p % 1000000 == 0) respuesta = n;
        else n++;
        printf("p(%d): %d, respuesta: %d \n", n, p, respuesta);
    }
    printf("La respuesta es %d \n", respuesta);
    return 0;
}

long long int partitions(int n, int k, long long int memo[][100]){ //Devuelve el número de particiones de un n mediante un divide y vencerás. Diseñado para PE #76, #77 y #78
    if (n == 0) return 1;
    else if (n < 0 || k == 0) return 0;
    else if (memo[n][k] != -1) return memo[n][k];
    else{
        memo[n][k] = partitions(n, k-1, memo) + partitions(n-k, k, memo);
        return memo[n][k];
    }
}
long long int partitionsAux(int n) {
    static long long memo[100][100];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++) memo[i][j] = -1;
    }
    return partitions(n, n, memo);
}
