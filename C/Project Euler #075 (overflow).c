#include <stdio.h>
#include <stdlib.h>

#define N 1500000

int main()
{
    int x, y, z, respuesta = 0;
    long long int a, b, c;
    for(x=1; x <= N; x++){
        if (x < (y + z)){//Aplicando desigualdad triangular: z no puede ser mayor o igual que la suma de los otros dos lados
            for(y=1; y <= N; y++){
                if (y < (x + z)){
                    for(z=1; z <= N; z++){
                        if (z < (x + y) && (x + y + z) == N){ //Sólo se consideran lados que resulten en el N objetivo
                            a = x*x; b = y*y; c = z*z; //Inicializando cuadrados
                            if (a + b == c){ //Teorema de Pitágoras (cat^2 + cat^2 = hip^2)
                                respuesta++;
                                printf("Respuesta:%d - %d - x:%d y:%d z:%d\n", respuesta, (x + y + z), x, y, z);
                            }
                        }
                    }
                }
                printf("x:%d y:%d z:%d\n", x, y, z);
            }
        }
    }
    printf("La respuesta es: %d\n", respuesta / 2); //El programa actualmente cuenta las soluciones dos veces
    printf("Fin del programa.\n");
    return 0;
}
