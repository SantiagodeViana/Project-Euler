#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #51 de Project Euler
 * "Encuentre el número primo más pequeño que, al sustituir parte del número (no necesariamente dígitos adyacentes) por el mismo dígito, 
 * forme parte de una familia de ocho valores primos."
 * https://projecteuler.net/problem=51            */

#define N 10000

int isPrime(int n);

int main()
{
    int binary = 10000, XOR = 0; //Binary sirve para representar los dígitos que se expresan o incluyen en la evaluación
    int aux, aux2, aux3, pow = 1, count = 0, max = 0, respuesta = N; //Max representa el número de primos conseguidos en una iteración específica. Respuesta es el menor primo conseguido
    int candidato = 0, reemplazo = 0; //"Candidato" consiste en los números sin los dígitos. "Reemplazo" es el número que se coloca en todos los dígitos faltantes
    //Los 1 representan los números normales, aquellos que no serán reemplazados. 0 representan las posiciones removidas para colocar un mismo número
    for (int i = 32; i < 64; i++){ //La cantidad de dígitos a evaluarse es el exponente en 2^exp del límitte del bucle (ej: 4 = 2^2 = dos dígitos
        if (binary % 2 == 0) binary++; //Contador en binario
        else binary *= 10;
        printf("La respuesta es %d (max: %d)\n", respuesta, max);
        for (int j = 10000; j <= 100000; j++){ //Segundo bucle para buscar números y candidatos primos
            //printf("Binary: %d, i:%d\n", binary, j);
            aux = j;
            aux2 = binary;
            while (aux2 > 0){ //Primero: es colocan los números
                candidato += (aux2 % 10) * (aux % 10) * pow;
                if (aux2 % 10 == 0) XOR++; //Se va calculando el XOR en casa paso
                aux2 /= 10;
                aux /= 10;
                pow *= 10;
                XOR *= 10;
            }
            if (i == 1) XOR = 10; //Contando leading zeros
            pow = 1;
            for (int k = 9; k >= 0; k--){ //Segundo: se reemplazan los dígitos por un mismo número
                aux = candidato;
                aux3 = XOR;
                while (aux3 > 0){
                    reemplazo += (aux3 % 10) * (k % 10) * pow;
                    aux3 /= 10;
                    pow *= 10;
                }
                aux += reemplazo;
                if (isPrime(aux) == 1){
                    count++;
                    if (count > max){
                        printf("%d\n", aux);
                        respuesta = aux; //aux < respuesta es implícito por el sentido del bucle
                        max = count;
                    }
                }
                reemplazo = 0;
                pow = 1;
            }
            XOR = 1;
            candidato = 0;
            count = 0;
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
