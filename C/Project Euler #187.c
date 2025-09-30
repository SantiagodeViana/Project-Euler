#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);
int isSemiprime(int n);

int main()
{
    int respuesta = 0;
    for (int i = 1; i <= 100000000; i++){
        if (isSemiprime(i) == 1) respuesta++;
        if (i % 10000 == 0) printf("i: %d Respuesta: %d\n", i, respuesta);
    }
    printf("La respuesta es %d\n", respuesta);
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
int isSemiprime(int n){ //Comprueba si n es un "semiprimo": un número compuesto con exactamente dos factores primos
    int i = 2, aux = n, semiprime = 1, count = 0; //i es el divisor, semiprime variable booleana, y count registra la cantidad de factores primos
    while (i <= n/2){
        while(semiprime == 1 && (aux % i == 0) && aux > 1){
            if (isPrime(i) == 1) count++;
            aux /= i;
            if (count > 2) semiprime = 0;
        }
        i++;
    }
    if (count != 2) semiprime = 0;
    return semiprime;
}
