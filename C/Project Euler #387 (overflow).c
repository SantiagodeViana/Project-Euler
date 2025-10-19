#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para Project Euler #387
 * "Encuentra la suma de los números primos fuertes y truncables a la derecha de Harshad menores que 10^14"
 * https://projecteuler.net/problem=387
 * Para i: 8004600031 Respuesta:36498117748 */

int isPrime(long long int n);
int digitSum(long long int n);
int isHarshad(long long int n);
int rightTruncatableHarshad(long long int n);
int strongHarshad(long long int n);

int main()
{
    long long int aux, i, respuesta = 0;
    for (i=101; i <= 100000000000000; i+= 2){ //El primer candidato es 181; como se buscan primos, basta con contar impares
        aux = i;
        aux /= 10;
        if (isHarshad(aux) == 1){ //Sólo se consideran candidatos que, tras ser truncados, devuelven números Harshad
            if (rightTruncatableHarshad(aux) == 1){ //Después de eso, se revisa si además también es rightTruncatable
                if (strongHarshad(aux) == 1){ //Finalmente, se revisa si aux también es un número Harshad fuerte, computacionalmente más exigente al confirmar primos
                    if (isPrime(i) == 1){ //Por último se comprueba la primalidad del número original, la operación más exigente. Sólo aquellos serán sumados a la respuesta
                        respuesta += i;
                        printf("i: %lld Respuesta:%lld\n", i, respuesta);
                    }
                }
            }
        }
    }
    return 0;
}

int isPrime(long long int n){//Función para determinar si un numero es primo.
    if (n == 1) return 1; //Cambiar a 0 o mantener a conveniencia del programa
    else if (n < 4) return 1; //Si son menores de 4, son primos
    else if (n % 2 == 0) return 0; //Si son pares, no son primos
    else if (n < 9) return 1; //Si son menores de 9 e impares, son primos
    else if (n % 3 == 0) return 0; //Si son múltiplos de 3, no son primos
    else{ //Criba de Eratóstenes
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
int digitSum(long long int n){ //Función para sumar dígitos de un entero
    int suma = 0;
    while (n > 0){
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
    int suma = digitSum(n);
    //Instrucciones ocultas redundantes para este caso
    //if (isHarshad(n)!= 1) return 0; //n debe ser Harshad en el primer lugar
    //else if (n < 10) return 0;
    if (isPrime(n/suma) == 1) return 1; //l si división de la suma de sus dígitos es un número primo
    return 0;
}
