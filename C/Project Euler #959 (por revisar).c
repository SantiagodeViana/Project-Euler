#include <stdio.h>
#include <stdlib.h> // srand(), rand()
#include <time.h>  // time()

#define N 1000000

int coinFlip();

int main()
{
    int a = 1, b = 2, aux = 0, posicion = N/2, coin; //a son saltos hacia la izq, b hacia la derecha. Aux registra la cantidad de pasos (números) únicos explorados.
    int numberLine[N]; //Representación de la "number line"
    double respuesta = 0; // Respuesta calcula el promedio.
    long long int n = 0; //n es la cantidad de pasos totales

    srand(time(NULL));

    for (int i = 0; i < N; i++) numberLine[i] = -1; //Inicializando matriz de posiciones
    do{
        coin = coinFlip(); //Se decide la posición a la cual moverse
        if (coin == 0) posicion -= a;
        else if (coin == 1) posicion += b;
        if (numberLine[posicion] == -1){ //Se marca y se cuentan las posiciones visitadas
            numberLine[posicion] = 1;
            aux = 1;
        }
        respuesta = ((respuesta * n) + aux) / (n + 1);
        n++;
        aux = 0; //Reiniciando aux
        printf("Respuesta: %.12f\n", respuesta); //if (n % 5000000 == 0)
        //getchar();
    } while (1);

    return 0;
}

int coinFlip(){
    return rand() % 2; //Devuelve una probabilidad 50/50
}
