#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #95 de Project Euler
 * https://projecteuler.net/problem=95            */

int suma_divisores(int n) {
    int suma = 0;
    for (int divisor = 1; divisor <= n / 2; divisor++) {
        if (n % divisor == 0) {
            suma += divisor;
        }
    }
    return suma;
}

int main() {
    int suma = 0, suma2 = 0, divisor = 1, dividendo = 1, amicable1 = 0, amicable2 = 0;
    long long int respuesta = 0;

    while (dividendo <= 10000) { // Se buscan y suman los divisores de un número
        if (dividendo % divisor == 0) suma += divisor;
        divisor++;
        if (divisor > (dividendo / 2) && dividendo != suma && suma > 0) {  // Al terminar de buscar los divisores...
            amicable1 = dividendo;  // ...se buscarán números amicables
            amicable2 = suma;
            divisor = 1;
            dividendo++;
            suma = 0;
            suma2 = 0;
            while (divisor <= (amicable2 / 2)) { // Se buscan y suman los divisores de la suma de divisores
                if (amicable2 % divisor == 0) suma2 += divisor;
                divisor++;
            }
        }
        else if (divisor > (dividendo / 2)) {
            suma = 0;
            divisor = 1;
            dividendo++;
        }

        if (amicable1 == suma2) { // Si el número es amicable
            respuesta += amicable1;
            respuesta += amicable2;
            printf("Amicable1: %d   Amicable2: %d   Respuesta: %ld   Suma2: %d\n", amicable1, amicable2, respuesta, suma2);
            suma2 = 0;
            divisor = 1;
        }

        if (divisor > dividendo) {
            divisor = 1;
        }
    }

    respuesta = (respuesta - 11088) / 2 + 11088; // Ajustar el resultado para eliminar las repeticiones
    printf("La respuesta es %ld\n", respuesta);
    return 0;
}
