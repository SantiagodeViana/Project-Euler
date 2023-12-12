#include <stdio.h>
#include <stdlib.h>

//Arreglar. Probablemente pueda resolverse mediante backtracking.

int main()
{
    int N = 5, total = 0, respuesta = 0; //N es igual a la suma objetivo. Total es la suma actual en el array
    int enteros[N]; //Array para controlar enteros
    for (int i = 0; i < N; i++) enteros[i] = 0; //"Limpiando" array
    for (int i = N; i >= 0; i--){ //Este bucle controla el entero mayor
        while (j != N){

            if (total == N){
                printf("%5d", enteros[0]);
                printf("%5d", enteros[1]);
                printf("%5d", enteros[2]);
                printf("%5d", enteros[3]);
                printf("%5d", enteros[4]);
                printf("\n");
                respuesta++;

            }
        }

        for (int j = 0; j < N; j++){ //Este bucle controla el entero actual
            enteros[j]++;
            total++;

        }
        enteros[i]++;
        total = 0; //Reiniciando variable del total
    }

    printf("La respuesta es %d\n", respuesta);

    return 0;
}
