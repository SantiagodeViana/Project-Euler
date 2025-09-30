#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);
int isSquarefree(long long int n);

int main()
{
    int respuesta = 0;
    for (long long int = 1; i <= 50; i++){ //1125899906842624
        if (isSquarefree(i) == 1){
            respuesta++;
            printf("n: %d", i);
        }
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}

int isPrime(int n){ //Función para determinar si un numero es primo, basada en la Criba de Eratóstenes
    if (n == 1) return 0; //Cambiar a 1 o mantener a conveniencia del programa
    else if (n < 4) return 1; //Si son menores de 4, son primos
    else if (n % 2 == 0) return 0; //Si son pares, no son primos
    else if (n < 9) return 1; //Si son menores de 9 e impares, son primos
    else if (n % 3 == 0) return 0; //Si son múltiplos de 3, no son primos
    else{
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
int isSquarefree(long long int n){ //Comprueba si n es "squarefree": si es divisible por el cuadrado de un primo
    int i = 1, squarefree = 1; //Squarefree es un variable booleana
    while (i < sqrt(n) && squarefree == 1){
        if (isPrime(i) == 1){
            if (n % i*i == 0) squarefree = 0;
        }
        i++;
    }
}
