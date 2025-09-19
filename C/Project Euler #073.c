#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 12000

/* Solución para el problema #73 de Project Euler
 * https://projecteuler.net/problem=73                     */

int isPrime(int n);
int isCoprime(int n, int m);

int main()
{
    int respuesta = 0, num, dem;
    double aux, floor = 1.0/3.0, ceiling = 1.0/2.0; //Numerador y denominador. Floor representa la cota inferior, ceiling la superior
    isCoprime(22, 55);
    isCoprime(26, 65);
    for (dem = 1; dem <= N; dem++){
        for (num = 1; num < dem; num++){
            aux = (double)num/dem;
            if (aux < ceiling && aux > floor){
                if (isCoprime(num, dem) == 1) respuesta++; //Sólo deben considerarse fracciones reducidas
            }
        }
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
int isCoprime(int n, int m){ //Determina si un par de números son coprimos
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
        for (i=11; i <= menor; i+= 6){ //Se buscan factores primos
            if ((n%i==0 && m%i==0)) return 0; //Si los números comparten un primo como divisor, no son coprimos
            else if ((n%(i+2)==0 && m%(i+2)==0)) return 0;
        }
        return 1; //De lo contrario, sí lo son
    }
}
