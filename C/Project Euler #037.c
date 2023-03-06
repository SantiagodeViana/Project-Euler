#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);
int left(int n);
int right(int n);

////EULER 37
//Encontrar suma de números truncables palíndromos

int main()
{
    int i, j = 10, suma;
    while (i < 11){
        if ((left(j) == 1) && (right(j) == 1)){
            printf("%d\n", j);
            suma += j;
            i++;
        }
        j++;
    }
    printf("La respuesta es %d\n", suma);
    printf("Fin del programa\n");
    return 0;
}

int left(int n){ //Desde la izquierda
    int i = 1, j;
    while (i < n) i *= 10;
    while (i >= 1){
        j = n % i;
        if (isPrime(j) == 0) return 0;
        i /= 10;
    }
    if (isPrime(j) == 1) return 1;
    return 0;
}

int right(int n){ //Desde la derecha
    int i = 1, j;
    while (i < n){
        j = n / i;
        if (isPrime(j) == 0) return 0;
        i *= 10;
    }
    if (isPrime(j) == 1) return 1;
    return 0;
}

int isPrime(int n){//Función para determinar si un numero es primo.    if (n == 1) return 0;
    if (n == 1) return 0;
    else if (n < 4) return 1; //Si son menores de 4, son primos
    else if (n % 2 == 0) return 0; //Si son pares, no son primos
    else if (n < 9) return 1; //Si son menores de 9 e impares, son primos
    else if (n % 3 == 0) return 0; //Si son múltiplos de 3, no son primos
    else{ //Sierva (?) cuyo nombre no recuerdo
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
