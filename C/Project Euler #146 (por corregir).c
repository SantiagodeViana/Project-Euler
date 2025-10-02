#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /* Solución para el problema #146 de Project Euler
  * "¿Cuál es la suma de todos los números enteros n menores de 150 millones?"
  * https://projecteuler.net/problem=146             
  * 
  * 315410) Respuesta: 315420
  * 927070) Respuesta: 1242490
  * 2525870) Respuesta: 3768360
  * 6760000) Respuesta: 3768360   */

#define N 150000000

int isPrime(long long int n);
int primePattern(long long int n);

int main()
{
    long long int n, respuesta = 0;
    for (n = 9; n <= N; n++){ //primePattern(n) devuelve 1 cuando n = 2, revisar
        if (primePattern(n) == 1){
            respuesta += n;
            printf("%lld) Respuesta: %lld\n", n, respuesta);
        }
        if (n % 10000 == 0) printf("%lld) Respuesta: %lld\n", n, respuesta);
        //getchar();
    }
    printf("La respuesta es %lld\n", respuesta);
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
int primePattern(long long int n){ //Comprueba si n^2 + 1, n^2 + 3, n^2 + 7, n^2 + 9, n^2 + 13, y n^2 + 27 son primos consecutivos
    int pattern = 1; //Booleano
    long long int square = n * n;
    if (isPrime(square + 1) != 1) pattern = 0;
    else if (isPrime(square + 3) != 1) pattern = 0;
    else if (isPrime(square + 7) != 1) pattern = 0;
    else if (isPrime(square + 9) != 1) pattern = 0;
    else if (isPrime(square + 13) != 1) pattern = 0;
    else if (isPrime(square + 27)  != 1) pattern = 0;
    return pattern;
}
