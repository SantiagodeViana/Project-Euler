#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #120 de Project Euler
 * https://projecteuler.net/problem=120    */

int main()
{
    int max = 0, respuesta = 0; //n es el exponente y r el resto
    long long int a, b, suma, r;
    for (int i = 3; i <= 1000; i++){ //a
        a = i - 1;
        b = i + 1;
        max = 0;
        while (a < LLONG_MAX/(i+1) && b < LLONG_MAX/(i+1)){ //Condición para evitar overflow, repitiendo n veces
            a *= (i - 1); // (a-1)^n
            b *= (i + 1); // (a+1)^n
            suma = a + b; // (a-1)^n + (a+1)^n
            r = suma % (i * i);
            if (r > max) max = r;
        }
        respuesta += max;
        printf("a: %lld, max: %d Respuesta:%d\n", i, max, respuesta);
    }
    return 0;
}
