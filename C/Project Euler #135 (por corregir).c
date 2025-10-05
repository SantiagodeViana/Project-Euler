#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /* Solución para el problema #135 de Project Euler
  * "¿Cuántos valores de n menores que un millón tienen exactamente diez soluciones distintas?"
  * https://projecteuler.net/problem=135 */

int main()
{
    int x = 4, y = 3, z = 2, d = 1, soluciones = 0, respuesta = 0; //x es el mayor cuadrado, d la diferencia.
    long long int x2 = 16; //x2 denotará el cuadrado de x
    //Al ser x, 'y' y z parte de una progresión aritmética, la diferencia es la misma
    for (int n = 1; n <= 1000000; n++){
        x = n*2; //Se escoge el doble de n como valor inicial para comprobar soluciones
        x2 = x*x;
        for (; (x2 > n) && soluciones <= 10; x--){ //Se dejan de buscar candidatos si existen más de 10 soluciones exactas
            x2 = x*x;
            for (d = 1; x-2*d > 0; d++){ //3 es el valor mínimo antes de que z = 0 con la mínima diferencia. Las variables deben ser enteros positivos
                y = x - d;
                z = x - 2*d;
                if (x2 - (y*y) - (z*z) == n) soluciones++;
            }
        }
        if (soluciones == 10){
            respuesta++;
            printf("n: %d Respuesta: %d\n", n, respuesta);
        }
        if (n % 100000 == 0) printf("n: %d Respuesta: %d\n", n, respuesta);
        soluciones = 0;
    }
    printf("La respuesta es: %d\n", respuesta);
    return 0;
}
