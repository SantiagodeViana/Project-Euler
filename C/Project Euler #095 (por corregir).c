#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #95 de Project Euler
 * https://projecteuler.net/problem=95    */

int divSum(int n);
int amicableChain(int n);
int main() {
    int aux = 0, respuesta = 0, max = 0;
    printf("%d\n", amicableChain(12496));
    for (int i = 1; i < 1000000; i++){
        aux = amicableChain(i);
        if (aux != 0){ //Evaluando cadenas no nulas
            if (aux > max){
                respuesta = i; //Se reemplaza la respuesta con la cadena más larga encontrada
                max = aux;
            }
        }
        printf("Longitud cadena %d: %3d Respuesta %d (%d)\n", i, aux, respuesta, max);
    }
    printf("La respuesta es %d \n", respuesta); //i sólo identifica al número que genera la cadena más larga
    return 0;
}

int divSum(int n){
    int i = 1, div = 0; //Índice y suma de divisores
    while (i <= (n/2)){
        if (n % i == 0) div += i;
        i++;
    }
    return div;
}

int amicableChain(int n){ //Devuelve la "longitud" de la cadena "amigable".
    int tortuga, liebre, pasos = 0, longitud = 1; //Función basada en el algoritmo de detección de ciclos de Floyd.
    if (divSum(n) == n) return 0; //Los números "perfectos" no generan cadenas
    else{ //Se agrega condición de que ninguno de los elementos supere el millón
        tortuga = divSum(n);
        liebre = divSum(divSum(n));
        while (tortuga != liebre && tortuga < 1000000){ //Se busca el ciclo
            tortuga = divSum(tortuga); //Tortuga: un paso
            liebre = divSum(divSum(liebre)); //Liebre: dos pasos
        }
        if (tortuga < 1000000){
            tortuga = n; //La tortuga vuelve al comienzo
            while (tortuga != liebre && tortuga < 1000000){ //Se calculan los pasos denotan antes de que empiece el ciclo
                tortuga = divSum(tortuga);
                liebre = divSum(liebre); //Tortuga y liebre ahora a misma velocidad
                pasos++;
            }
            liebre = divSum(tortuga);
            while (tortuga != liebre && tortuga < 1000000){
                liebre = divSum(liebre); //Se calcula la longitud del ciclo
                longitud++;
            }
            return (pasos + longitud);
        }
        else return 0;
    }
}
