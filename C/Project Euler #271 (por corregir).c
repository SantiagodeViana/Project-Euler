#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #1 de Project Euler
 * "Para un número positivo n, definimos S(n) como la suma de los enteros x tales que 1 < x < n y x³ ≡ 1 (mod n).
 * Cuando n = 91, existen 8 posibles valores para x, a saber: 9, 16, 22, 29, 53, 74, 79, 81.
 * Así, S(91) = 9 + 16 + 22 + 29 + 53 + 74 + 79 + 81 = 363.
 * Encuentra S(13082761331670030). 
 * https://projecteuler.net/problem=271 */

long long int euclides (long long int n, long long int m);

int main()
{
    long long int respuesta = 0;
    for(long long int i = 1; i < 91; i++){
        if (euclides(91, i*i*i) == 1){
            printf("i: %d\n", i);
            respuesta += i;
        }
    }
    printf("La respuesta es %lld\n", respuesta);
    return 0;
}

long long int euclides (long long int n, long long int m){ //Regresa MCD de a y b, donde 0 < b <= a
    int a = n, b = m; //De manera predeterminada se asume que n es mayor que m
    if (a == b) return a; //Si a = b, son iguales al MCD
    if ((a%2 == 0) && (b%2 ==0)) return 2; //Ad hoc: Ambos números pares, es reducible
    else if (n < m){ //Si n es menor que m,
        a = m;
        b = n;
    }
    while ((a != 0) && (b != 0) && (a != 1) && (b != 1) && (a % b != 0)){ //Los restos se van turnando, de mayor a menor; // && (b % a != 0 &&
        if ((b != 0) && (a != 1) && (b != 1)) a %= b;
        if ((a != 0) && (a != 1) && (b != 1)) b %= a;
    }
    if (b == 0) return a; //En el caso de los pares, devolver el resto diferente de 0
    else if (a == 0) return b; //En el caso de los pares, devolver el resto diferente de 0
    else if (a < b) return a;
    else if (b < a) return b;
    return 1;
}
