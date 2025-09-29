#include <stdio.h>
#include <stdlib.h>

int combinatoria(int num, int den); //Recibe la combinatoria de dos factoriales.
//Devuelve 1 si excede un millón, devuelve 0 de lo contrario. Devuelve -1 en caso de error (den > num)

/* Solución para el problema #53 de Project Euler
 * "¿Cuántos valores, no necesariamente distintos, de (n r) para 1 <= n <= 100, son mayores que un millón?"
 * https://projecteuler.net/problem=53                                                                          */

int main()
{
    int i, j, respuesta = 0;
    for (i=23; i <= 100; i++){ //Empieza por 23
        for (j=1; j <= i; j++){
            if (combinatoria(i, j) == 1){
                respuesta++;
                printf("Respuesta:%d\n", respuesta); //La respuesta es 4075
            }
        }
    }
    printf("La respuesta es %d\n", respuesta);
    printf("Fin del programa.\n");
    return 0;
}

int combinatoria(int num, int den){
    if (den > num) return -1; //No se permiten denominadores mayores que los numeradores
    int diff = (num - den), producto = 1, i = 1, aux2 = den; //Se declara diff como (n-r), una variable para el producto y un contador que irá sumando el factorial del denominador;  aux = num
    //Se guarda una variable aux para guardar el num original
    if  (diff > den){ //Si la diferencia es mayor al denominador, cambian los roles
        den = diff;
        diff = aux2;
    }
    for ( ; num > den; num--){
        producto *= num;
        while ((producto % i == 0) && (i <= diff)){ //Cuando sea posible, se tomará parte del factorial del denominador y dividirlo arriba
            producto /= i;
            i++;
        }
        if (producto > 1000000){
            //printf("Num:%d Dem:%d", aux, den);
            //getchar();
            return 1; //Si el producto llega a ser mayor a un millón, la función se detiene y devuelve verdadero
        }
    }
    return 0;
}
