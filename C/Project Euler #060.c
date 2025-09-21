#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Hay que arreglar la asignación de primos

int isPrime(int n);
int concatenate(int n, int m);

int main()
{
    int a = 7, b = 5, c = 3, d = 2, i = a, suma;
    int set = 0; //Set representa si un conjunto se ha encontrado o no
    while (i <= INT_MAX && set == 0){
        if (isPrime(a) == 1){ //Se comprueba constantemente la primalidad de las concadenaciones.
            printf("a:%d   b:%d  c:%d   d:%d\n", a, b, c, d);
            set = isPrime(concatenate(a, b)); //a es el primo de mayor valor
            if (set == 1) set = isPrime(concatenate(a, c));
            if (set == 1) set = isPrime(concatenate(a, d));
            if (set == 1) set = isPrime(concatenate(b, a));
            if (set == 1) set = isPrime(concatenate(b, c));
            if (set == 1) set = isPrime(concatenate(b, d));
            if (set == 1) set = isPrime(concatenate(c, a));
            if (set == 1) set = isPrime(concatenate(c, b));
            if (set == 1) set = isPrime(concatenate(c, d));
            if (set == 1) set = isPrime(concatenate(d, a));
            if (set == 1) set = isPrime(concatenate(d, b));
            if (set == 1) set = isPrime(concatenate(d, c));
            else{ //Si no se consigue un conjunto, se procede al siguiente
                d = c;
                c = b;
                b = a;
            }
        }
        a++;
    }
    printf("a:%d   b:%d  c:%d   d:%d\n", a, b, c, d);
    suma = a + b + c + d;
    printf("La respuesta es %d\n", suma);
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
int concatenate(int n, int m){ //Función para concadenar n a la izquierda de m
    int pow = 1;
    while (pow <= m) pow *= 10; //Se mide m
    return ((n * pow) + m); //Distinguiendo tamaño de entradas
}
