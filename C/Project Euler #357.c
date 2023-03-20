#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// EULER 357

int isPrime(int n);
int isPrimeGenerating(int n);

int main()
{
    int i;
    long long int suma = 0;
    printf("%d\n", isPrimeGenerating(8));
    for (i=1; i<=100000000; i++){
        if (isPrimeGenerating(i) == 1){
            suma += i;
            printf("Respuesta:%lld i:%d\n", suma, i); //La respuesta es 1739023853137
        }
    }
    printf("Fin del programa.\n");
    return 0;
}

int isPrime(int n){//Función para determinar si un numero es primo.
    if (n == 1) return 1; ////*Cambiar a 0 o mantener a conveniencia del programa
    else if (n < 4) return 1; //Si son menores de 4, son primos
    else if (n % 2 == 0) return 0; //Si son pares, no son primos
    else if (n < 9) return 1; //Si son menores de 9 e impares, son primos
    else if (n % 3 == 0) return 0; //Si son múltiplos de 3, no son primos
    else{ //Criva de Erastóstenes
        int r = floor(sqrt(n));
        int f = 5;
        while (f <= r){
            if (n % f == 0) return 0;
            else if (n % (f + 2) == 0) return 0;
            else f += 6;
        }
        return 1;
    }
}
int isPrimeGenerating(int n){ //Modelo sacado de overview de Problema 3 de Project Euler
    int i;
    if (n == 1 || n == 2) return 1; //Devuelve 1 cuando es generador dde primos
    else if (isPrime(n) == 1) return 0; //Devuelve 0 cuando no lo es
    else{
        for(i=1; i <= floor(sqrt(n)) ; i++){
            if (n % i == 0){ //Si se consigue un divisor
                if (isPrime(i + n/i) != 1) return 0;
            }
        }
    }
    return 1;
}
