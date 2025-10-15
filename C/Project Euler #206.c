#include <stdio.h>
#include <stdlib.h>

#define N 1929394959697989990 //1929394959697989990 es el mayor número posible

/* Solución para el problema #206 de Project Euler
 * "Encuentra el único número entero positivo cuyo cuadrado tenga la forma 1_2_3_4_5_6_7_8_9_0, donde cada «_» es un solo dígito.
 * https://projecteuler.net/problem=206                     */

int PE206(long long int n);

int main()

{
    long long int i = 1000000000, aux, respuesta = 0;
    while (i < 10000000000 && respuesta == 0){
        i++;
        if (i <= N/2){ //Condición para evitar overflow
            aux = i * i;
            if (PE206(aux) == 1) respuesta = aux;
            if (i % 10000000 == 0) printf("%lld^2 = %lld\n", i, aux);
        }
    }
    printf("La respuesta es %lld\n", i);
    return 0;
}

int PE206(long long int n){ //Comprueba el cuadrado específico buscado
    int check = 0; //
    while (n > 0){
        if (n % 10 != check) return 0;
        n /= 100;
        if (check == 0) check = 9;
        else check--;
    }
    return 1;
}
