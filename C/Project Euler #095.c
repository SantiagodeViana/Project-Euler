#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #95 de Project Euler
 * https://projecteuler.net/problem=95    */

int divSum(int n);
int amicableChain(int n);
int main() {
    int aux = 0, respuesta = 0, max = 0;
    for (int i = 1; i < 1000000; i++){
        aux = amicableChain(i);
        if (aux != 0){ //Evaluando sólo cadenas válidas: no nulas y que terminen con el término inicial
            if (aux > max){
                respuesta = i; //Se reemplaza la respuesta con la cadena más larga encontrada
                max = aux;
            }
        }
        if (i% 1000 == 0) printf("Longitud cadena %d: %3d Respuesta %d (%d)\n", i, aux, respuesta, max); //i sólo identifica al número que genera la cadena más larga
    }
    printf("La respuesta es %d \n", respuesta); //En este problema, el término inicial también es el término más pequeño
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
    int tortuga, liebre, longitud = 1, pow = 1; //Implementando algoritmo de Brent: hace muchas menos llamadas a funciones exigentes, ahorrando mucho tiempo
    int min = n; //Variable sólo para almacenar valor más pequeño conseguido en una cadena, pedido por el problema
    if (divSum(n) == n) return 0; //Los números "perfectos" no generan cadenas
    else{ //Se agrega condición de que ninguno de los elementos supere el millón
        tortuga = n;
        liebre = divSum(n);
        while (tortuga != liebre && liebre < 1000000 && liebre != 0){ //Se descartan las cadenas que excedan el millón. Igualmente, aquellas que lleguen a 0 no son ciclos
            if (pow == longitud){
                tortuga = liebre; //Tortuga: un paso
                pow *= 2;
                longitud = 0;
            }
            liebre = divSum(liebre);
            longitud++;
        } //Se consideran sólo los ciclos que lleguen al lugar de inicio
        if (liebre < 1000000){ //Se busca la posición de la primera repetición de la longitud
            tortuga = n;
            liebre = n;
            for (int i = 1; i <= longitud; i++) liebre = divSum(liebre); //La distancia entre la tortuga y liebre es "longitud"
            if (tortuga != liebre || liebre > 1000000) return 0;
            else return longitud; //Una cadena sin pasos antes del ciclo implica que inicia en el término original, las cadenas que se buscan
        }
        else return 0;
    }
}
