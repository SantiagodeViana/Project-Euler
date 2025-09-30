#include <stdio.h>
#include <stdlib.h>

int isPandigital (long long int n);

 /* Solución del problema #170 de Project Euler
  * "¿Cuál es el mayor producto concatenado de 10 dígitos pandigitales del 0 al 9 de un número entero con otros dos o más números enteros,
  *  de modo que la concatenación de los números de entrada también sea un número de 10 dígitos pandigital del 0 al 9?"
  * https://projecteuler.net/problem=170                                     */

int main()
{
    printf("%d\n", isPandigital(763859124));
    printf("%d\n", isPandigital(111111111));
    printf("%d\n", isPandigital(222222222));
    printf("%d\n", isPandigital(333333333));
    printf("%d\n", isPandigital(444444444));
    printf("%d\n", isPandigital(555555555));
    printf("%d\n", isPandigital(666666666));
    printf("%d\n", isPandigital(777777777));
    printf("%d\n", isPandigital(888888888));
    printf("%d\n", isPandigital(999999999));
    return 0;
}

int isPandigital (long long int n){
    int pandigital = 1; //Variable booleana
    int aux, digito = 0; //Variable en la que se evalúa en ese momento si el dígito está en el número
    while (pandigital == 1 && digito < 10){ //El bucle termina al encontrar todos los dígitos o si hay alguno que no se encuentre
        aux = n;
        while (aux > 0){
            if (n % 10 == digito){
                digito++; //Al encontrar el dígito, se procede a buscar el siguiente...
                aux = 0; //...y se termina la búsqueda en curso
            }
            else if ((n % 10 != digito) && n < 10) pandigital = 0; //El número no es pandigital si no encuentra se encuentra el dígito en ninguna iteración
            n /= 10;
        }
    }
    return pandigital;
}
