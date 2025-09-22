#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #94 de Project Euler
 * https://projecteuler.net/problem=94    */

int main()
{
    long double area, s; //Semiperimetro
    int respuesta = 0;
    for (int a = 1; a <= 1000000000; a++){
        for (int b = a; b <= a+1; b++){
            for (int c = b; c <= b+1; c++){ //Los bucles se mueven sólo con una unidad de diferencia
                s = (a + b + c) / 2; //Fórmula de Herón
                if ((a != b || b != c) && (a == b || b == c)){ //s debe ser un entero. Los lados tampoco pueden ser iguales
                    area = sqrt(s * (s - a) * (s - b) * (s - c));
                    if (area == (int)area){
                        respuesta+= (a + b + c); //Si el área también es un entero, se ha encontrado una respuesta y se suma el perímetro
                        printf("a:%d b:%d c:%d  Respuesta:%d\n", a, b, c, respuesta);
                    }
                }
            }
        }
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}
