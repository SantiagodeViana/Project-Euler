#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #100 de Project Euler
 * "Al encontrar la primera disposición que contenga más de 10¹² = 1 000 000 000 000 discos en total, determina el número de discos azules que contendría la caja."
 * https://projecteuler.net/problem=100            */

int main()
{
    const long double objetivo = 0.5L;
    const long double eps = 1e-15L;

    long long int total = 1000000000000, blues = (total*70711/100000), respuesta; //7071068/10000000
    long double probabilidad = (((long double)blues/total) * ((long double)(blues-1)/(total-1)));

    while (fabsl(probabilidad - objetivo) > eps){ //Expresión para permitir tolerancia de los signos
        if (probabilidad > 0.5L) blues--; //Si hay que reducir la probabilidad, se reduce el numerador
        else{
            total++; //En caso contrario, se aumenta el denominador y reinicia el numerador
            blues = (total*70711/100000);
        }
        probabilidad = (((long double)blues/total) * ((long double)(blues-1)/(total-1)));
        if (blues % 10000000 == 0) printf ("B:%lld T:%lld Probabilidad: %.12f\n", blues, total, (double)probabilidad);
    }
    respuesta = blues;
    printf("La respuesta es %lld\n", blues);
    return 0;
}
