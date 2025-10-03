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
        while (x > y && respuesta == 0){
            raiz = sqrt(x + y);
            if (raiz == (int)raiz){
                raiz = sqrt(x - y);
                if (raiz == (int)raiz){ //Sólo se evalúa 'z' si x y 'y' son válidos
                    while(y > z && respuesta == 0){
                        raiz = sqrt(x + z);
                        while(raiz == (int)raiz && respuesta == 0){ //Sale del bucle al descartar casos o conseguir respuesta
                            switch (i) { //La raíz de actualiza en cada caso y se evalúa si es un entero (cuadrado perfecto)
                                case 1:
                                    raiz = sqrt(x - z);
                                    break;
                                case 2:
                                    raiz = sqrt(y + z);
                                    break;
                                case 3:
                                    raiz =  sqrt(y - z);
                                    break;
                                case 4: //Respuesta conseguida
                                    printf("x:%d y:%d z%d\n", x, y, z);
                                    respuesta =  x + y + z;
                                    break;
                            }
                            i++;
                        }
                        i = 1;
                        z++;
                    }
                    z = 1;
                }
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
