#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /* Solución al problema #138 de Project Euler
  * "Encuentra ΣL para los doce triángulos isósceles más pequeños para los que h = b±1 y b, L son números enteros positivos."
  * https://projecteuler.net/problem=138        */

int main()
{
    int respuesta = 3941225, triangles = 9; //Triangles cuenta los isóceles que cumplen con las condiciones establecidas. Ya se cuenta el primero en la respuesta porque el programa actual lo cuenta dos veces
    long long int L = 3590000, b = (22*L/25);
    long double h, ratio;
    while (triangles < 12){ //Bucle de L hasta conseguir
        while (b < (9*L/10)){ //Bucle de b. Contando sólo bases menores que L
            h = sqrt(L*L - (b/2*b/2));
            if (h == (int)h){ //Sólo se consideran enteros como alturas
                if (h == (b+1) || h == (b-1)){
                    respuesta += L;
                    triangles++;
                    ratio = (double)b/L;
                    //printf("Ratio: %f\n", (double)ratio);
                    printf("%d) L:%lld b:%lld h:%lld Respuesta:%d\n", triangles, L, b, (int)h, respuesta);
                }
            }
            b++;
        }
        if (L % 10000 == 0) printf("L:%lld b:%lld\n", L, b);
        b = (22*L/25); //Reiniciando valor de base
        L++;
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}
