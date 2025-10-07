#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int squareSum(long long int n);

 /* Solución del problema #171 de Project Euler
  * "Encuentra los últimos nueve dígitos de la suma de todos los n, 0 < n < 10^20, tales que f(n) sea un cuadrado perfecto.
  * https://projecteuler.net/problem=171                   */

int main()
{
    long long int i, square = 0, respuesta = 0;
    for (i = 1; i <= 1000000; i++){
        square = squareSum(i);
        if (sqrt(square) == (int)sqrt(square)){ //Comprueba cuadrados perfectos: aquellos cuya raíz sean enteros
            respuesta += square;
            printf("%lld\n", square);
        }
    }
    printf("La respuesta es %lld\n", respuesta);
    return 0;
}

long long int squareSum(long long int n){ //Devuelve suma del cuadrado de los dígitos de n
    long long int suma = 0;
    while (n > 0){
        suma += (n % 10)*(n % 10);
        n /= 10;
    }
    return suma;
}
