#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);

//Euler 69:
/*  El programa sólo busca el número con la mayor cadena de divisores primos
    En otras palabras, el número con la mayor cantidad de divisores
    En teoría, este es el número que tendría el menor radio de Totient
    La respuesta es 510510
*/

int main()
{
    int i, j = 0, max = 0, primos[10000];
    for (i=2; i <= 10000; i++){ //Llenando array de primos
        if (isPrime(i) == 1){
            primos[j] = i;
            j++;
        }
        //printf("%d\n", i);
    }
    for (i=2; i <= 1000000; i++){
        j = 0; //Reiniciando índice de array
        while(i % primos[j] == 0 && i >= primos[j]){
            j++;
            if (j > max){
                max = j;
                printf("i:%d Max:%d\n", i, max);
            }
        }
        //printf("%d\n", i);
    }
    printf("Fin del programa.\n");
    return 0;
}

/*
    for (i=10000000; i > 1 && isPrime(i) != 1; i--){
        if (isPrime(i) == 1) printf("PRIMO %d\n", i);
        printf("%d\n", i);
    }
*/

int isPrime(int n){ //Función para determinar si un numero es primo.
    if (n == 1) return 1; ////*Cambiar a 0 o mantener a conveniencia del programa
    else if (n < 4) return 1; //Si son menores de 4, son primos
    else if (n % 2 == 0) return 0; //Si son pares, no son primos
    else if (n < 9) return 1; //Si son menores de 9 e impares, son primos
    else if (n % 3 == 0) return 0; //Si son múltiplos de 3, no son primos
    else{ //Criva de Erastóstenes
        int root = floor(sqrt(n));
        int i = 5;
        while (i <= root){
            if (n % i == 0) return 0;
            else if (n % (i + 2) == 0) return 0;
            else i += 6; //11, 17
        }
        return 1;
    }
}
