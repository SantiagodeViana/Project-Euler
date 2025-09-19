#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int digitFactorial(int n);

/* Solución para el problema #34 de Project Euler
 * https://projecteuler.net/problem=34                     */

int main()
{
    int respuesta = 0;
    for (int i = 10; i < INT_MAX; i++){ //Números de un sólo dígito no son sumas
        if (i == digitFactorial(i)){
            respuesta += i;
            printf("Respuesta: %d\n", respuesta);
        }
    }
    return 0;
}

int factorial(int n){
  if (n == 0) return 1; //Paso base
  else return (n * factorial(n-1)); //Llamada recursiva
}

int digitFactorial(int n){ //Recibiendo un n, devuelve la suma del factorial de sus dígitos
    int suma = 0;
    while (n > 0){
        suma += factorial(n%10);
        n/=10;
    }
    return suma;
}
