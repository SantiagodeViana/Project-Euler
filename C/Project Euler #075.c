#include <stdio.h>
#include <stdlib.h>

#define N 1500000

/* Solución para el problema #75 de Project Euler
 * "¿Cuántas cadenas, con un número inicial menor de un millón, contienen exactamente sesenta términos no repetidos?"
 * https://projecteuler.net/problem=75                     */

int main()
{
    int x = 3, y = 4, z = 5, respuesta = 0; //La inicialización es de la menor terna pitagórica
    long long int a, b, c;
    while (x < N){
        while (y < N && y < (x + z)){ //Aplicando desigualdad triangular: z no puede ser mayor o igual que la suma de los otros dos lados
            while (z < N && z < (x + y)){
                if ((x + y + z) == N){ //Sólo se consideran lados que resulten en el N objetivo
                    a = x*x; b = y*y; c = z*z; //Inicializando cuadrados
                    if (a + b == c){ //Teorema de Pitágoras (cat^2 + cat^2 = hip^2)
                        respuesta++;
                        printf("Respuesta:%d - %d - x:%d y:%d z:%d\n", respuesta, (x + y + z), x, y, z);
                    }
                }
                z++;
            }
            y++;
            z=5;
        }
        if (x < (y + z)) x++;
        y=4;
        printf("x:%d y:%d z:%d  Respuesta:%d\n", x, y, z, respuesta);
    }
    printf("La respuesta es: %d\n", respuesta);
    printf("Fin del programa.\n");
    return 0;
}
