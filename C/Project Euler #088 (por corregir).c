#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #88 de Project Euler
 * "¿Cuál es la suma de todos los números mínimos 'producto-suma' para 2 ≤ k ≤ 12000?"
 * https://projecteuler.net/problem=88           */

int main()
{
    int n, a, b, respuesta = 0, suma = 0;
    for (int k = 2; k <= 6; k++){ //Tamaño k
        n = 4, a = 2, b = 2;
        while (k < n + 2){
            while (a * b != n){ //Se buscan divisores de n
                b++;
                if (b > n/2){
                    a++;
                    b = 2;
                }
            }
            if (k <= n){
                suma += n;
                printf("k = %d n = %d\n", k, n);
            }
            else n++;
        }
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}
