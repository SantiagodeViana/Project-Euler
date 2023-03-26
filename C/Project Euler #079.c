#include <stdio.h>
#include <stdlib.h>

void insertar (int array[50], int n, int comienzo, int destino);

//EULER 79
//Varios problemas por solucionar: La función introducir está repitiendo números
//El código también repite dígitos en vez de moverlos; esto debería poder ser resuelto con otra función para remover
//Respuesta: 73162890

int main()
{
    int keylog[50] = {319, 680, 180, 690, 129, 620, 762, 689, 318, 368, 710, 720, 710, 629, 168, 160, 689, 716, 731, 736, 729, 316, 729, 710, 769, 290, 719, 680, 318, 389, 162, 289, 162, 718, 729, 319, 790, 890, 362, 319, 760, 316, 380, 319, 728}; //Algunos elementos repetidos del original han sido eliminados manualmente
    int i, j, k = 50, posicion = 0, temp, length = 0, respuesta[50]; //Declarando contadores, variable auxiliar "temp", variable para almacenar la longitud "length" y el array para almacenar las respuestas
    printf("EULER 79.\n");
    for (i=0; i<50; i++) respuesta[i] = -1; //Inicializando array
    for (i=0; i<50; i++){ //Bucle para recorrer keylog
        temp = keylog[i];
        for (j=50-1; j>=50-length-1; j--){ //Bucle para comprobar dígitos repetidos
            if (respuesta[j] == temp%10){
                while (respuesta[j] == temp%10) temp /= 10; //Recortar hasta que el dígito no esté repetido
                posicion = j-1;
            }
        }
        if (posicion != 0 && temp != 0){
            insertar (respuesta, temp, 50-length-1, posicion);
            length++;
        }
        posicion = 0;
        if (temp >= 100){ //El última entrada se introduce al final directamente si no hay repetidos
            for (j=length; j>=0; j--) respuesta[50-j-3-1] = respuesta[50-j-1]; //Se extiende la cadena en tres posiciones
            length += 3;
            for (j=0; j<3; j++){ //Agregan dígitos al final
                respuesta[50-j-1] = temp %10;
                temp /= 10;
            }
        }
        for (k=0; k<50; k++) if (k > 30) printf("%d", respuesta[k]); //Línea solo para imprimir y visualizar el proceso del programa
        getchar(); //El programa pide input del usuario antes de continuar visualizando
    }
    printf("Fin del programa.\n");
    return 0;
}

void insertar (int array[50], int n, int comienzo, int destino){ //Parámetros: array de destino, elemento a introducir, longitud de cadena (de derecha a izqeuierda), posición destino
    if(comienzo < destino){
        while (comienzo != destino){
            array[comienzo-1] = array[comienzo];
            comienzo++;
        }
        if (n!=0) array[destino-1] = n;
    }
}
