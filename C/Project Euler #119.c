#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #119 de Project Euler
 * El programa arroja los diferentes términos y candidatos desordenados y repetidos. Deben ordenarse manualmente.
 * https://projecteuler.net/problem=119 */

int digitSum(long long int n);

int main()
{
    int i, j, k, n = 0, suma; //n va a ser el índice de los términos de la secuencia con la propiedad buscada
    long long int aux, power;
    for (i = 2; n < 50; i++){ //Primer bucle: base
        for (j = 1; j < 63; j++){ //Segundo bucle: exponente. 2^63 es la última potencia antes que > LLONG_MAX
            power = i;
            k = 1;
            while ((power <= LLONG_MAX / i) && k < j){ //Tercer bucle: multiplicación para evitar pow y doubles
                 power *= i;
                 k++;
            }
            suma = digitSum(power);
            if (power % suma == 0 && suma != 1){
                aux = power;
                while (aux % suma == 0){
                    aux /= suma; //Se divide constantemente la potencia de manera que los únicos divisores sean el digitSum
                    if (aux == suma){ //Si se llega al final del mcm, se ha conseguido la digitPowerSum
                        printf("%lld\n", power);
                        n++; //Se suma la cantidad de digitPowerSums
                    }
                }
            }
        }

    }
    return 0;
}

int digitSum(long long int n){ //Función para sumar dígitos de un entero
    int suma = 0;
    while (n > 0){
        suma += n % 10;
        n/=10;
    }
    return suma;
}
