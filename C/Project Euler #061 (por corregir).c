#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /* Solución para el problema #61 de Project Euler
  * Halla la suma del único conjunto ordenado de seis números cíclicos de cuatro dígitos en el que cada tipo polígonal:
  * triángular, cuadrado, pentagonal, hexaonal, heptagonal y octagonal, está representado por un número diferente del conjunto.
  * https://projecteuler.net/problem=61                          */

int areCyclical(int n, int m, int o, int p, int q, int r);

int main()
{
    int respuesta, aux, pow, cyclical = 0;
    int x3, x4, x5, x6, x7, x8; //Números poligonales
    int i, j, k, l, m, n; //Índices
    for (i = 45; i < 140; i++){ //Los ìndices se modifican para buscar solamente cuatro dìgitos
        x3 = i * (i + 1) / 2; //Triangular
        for (j = 32; j < 99; j++){
            x4 = j * j; //Cuadrado
            for (k = 26; k < 81; k++){
                x5 = k * (3 * k - 1) / 2; //Pentagonal
                for (l = 23; l < 70; l++){
                    x6 = l * (2 * l - 1); //Hexagonal
                    for (m = 21; m < 63; m++){
                        x7 = m * (5 * m - 3) / 2; //Heptagonal
                        for (n = 19; n < 57; n++){
                            x8 = n * (3 * n - 2); //Heptagonal
                            cyclical *= (x3 % 100 == x4 / 100);
                            cyclical *= (x4 % 100 == x5 / 100);
                            cyclical *= (x5 % 100 == x6 / 100);
                            cyclical *= (x6 % 100 == x7 / 100);
                            cyclical *= (x7 % 100 == x8 / 100);
                            cyclical *= (x8 % 100 == x3 / 100);
                        }
                    }
                }
            }
            printf("i:%d, j%d, k:%d, l:%d, m:%d, n:%d   Respuesta:%d\n", x3, x4, x5, x6, x7, x8, respuesta);
        }
    }
    printf("La respuesta es  %d\n", respuesta);
    return 0;
}
