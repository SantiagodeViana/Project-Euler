#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #95 de Project Euler
 * https://projecteuler.net/problem=95            
 * 5916 alcanza un bucle que no regresa a n original. Hay que implementar detección para su descarte
 */

int isPrime(int n);
int amicablePair(int n, int m);
int amicableChain(long long int n, long long int ref);

int main() {
    int aux = 0, respuesta = 0;

    for (int i = 1; i < INT_MAX; i++){
        aux = amicableChain(i, -1);
        if (aux != 0){
            if (aux > respuesta) respuesta = aux;
        }
        printf("Longitud cadena %d: %d Respuesta %d\n", i, aux, respuesta);
        //getchar();
    }
    printf("La respuesta es %d \n", respuesta);
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
int amicablePair(int n, int m){ //La función confirma si la suma de los divisores del par introducido es igual al otro número, formando un "par amigable"
    int i = 1, div = 0; //Índice y suma de divisores
    int amicableN = 1, amicableM = 1; //Booleanos para confirmar si los números son "amigables" por cuenta propia
    if (n == m || n < 0 || m < 0){ //Se agrega condición para evitar números negativos
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
int amicableChain(long long int n, long long int ref){ //Devuelve la "longitud" de la cadena "amigable". Ref debe inicializarse como -1
    int i = 1, longitud = 0; //Índice, suma de divisores y longitud de cadena
    long long int div = 0;
    while (i <= (n/2)){
        if (n % i == 0) div += i;
        i++;
    }
    //Paso base: no hay ciclo. La mayoría de los números no devuelven ciclos, incluyendo a los números "perfectos"
    //El problema también excluye aquellas cadenas
    if (div == n || div == 0 || div > 1000000) return 0;
    else if (div == ref) return 1; //Pase base: ciclo encontrado. Devuelve 1 si se halla el n original
    else if (amicablePair(n, div) != 1){ //Se agrega condición para evitar pares amigables y así evitar bucles. Pendiente de considerar ternas.
        if (ref == -1) ref = n; //En caso de ser el primer paso, sse declara la variable de referencia
        //printf("Ref %lld, n: %lld, div: %lld\n", ref, n, div);
        //getchar();
        longitud = amicableChain(div, ref);
        return longitud + (longitud && 1); //Llamada recursiva: 0 si no hay ciclo, devuelve longitud + 1 en caso de continuar
    }
    else return 0;
}
