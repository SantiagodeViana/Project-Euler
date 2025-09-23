#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #123 de Project Euler
 * https://projecteuler.net/problem=123    */

int isPrime(long long int n);

int main()
{
    int n = 2, respuesta = 0, r, max = 0; //n cuenta la cantidad de primos, max registra el resto máximo obtenido
    long long int i = 5, a, b, suma = 0;
    while (respuesta < 1000000000){
        if (isPrime(i) == 1){
            n++;
            a = (i - 1);
            for (int j = 1; j < n; j++) a *= (i - 1); //(pn - 1)^n, Se elevan las expresiones las veces necesarias
            b = (i + 1);
            for (int j = 1; j < n; j++) b *= (i + 1); // (pn + 1)^n
            suma = a + b;
            r = suma % (i * i);
            if (r > max){ //(pn - 1)^n + (pn + 1)^n % pn^2
                max = r; //Almacenando resto màximo
                respuesta = n;
                printf("Respuesta %d (%lld = %d)\n", respuesta, i, max);
            }
        }
        i++;
    }
    printf("La respuesta es %d\n", respuesta);
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
