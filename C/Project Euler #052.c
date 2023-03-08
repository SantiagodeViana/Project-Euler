#include <stdio.h>
#include <stdlib.h>

int isPermutable(int n, int m, int length);

/* Condiciones:
 * Rango de dígitos
 * La multiplicación debe tener la misma cantidad de dígitos
*/

int main()
{
    int i, length = 7;
    for (i=100000; i<1000000; i++){ //El rango, algo arbitrario, está basado en el ejemplo: seis dígitos.
        if ((isPermutable(i, i*2, length) == 1) //Esta identación es rarísima, pero ¯\_(ツ)_/¯, funciona
        && (isPermutable(i, i*3, length) == 1)
        && (isPermutable(i, i*4, length) == 1)
        && (isPermutable(i, i*5, length) == 1)
        && (isPermutable(i, i*6, length) == 1)
        && (i*6<1000000)){
            printf("x:%d 2x:%d 3x:%d 4x:%d 5x:%d 6x:%d\n", i, i*2, i*3, i*4, i*5, i*6);
        }
    }
    printf("Fin del programa\n"); //La respuesta es 142857
    return 0;
}

int isPermutable(int n, int m, int length){ //Se guardan los digitos del número
    int i, j, cont = 1, digitos[length]; //Se declaran contadores y array; "cont" lleva la coincidencia de los digitos
    for (i=1; i <= length-1; i++){ //Se rellena el array
        digitos[i] = (n % 10);
        n /= 10;
    }
    //Se comprueba si los digitos coinciden
    for (i=1; i <= length-1; i++){ //Recorre los digitos de m
        j=1;
        while ((cont == i) && (j <= length-1)){//Recorre los digitos de n, el array; si se encuentra una coincidencia (cont++), se prosigue
            if (digitos[j] == (m % 10)) cont++;
            j++;
        }
        if (cont < i) return 0; //Si hay algún digito que no coincida, no es permutable
        else if (cont == length) return 1; //cont=5 cuando todos los digitos coinciden, permutable
        m /= 10;
        }
    return 0;
}
