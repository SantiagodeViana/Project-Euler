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
    int pasos = 0;
    long long int a = n, b = m; //De manera predeterminada se asume que n es mayor que m
    if (a == b) return a; //Si a = b, son iguales al MCD
    else if (n < m){ //Si n es menor que m,
        a = m;
        b = n;
    }
    while ((a != 0) && (b != 0) && (a != 1) && (b != 1) && (a % b != 0)){ //Los restos se van turnando, de mayor a menor;
        if ((b != 0) && (a != 1) && (b != 1)){
            a = (a % b);
            pasos++;
        }
        if ((a != 0) && (a != 1) && (b != 1)){
            b = (b % a);
            pasos++;
        }
    }
    return pasos;
    return 1;
}
