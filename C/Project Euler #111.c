#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #111 de Project Euler
 * "Encuentra la suma de todos los S(10, d)."
 * https://projecteuler.net/problem=111            */

int isPrime(long long int n);
long long int PE111(int n, int d);
int digRep(long long int n, int d);

int main()
{
    long long int respuesta = 0;
    for (int i = 0; i < 10; i++) respuesta += PE111(10, i);
    printf("La respuesta es %lld", respuesta);
    return 0;
}

/* Función "madre" con un solo bucle que engloba a las tres funciones del problema
 * M(n, d) representa la cantidad máxima de dígitos repetidos para un primo de n dígitos, donde d es el dígito repetido
 * N(n, d) representa la cantidad de dichos primos
 * S(n, d) representa la suma de dichos primos */

long long int PE111(int n, int d){ //Devuelve S(n, d), como es el output que piden en el problema
    int functionM = 1, functionN = 0, aux = 0; //
    long long int j = 1, k, functionS = 0;
    for (int i = 1; i < n; i++) j *= 10; //Preparando índice j para bucle principal
    k = j*10; //Upper bound
    j++;
    for (j ; j < k; j+=2){ //Primer bucle para calcular M(n, d). Se cuentan los impares porque sólo se están buscando primos.
        aux = digRep(j, d);
        if (aux > functionM){
            if(isPrime(j) == 1) functionM = aux; //Sólo se considera el máximo de dígitos de primos
        }
    }
    j = 1;
    for (int i = 1; i < n; i++) j *= 10; //Reiniciando j
    j++;
    for (j ; j < k; j+=2){ //Segundo bucle para calcular N(n, d) y S(n, d)
        if (digRep(j, d) == functionM){
            if(isPrime(j) == 1){
                functionN++; //Se cuenta primo...
                functionS += j; //...y se suma al total
            }
        }
    }
    printf("P(%d, %d):\n", n, d);
    printf("    M(%d, %d): %d\n", n, d, functionM);
    printf("    N(%d, %d): %d\n", n, d, functionN);
    printf("    S(%d, %d): %lld\n", n, d, functionS);
    return functionS;
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
int digRep(long long int n, int d){ //Cuenta la cantidad de dígitos repetidos en un n, donde d es el dígito repetido
    int rep = 0; //Cantidad de veces en las que d aparece
    while (n > 0){
        if (n % 10 == d) rep ++;
        n/=10;
    }
    return rep;
}
