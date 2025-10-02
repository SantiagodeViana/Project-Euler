#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /* Solución para el problema #142 de Project Euler
  * "Encuentre el menor valor de x + y + z con números enteros > y > z > 0 tal que x + y, x − y, x + z, x − z, y + z, y − z sean todos cuadrados perfectos."
  * https://projecteuler.net/problem=142            */

int main()
{
    int x = 3, y = 2, z = 1, i = 1; //Valores mínimos que cumplen las condiciones
    double raiz; //Evalúa si las expresiones son cuadrados perfecto o no
    long long int respuesta = 0;
    while (respuesta == 0){
        while (x > y){
            raiz = sqrt(x + y);
            if (raiz == (int)raiz){
                raiz = x - y; //Sólo se evalúa 'z' si x y 'y' son válidos
                while(raiz == (int)raiz && y > z && respuesta == 0){ //Sale del bucle al descartar casos o conseguir respuesta
                    switch (i) {
                        case 1:
                            raiz = sqrt(x + z);
                            break;
                        case 2:
                            raiz = sqrt(x - z);
                            break;
                        case 3:
                            raiz = sqrt(y + z);
                            break;
                        case 4:
                            raiz =  sqrt(y - z);
                            break;
                        case 5: //Respuesta conseguida
                            printf("x:%d y:%d z%d\n", x, y, z);
                            respuesta =  x + y + z;
                            break;
                        default:
                            z++;
                            break;
                    }
                    i++;
                }
                i = 1;
                z = 1;
            }
            y++;
        }
        printf("x:%d y:%d z%d\n", x, y, z);
        y = 2;
        x++;
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}
