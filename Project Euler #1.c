#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Solución para el problema #1 de Project Euler
     * "Encuentra la suma de todos los múltiplos de 3 o 5 por debajo de 1000."
     * https://projecteuler.net/problem=1            */
    int suma = 0;
    for (int i = 0; i < 1000; i++){
        if (i % 3 == 0|| i % 5 == 0) suma += i;
        if (i == 9) printf("Suma de multiplos de 3 o 5 menores que 10: %d\n", suma);
    }
    printf("La suma de multiplos de 3 o 5 menores que 1000 es: %d\n", suma);
    return 0;
}
