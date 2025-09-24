#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 /* Solución para el problema #134 de  Project Euler
  * https://projecteuler.net/problem=134              */

int isPrime(int n);

int main()
{
    int p1 = 5, pow; //n será el número que cumpla con las condiciones
    long long int n, respuesta = 0;
    for (int p2 = 6; p2 < 1000000; p2++){ //Bucle para buscar p2
        if (isPrime(p2) == 1){
            n = p1;
            pow = 1; //Se reinicia "medidor"
            while (pow <= n) pow *= 10; //Midiendo p1
            while (n % p2 != 0) n += pow; //Se busca n divisible por p2
            respuesta += n;
            printf("p1: %d  p2: %d  n:%lld  Respuesta:%lld\n", p1, p2, n, respuesta);
            //getchar();
            p1 = p2; //Procediendo la siguiente par
        }
    }
    printf("La respuesta es %lld\n", respuesta);
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
