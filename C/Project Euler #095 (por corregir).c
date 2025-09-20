#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #95 de Project Euler
 * https://projecteuler.net/problem=95    */

int divSum(int n);
int amicableChain(int n);
int main() {
    int aux = 0, respuesta = 0, max = 0;
    /*for (int i = 1; i < 1000000; i++){
        aux = amicableChain(i);
        if (aux != 0){ //Evaluando cadenas no nulas
            if (aux > max){
                respuesta = i; //Se reemplaza la respuesta con la cadena más larga encontrada
                max = aux;
            }
        }
        if (i% 1000 == 0) printf("Longitud cadena %d: %3d Respuesta %d (%d)\n", i, aux, respuesta, max); //i sólo identifica al número que genera la cadena más larga
    }*/
    respuesta = amicableChain(203034); //Ejecución en dos partes: cadena más larga conseguida, evaluando término más pequeño
    printf("La respuesta es %d \n", respuesta);
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
    int tortuga, liebre, pasos = 0, longitud = 1, pow = 1; //Implementando algoritmo de Brent: hace muchas menos llamadas a funciones exigentes, ahorrando mucho tiempo
    int min = n; //Variable sólo para almacenar valor más pequeño conseguido en una cadena, pedido por el problema
    if (divSum(n) == n) return 0; //Los números "perfectos" no generan cadenas
    else{ //Se agrega condición de que ninguno de los elementos supere el millón
        tortuga = n;
        liebre = divSum(n);
        while (tortuga != liebre && liebre < 1000000){
            if (pow == longitud){
                tortuga = liebre; //Tortuga: un paso
                pow *= 2;
                longitud = 0;
            }
            liebre = divSum(liebre);
            longitud++;
        }
        if (liebre < 1000000){ //Se busca la posición de la primera repetición de la longitud
            tortuga = n;
            liebre = n;
            for (int i = 1; i <= longitud; i++) liebre = divSum(liebre); //La distancia entre la tortuga y liebre es "longitud"
            while (tortuga != liebre && liebre < 1000000){
                tortuga = divSum(tortuga);
                liebre = divSum(liebre); //Tortuga y liebre ahora a misma velocidad
                if (tortuga < min) min = tortuga;
                pasos++;
            }
            //return (pasos + longitud);
            return min;
        }
        else return 0;
    }
}
