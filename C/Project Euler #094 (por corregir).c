#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #94 de Project Euler
 * https://projecteuler.net/problem=94    */

int main()
{
    int respuesta = 0, a = 1, b = 1, c;
    long double area, s; //Semiperimetro
    for (c = 2; c <= 1000000000; c++){ //Los bucles se mueven sólo con una unidad de diferencia
        s = (a + b + c) / 2; //Fórmula de Herón
        if (s == (int)s){ //s debe ser un entero. Los lados tampoco pueden ser iguales
            area = sqrt(s * (s - a) * (s - b) * (s - c));
            if (area == (int)area){
                respuesta+= (a + b + c); //Si el área también es un entero, se ha encontrado una respuesta
                printf("a:%d b:%d c:%d  Respuesta:%d\n", a, b, c, respuesta);
            }
        } //Se siguen buscando candidatos
        b++;
        a++;
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}
