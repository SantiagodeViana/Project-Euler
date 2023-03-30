#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Puede que el problema esté relacionado con un tipo de variable
//Revisar división, casos de división entre 0
//La respuesta del ejemplo es mayor de lo que debería hacer
//Floating point exception (core dumped)
//...Program finished with exit code 136

int isPrime(long long int n);
int digitos(long long int n);
int digitSum(long long int n);
int isHarshad(long long int n);
int rightTruncatableHarshad(long long int n);
int strongHarshad(long long int n);
int rightTruncatableStrongHarshadPrime(long long int n);

int main()
{
    //printf("%d", rightTruncatableStrongHarshadPrime(2011));
    long long int i = 0, respuesta = 0;
    for (i=1; i <= 100000; i++){
        if (rightTruncatableStrongHarshadPrime(i) == 1){
            respuesta += i;
            printf("Respuesta:%lld i:%lld\n", respuesta, i);
        }
    }
    return 0;
}

int isPrime(long long int n){//Función para determinar si un numero es primo.
    if (n == 1) return 1; ////*Cambiar a 0 o mantener a conveniencia del programa
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

int digitos(long long int n){ //Cuenta los dígitos de una cifra
    int respuesta = 0, i = 1;
    while (i <= n){
        i*=10;
        respuesta++;
    }
    return respuesta;
}

int digitSum(long long int n){ //Función para sumar sus dígitos
    int i, suma = 0;
    for (i=0; i<=digitos(n)+1;i++){
        suma += n % 10;
        n/=10;
    }
    return suma;
}

int isHarshad(long long int n){
    if (n % digitSum(n) == 0) return 1; //Si es divisible entre la suma de sus dígitos
    else return 0;
}

int rightTruncatableHarshad(long long int n){ //Desde la derecha
    int i = 1, j;
    if (n < 10) return 0;
    else{
        while (i < n){
            j = n / i;
            if (isHarshad(j) == 0) return 0; //Mientras recursivamente siempre siga dando números Harshad
            i *= 10;
        }
    }
    return 1;
}

int strongHarshad(long long int n){
    if (n % digitSum(n) != 0) return 0;
    else if (n < 10) return 0;
    else if (isPrime(n/digitSum(n)) == 1) return 1; //Si l división de la suma de sus dígitos es un número primo
    return 0;
}

int rightTruncatableStrongHarshadPrime(long long int n){
    if (isPrime(n) != 1) return 0;
    else if (n < 10) return 0; //Menores que 10 return 0?
    else{
        n /= 10;
        if (strongHarshad(n) == 1 && rightTruncatableHarshad(n) == 1) return 1;
    }
    return 0;
}
