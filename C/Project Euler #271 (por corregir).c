#include <stdio.h>
#include <stdlib.h>

#define N 13082761331670030

/* Solución para el problema #1 de Project Euler
 * "Para un número positivo n, definimos S(n) como la suma de los enteros x tales que 1 < x < n y x³ ≡ 1 (mod n).
 * Cuando n = 91, existen 8 posibles valores para x, a saber: 9, 16, 22, 29, 53, 74, 79, 81.
 * Así, S(91) = 9 + 16 + 22 + 29 + 53 + 74 + 79 + 81 = 363.
 * Encuentra S(13082761331670030). 
 * https://projecteuler.net/problem=271 */

int main()
{
    long long int respuesta = 0;
    for(long long int i = 2; i < N; i++){
        if ((i*i*i) % N == 1){
            printf("i: %d\n", i);
            respuesta += i;
        }
    }
    printf("La respuesta es %lld\n", respuesta);
    return 0;
}
