#include <stdio.h>
#include <stdlib.h>

 /* Solución al problema #127 de Project Euler
  * https://projecteuler.net/problem=127 */

int isPrime(int n);
int radial(int n);  

int main()
{
    printf("Hello world!\n");
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
int radial(int n){
    int d = n, producto = 1;
    while (n > 0){
        if (isPrime(d) == 1){ //Sólo se consideran divisores primos
            while (n % d == 0) n /= d;
            producto *= d;
        }
        d--;
    }
    return producto;
}
