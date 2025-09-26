#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /* Solución para el problema #146 de Project Euler
  * https://projecteuler.net/problem=146             */

#define N 1000000

int isPrime(long long int n);
int primePattern(int n);

int main()
{
    int n;
    long long int respuesta = 0;
    //printf("%d\n", primePattern(10));
    for (n = 1; n <= N; n++){
        if (primePattern(n) == 1){
            respuesta += n;
            printf("%d)\n", n);
        }
    }
    printf("La respuesta es %d\n", n);
    return 0;
}

int isPrime(long long int n){ //Función para determinar si un numero es primo, basada en la Criba de Eratóstenes
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
int primePattern(int n){ //Comprueba si n^2 + 1, n^2 + 3, n^2 + 7, n^2 + 9, n^2 + 13, y n^2 + 27 son primos consecutivos
    int i, pattern = 0, cons = 1; //Cons cuenta los primos consecutivos, pattern cuenta las coincidencias con la secuencia
    long long int square = n * n;
    if (isPrime(square + 1) == 1){
        i = square + 1;
        while (cons <= 5){
            if (isPrime(i) == 1){ //Se calcula si los siguientes
                switch (cons) {
                    case 1:
                        if (isPrime(square + 3) == 1) pattern++;
                        break;
                    case 2:
                        if (isPrime(square + 7) == 1) pattern++;
                        break;
                    case 3:
                        if (isPrime(square + 9) == 1) pattern++;
                        break;
                    case 4:
                        if (isPrime(square + 13) == 1) pattern++;
                        break;
                    case 5:
                        if (isPrime(square + 27)  == 1) pattern++;
                        break;
                    default:
                        break;
                }
                cons++;
            }
            i++;
        }
    }
    if (pattern == 5) return 1;
    else return 0;
}
