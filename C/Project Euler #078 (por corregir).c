#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 500

/* Solución para el problema #78 de Project Euler
 * https://projecteuler.net/problem=78
 */

long long int partitions(int n, int k, long long int memo[][N]);

int main()
{
    int n = 1, respuesta = -1;
    long long int p, memo[N][N];
    for (int i = 0; i <= N; i++){ //Inicializando lista
        for (int j = 0; j <= N; j++) memo[i][j] = -1;
    }
    while (respuesta == -1){
        p = partitions(n, n, memo);
        if (p % 1000000 == 0) respuesta = n;
        else n++;
        printf("p(%d): %d, respuesta: %d \n", n, p, respuesta);
    }
    printf("La respuesta es %d \n", respuesta);
    return 0;
}

long long int partitions(int n, int k, long long int memo[][N]){ //Devuelve el número de particiones de un n mediante un divide y vencerás. Diseñado para PE #76, #77 y #78
    if (n == 0) return 1;
    else if (n < 0 || k == 0) return 0;
    else if (memo[n][k] != -1) return memo[n][k];
    else{
        memo[n][k] = partitions(n, k-1, memo) + partitions(n-k, k, memo);
        return memo[n][k];
    }
}
