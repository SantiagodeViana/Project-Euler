#include <stdio.h>
#include <stdlib.h>

#define N 30

/* Solución para el problema #213 de Project Euler
 * "Encuentra la suma de todos los n, 0 < n < 64 000 000 tales que σ₂(n) sea un cuadrado perfecto."
 * https://projecteuler.net/problem=213           */

int main()
{
    int circus[N-1][N-1] = {1, 1, 1, ..., 1};
    for(int i; i <= 50; i++){ //Saltos
        for(int j=0; j < N; j++){ //Pulgas
            for(int k = 0; k < N; k++){
                switch (choice){ //Pendiente de considerar pulgas en "paredes"
                    case 0:
                        i++;
                        break;
                    case 1:
                        j--;
                        break;
                    case 2:
                        k++;
                        break;
                    case 3:
                        k--;
                        break;
                }
            }
        }
    }
    printf("Hello world!\n");
    return 0;
}
