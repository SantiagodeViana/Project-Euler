#include <stdio.h>
#include <stdlib.h>

 /* Solución para el problema #135 de Project Euler
  * "¿Cuántos valores de n menores que un millón tienen exactamente diez soluciones distintas?"
  * https://projecteuler.net/problem=135 */

int main()
{
    int x, y, z, d = 1, soluciones = 0, respuesta = 0; //x es el mayor cuadrado, d la diferencia
    for (int n = 1; n <= 100; n++){
        x = n*2;
        while (x > 2){ //3 es el valor mínimo antes de que z = 0 con la mínima diferencia
            y = x - d;
            z = x - 2*d;
            if (((x*x) - (y*y) - (z*z)) > n) d++; //Se aumenta la diferencia en caso de que la expresión sea mayor
            else if (((x*x) - (y*y) - (z*z)) <= n){
                if (((x*x) - (y*y) - (z*z)) == n){
                    soluciones++;
                    printf("%d^2 - %d^2 - %d^2 = %d\n", x, y, z, n);
                }
                x--;
                d = 1;
            }
        }
        if (soluciones >= 10) respuesta++;
        soluciones = 0;
    }
    printf("La respuesta es: %d\n", respuesta);
    return 0;
}
