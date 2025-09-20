#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int pasosEuclides (long long int n, long long int m);

int main()
{//8191
    long long int n = 1000000000039, m = n, pasos = n, min = pasos, respuesta = m;
    for (long long int i = n; i >= 2; i--){
        pasos = pasosEuclides(n, i);
        if (pasos <= min){
            min = pasos;
            respuesta = i; //Se actualiza el mínimo de pasos conseguido y el coprimo que lo consigue
        }
        printf("f(n): %lld\n", respuesta); //printf ("i: %lld\n", i); if (i % 100000000 == 0)
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}

long long int pasosEuclides (long long int n, long long int m){ //Algoritmo de Euclides modificado para devolver número de pasos requeridos para obtener MCD
    int bound = floor(sqrt(n)), pasos = 0, pow = 1; //Pow multiplica a o b y la cantidad de pasos en potencias de diez para ahorrar operaciones
    long long int a = n, b = m; //De manera predeterminada se asume que n es mayor que m
    if (a == b) return a; //Si a = b, son iguales al MCD
    while (a != b && pasos < bound){ //Los restos se van turnando, de mayor a menor;
        if (a > b){
            while (a > b*pow) pow *= 10;
            while (a <= b*pow) pow /= 10;
            a -= b * pow;
        } else if (a < b){
            while (b > a*pow) pow *= 10;
            while (b <= a*pow) pow /= 10;
            b -= a;
        }
        pasos += 1 * pow;
        //printf("a: %lld b: %lld Pasos:%lld\n", a, b, pasos);
    }
    return pasos;
}
