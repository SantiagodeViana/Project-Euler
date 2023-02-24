#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #31 de Project Euler
 * "¿De cuántas formas diferentes se pueden hacer 2 £ utilizando cualquier número de monedas?"
 * https://projecteuler.net/problem=31            */

int main()
{
    int h, g, f, e, d, c, b, a, respuesta = 0; //200p, 100p, 50p, 20p, 10p, 5p, 2p, 1p
    for (a=0; a <= 1; a++){ //200p
        for (b=0; b <= 2; b++){ //100p
            for (c=0; c <= 4; c++){ //50p
                for (d=0; d <= 10; d++){ //20p
                    for (e=0; e <= 20; e++){ //10p
                        for (f=0; f <= 40; f++){ //5p
                            for (g=0; g <= 100; g++){ //2p
                                for (h=0; h <= 200; h++){ //p
                                    if (((a*200) + (b*100) + (c*50) + (d*20) + (e*10) + (f*5) + (g*2) + h) == 200){
                                        respuesta++;
                                        printf("Respuesta: %d\n", respuesta); 
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Fin del programa.\n");
    printf("La respuesta es: %d\n", respuesta); //La respuesta es 73682
    return 0;
}
