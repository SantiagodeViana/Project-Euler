#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Soluci�n para el problema #2 de Project Euler
     * "Considerando los t�rminos de la sucesi�n de Fibonacci cuyos valores no superan los cuatro millones, halle la suma de los t�rminos de valor par."
     * https://projecteuler.net/problem=2            */
    int n1 = 1, n2 = 2, aux = 0, respuesta = 2;
    while(n2 < 4000000){
        aux = n2;
        n2 += n1;
        n1 = aux;
        if (n2 % 2 == 0) respuesta += n2;
    }
    printf("La suma de los terminos pares de la sucesi�n de Fibonacci inferiores a cuatro millones es: %d\n", respuesta);
    return 0;
}
