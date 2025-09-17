#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #21 de Project Euler
 * https://projecteuler.net/problem=21            */

int amicablePair(int n, int m);

int main() {
    int suma = 0;
    for (int i = 1; i <= 10000; i++){
        for (int j = 1; j <= i; j++){
            if (amicablePair(i, j) == 1){
                suma += (i+j);
                printf("i: %d  j: %d Suma: %d\n", i, j, suma);
            }
        }
    }
    printf("La respuesta es %d\n", suma);
    return 0;
}

int amicablePair(int n, int m){ //La función confirma si la suma de los divisores del par introducido es igual al otro número, formando un "par amigable"
    int i = 1, div = 0; //Índice y suma de divisores
    int amicableN = 1, amicableM = 1; //Booleanos para confirmar si los números son "amigables" por cuenta propia
    if (n == m){
        amicableN = 0;
        amicableM = 0;
    }
    while (amicableN == 1 && i <= (n/2)){ //Se comienza confirmando si n es "amigable"
        if (n % i == 0){
            div += i;
            if (div > m) amicableN = 0; //Se detiene la búsqueda si la suma de divisores
        }
        i++;
    }
    if (div == m){
        div = 0;
        i = 1; //Reiniciando variables
        while (amicableM == 1 && i <= (m/2)){ //Se comienza confirmando si n es "amigable"
            if (m % i == 0){
                div += i;
                if (div > n) amicableM = 0; //Se detiene la búsqueda
            }
            i++;
        }
        if (div != n) amicableM = 0;
    } else amicableN = 0;
    return (amicableN && amicableM);
}
