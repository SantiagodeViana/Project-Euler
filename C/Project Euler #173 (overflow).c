#include <stdio.h>
#include <stdlib.h>

#define TILES 1000000

 /* Solución para el problema #173 de Project Euler
  * "Usando hasta un millón de baldosas, ¿cuántas láminas cuadradas diferentes pueden formarse?"
  * https://projecteuler.net/problem=173       */

int main()
{
    int respuesta = 0;
    // TILES < a < b
    for (long long int a = 3; a <= TILES; a++){ //a representa el perímetro y el "grueso" de las láminas
        for (long long int b = 1; b <= (a-2); b++){ //a representa el perímetro y el "grueso" de las láminas
            if (((a%2 == 0 && b%2 == 0) || (a%2 != 0 && b%2 !=0)) && ((a+b)*(a-b) <= TILES)){ //Expresando a^2 - b^2 como (a+b)(a-b)
                respuesta++; //a y b deben tener la misma paridad, y no deben exceder la cantidad de casillas.
                if (a % 1000 == 0) printf ("a: %d  b: %d  Respuesta: %d\n", a, b, respuesta);
            }
        }
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}
