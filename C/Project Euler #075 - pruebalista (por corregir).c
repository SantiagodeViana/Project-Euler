#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, suma = 0, size = 0, indice = size; //Size: tamaño máximo, indice: momento actual de lista
    //int aux = 0; //Variable auxiliar para almacenar en lista
    int lista[10];
    for (i=2; i <= 5; i++){
        for (j=i; j <= 5; j++){
            suma = (i*i) + (j*j);
            if (size == 0){ //Se agrega valor si la lista está vacía
                lista[size] = (suma);
                size++;
            }
            else{
                while (indice != 0 && (suma < lista[indice-1])) indice--; //Buscar posición en la lista
                for (k=size; k>indice ;k--) lista[k+1] = lista[k];
                lista[k] = suma; //Insertando valor
                //aux = lista[k]; //Almacenando en variable auxiliar
            }
            indice = size; //Reiniciando variable de índice
        }
    }
    for (i=0; i < size; i++){
        printf("%d\n", lista[i]);
    }
    printf("Fin del programa\n");
    return 0;
}
