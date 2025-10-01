#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 175

/* Solución para el problema #72 de Project Euler
 * "¿Cuántos elementos hay en el conjunto de fracciones propias reducidas para d ≤ 1,000,000?"
 * https://projecteuler.net/problem=72                     */

int isPrime(int n);
int isCoprime(int n, int m, int primos[N]);
int Euclides (int n, int m); //Algoritmo de Euclides

int main()
{

    int i, j; //i numerador, j denominador
    long long int respuesta = 0;
    for (i=2; i <= 1000000; i++){ //DENOMINADOR
            for (j=1; j<i; j++) if (Euclides (j, i) == 1){ //NUMERADOR
            respuesta++;
            if (respuesta % 100000000 == 0) printf("j:%d i:%d Respuesta:%lld\n", j, i, respuesta);
        }
    }

    printf("Fin del programa\n");
    printf("La respuesta es: %lld\n", respuesta);
    return 0;
}

int isCoprime(int n, int m, int primos[N]){ //Determina si un par de números son coprimos
    int i, menor;
    if (n > m) menor = m;
    else menor = n; //Declarando menor número
    if (n == 1) return 1; //Caso ad hoc, borrar después: 1 será coprimo de todos los denominadores
    else if (n == m) return 0; //Si son iguales no son coprimos
    else if (n % 2 == 0 && m % 2 == 0) return 0; //Abreviación: Si ambos son pares, no lo son
    else if (n % 3 == 0 && m % 3 == 0) return 0; //Múltiplos de 3
    else if (n % 5 == 0 && m % 5 == 0) return 0; //Múltiplos de 5
    else if (n % 7 == 0 && m % 7 == 0) return 0; //Múltiplos de 7
    else if (n > m && n % m == 0) return 0;
    else if (n < m && m % n == 0) return 0; //Si un número es divisor del otro, no son coprimos
    else if (isPrime(n) == 1 && isPrime(m) == 1) return 1;
    else{
        for (i=4; primos[i] <= floor(sqrt(menor)); i++){ //Se buscan factores primos
            if ((n%primos[i]==0 && m%primos[i]==0)) return 0; //Si los números comparten un primo como divisor, no son coprimos
        }
        return 1; //De lo contrario, sí lo son
    }
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
int Euclides (int n, int m){ //Regresa MCD de a y b, donde 0 < b <= a
    int a = n, b = m; //De manera predeterminada se asume que n es mayor que m
    if (a == b) return a; //Si a = b, son iguales al MCD
    if ((a%2 == 0) && (b%2 ==0)) return 2; //Ad hoc: Ambos números pares, es reducible
    while ((a != 0) && (b != 0) && (a != 1) && (b != 1) && (a % b != 0)){ //Los restos se van turnando, de mayor a menor; // && (b % a != 0 &&
        if ((b != 0) && (a != 1) && (b != 1)) a = (a % b);
        if ((a != 0) && (a != 1) && (b != 1)) b = (b % a);
    }
    if (b == 0) return a; //En el caso de los pares, devolver el resto diferente de 0
    else if (a == 0) return b; //En el caso de los pares, devolver el resto diferente de 0
    else if (a < b) return a;
    else if (b < a) return b;
    return 1;
}
int isDivisor (int n, int m){
    if (n%m == 0) return 1;
    return 0;
}
*/
