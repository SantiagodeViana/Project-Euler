#include <stdio.h>
#include <stdlib.h> // srand(), rand()
#include <time.h>  // time()

/* Solución para el problema #493 de Project Euler
 * "Se colocan 70 bolas de colores en una urna, 10 por cada uno de los siete colores del arcoíris.
 * ¿Cuál es el número esperado de colores distintos en 20 bolas elegidas al azar?
 * Da tu respuesta con nueve dígitos después del punto decimal (a.bcdefghij)."
 * https://projecteuler.net/problem=493  */

#define N 70
#define M 20
#define O 7

int randNum(); //Devuelve un número aleatorio

int main()
{
    //urn[] contiene a las 70 pelotas, choices[] son las 20 pelotas escogidas, y colores[] son los tonos diferentes escogidos
    //int color representa los 7 colores diferentes, e int choice es la pelota específica escogida en determinado momento
    int urn[N], choices[M], colores[O], color = 1, choice;
    double aux, respuesta; //Aux contará los colores diferentes escogidos. Respuesta ofrecerá el promedio entre todas las simulaciones
    for (int i = 0; i < N; i++){ //Inicializando urn[]
        urn[i] = color;
        if ((i+1) % 10 == 0) color++; //Se "cambia" de color por cada
    }
    for (int i = 0; i < O; i++) colores[i] = -1;//Inicializando colores[]
    for (int i = 0; i < 1000000; i++){ //Creando simulación con un millón de intentos
        aux = 1;
        for (int j = 0; j < M; j++){ //Se escogen 20 pelotas
            do{
                choice = randNum();
            } while (urn[choice] == -1); //-1 representará pelotas ya escogidas
            choices[j] = urn[choice];
            urn[choice] = -1; //Se descarta pelota
            int k = 0;
            while (k < O){ //Dos escenarios:
                if (choices[j] != colores[k] || colores[0] == -1){
                    aux++; //2: Hay más de un color en el array ya, por lo que se cuenta uno nuevo
                    while (colores[k] != -1) k++; //Se busca el -1 directamente para su reemplazo y para dejar de contar pelotas nuevas
                    colores[k] = choices[j];
                    k = O;
                }
                k++;
                printf("k:%d aux:%f", k, aux);
                getchar();
            } //Si se repite el color en el array, se sale
            //printf("j:%d", j);
        }
        if (i == 0) respuesta = aux; //Asignación en el primero de los casos
        else{ //Para el resto, se calcula el promedio
            respuesta += aux;
            respuesta /=2;
        }
        for (int i = 0; i < O; i++) colores[i] = -1; //***Inicializando
        printf("i:%d Respuesta:%.9f\n", i, respuesta);
    }
    return 0;
}

    /*for (int i = 0; i < N; i++){
        printf("%3d", urn[i]);
        if ((i+1) % 10 == 0) printf("\n");
    }
    while (1 == 1){
        printf("Numero aleatorio: %d", randNum());
        getchar();
    };*/

int randNum(){
    srand(time(NULL));
    return rand() % N;
}
