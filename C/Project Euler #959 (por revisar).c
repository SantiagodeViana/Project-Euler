#include <stdio.h>
#include <stdlib.h> // srand(), rand()
#include <time.h>  // time()

int coinFlip();

int main()
{
    int a = 1, b = 2, aux = 0, posicion = 0, min = 0, max = 0, coin; //a son saltos hacia la izq, b hacia la derecha
    double respuesta = 0; //Aux registra la cantidad de pasos (números) únicos explorados en ese paso. Respuesta calcula el promedio.
    long long int n = 0; //n es la cantidad de pasos totales
    srand(time(NULL));
    do{
        coin = coinFlip(); //Se decide la posición a la cual moverse
        if (coin == 0) posicion -= a;
        else if (coin == 1) posicion += b;
        if (posicion > max){
            aux += abs(posicion - max);
            max = posicion;
        }
        else if (posicion < min){
            aux += abs(posicion - min);
            min = posicion;
        }
        respuesta = ((respuesta * n) + aux) / (n + 1);
        aux = 0; //Reiniciando aux
        n++;
        if (n % 5000000 == 0) printf("Pasos nuevos encontrados: %.12f\n", respuesta);
    } while (1);

    return 0;
}

int coinFlip(){
    return rand() % 2; //Devuelve una probabilidad 50/50
}
