#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #21 de Project Euler
 * "Evalúa la suma de todos los números amigables menores de 10000."
 * https://projecteuler.net/problem=21            */

int divSum(int n);
int amicablePair(int n, int m);

int main() {
    int suma = 0;
    for (int i = 1; i <= 10000; i++){
        for (int j = 1; j < i; j++){
            if (amicablePair(i, j) == 1){
                suma += (i+j);
                printf("i: %d  j: %d Suma: %d\n", i, j, suma);
            }
        }
    }
    return 0;
}

int divSum(int n){ //Función para sumar divisores de n
    int i = 1, div = 0; //Índice y suma de divisores
    while (i <= (n/2)){
        if (n % i == 0) div += i;
        i++;
    }
    return div;
}
int amicablePair(int n, int m){ //La función confirma si la suma de los divisores del par introducido es igual al otro número, formando un "par amigable"
    return ((divSum(n) == m) && (divSum(m) == n));
}
