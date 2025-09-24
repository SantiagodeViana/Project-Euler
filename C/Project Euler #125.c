#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #125 de Project Euler
 * https://projecteuler.net/problem=125    */

int isPalindromic(long long int n);
int isPalindromicSum(long long int n);

int main()
{
    long long int i = 2, respuesta = 0;
    for (i = 2; i <= 100000000; i++){
        if (isPalindromicSum(i) == 1){
            respuesta += i;
            printf("%lld) Respuesta: %lld\n", i, respuesta);
        }
    }
    printf("La respuesta es %lld\n", respuesta);
    return 0;
}

int isPalindromic(long long int n){ //Función para comprobar si un entero es palíndromo
    long long int pow = 1, left, right;
    if (n < 0) return 0;
    else if (n < 10) return 1;
    while (n / pow >= 10) pow *= 10; //Midiendo n
    while (n > 0) {
        left  = n / pow;
        right = n % 10;
        if (left != right) return 0;
        //Se quitan los extremos en cada iteración
        n = (n % pow) / 10;
        pow /= 100;
    }
     return 1;
}
int isPalindromicSum(long long int n){
    int p = 1, aux, suma = 0, check = 0;
    if (isPalindromic(n) == 1){ //n debe ser un palíndromo
        while (p < sqrt(n) && check == 0){ //Se evalúan candidatos hasta conseguir uno o quedarse con una sola potencia
            aux = p;
            while(suma < n){ //Suma de cuadrados consecutivos
                suma += aux * aux;
                aux++;
            }
            if (suma == n) check = 1; //Condición que confirma que n es una "suma palidrómica"
            suma = 0;
            p++;
        }
    }
    return check;
}
