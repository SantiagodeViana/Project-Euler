#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #80 de Project Euler
 * "Para los primeros cien números naturales, encuentra el total de las sumas de dígitos de los primeros cien decimales de todas las raíces cuadradas irracionales."
 * https://projecteuler.net/problem=80            */

int main()
{
    int respuesta = 0;
    long double aux = sqrt(2);
    for (int i = 1; i <= 100; i++){
        aux *= 10; //Se quita la parte binaria y se almacena el siguiente decimal
        respuesta += aux;
        printf("%d) Respuesta: %d\n", i, respuesta);
        aux /= 10;
    }
    printf("La respuesta es %d", respuesta);
    return 0;
}
