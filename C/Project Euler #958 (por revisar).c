#include <stdio.h>
#include <stdlib.h>

int pasosEuclides (long long int n, long long int m);

int main()
{
    long long int n = 89, m = n;
    int pasos = pasosEuclides(n, m), min = pasos, respuesta = m;
    for (int i = n; i >= 2; i--){
        pasos = pasosEuclides(n, i);
        if (pasos < min){
            min = pasos;
            respuesta = i; //Se actualiza el mínimo de pasos conseguido y el coprimo que lo consigue
        }
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}

int pasosEuclides (long long int n, long long int m){ //Algoritmo de Euclides modificado para devolver número de pasos requeridos para obtener MCD
    long long int a = n, b = m, pasos = 1; //De manera predeterminada se asume que n es mayor que m
    while (a != b){ //Los restos se van turnando, de mayor a menor;
        if (a > b) a -= b ;
        else if (a < b) b -= a;
        pasos ++;
    }
    return pasos;
}

