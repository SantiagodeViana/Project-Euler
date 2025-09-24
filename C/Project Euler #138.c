#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /* Solución al problema #138 de Project Euler
  * https://projecteuler.net/problem=138    */

int main()
{
    int respuesta = 17, triangles = 1; //Triangles cuenta los isóceles que cumplen con las condiciones establecidas. Ya se cuenta el primero en la respuesta porque el programa actual lo cuenta dos veces
    long long int L = 19, b = L/2;
    long double h;
    while (triangles < 12){ //Bucle de L hasta conseguir
        while (b < L){ //Bucle de b. Contando sólo bases menores que L
            h = sqrt(L*L - (b/2*b/2));
            if (h == (int)h){ //Sólo se consideran enteros como alturas
                if (h == (b+1) || h == (b-1)){
                    respuesta += L;
                    triangles++;
                    printf("%d) L:%lld b:%lld h:%lld Respuesta:%d\n", triangles, L, b, (int)h, respuesta);
                }
            }
            b++;
        }
        if (L % 10000 == 0) printf("L:%lld b:%lld\n", L, b);
        b = L/2; //Reiniciando valor de base
        L++;
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}
