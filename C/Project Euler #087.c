#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);

/* Solución para el problema #87 de Project Euler
 * "¿Cuántos números menores de cincuenta millones pueden expresarse como la suma de un cuadrado primo, un cubo primo y una cuarta potencia prima?"
 * https://projecteuler.net/problem=87            */

int main()
{
    int x, y, z, n, respuesta = 0;

    for (n=1; n<=50000000 ; n++){ //50000000
        for (x=2; (x*x*x*x) <= n ; x++){
            if (isPrime(x) == 1){
                for (y=2; (y*y*y) <= n ; y++){
                    if (isPrime(y) == 1){
                        for (z=2; (z*z) <= n ; z++){
                            if (isPrime(z) == 1){
                                if (((x*x*x*x) + (y*y*y) + (z*z)) == n){
                                    respuesta++;
                                    printf("n:%d, Respuesta:%d (x:%d y:%d z:%d)\n", n, respuesta, x, y, z);
                                }
                            }
                        }
                    }
                }
            }
        }
        if (n % 1000000 == 0) printf("n:%d, Respuesta:%d\n", n, respuesta);
    }
    printf("\nLa respuesta es:%d\n", respuesta);
    printf("Fin del programa\n");
    return 0;
}

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
