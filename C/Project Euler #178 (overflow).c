#include <stdio.h>
#include <stdlib.h>

int isStepNumber(long long int n);

 /* Solución para el problema #178 de Project Euler
  * "¿Cuántos números pandigitales menores que 10^40 hay? 
  * https://projecteuler.net/problem=178       */

int main()
{
    int respuesta = 0;
    for (int i = 1; i <= 10000000000000000000000000000000000000000; i++){
        if (isStepNumber(i) == 1){
            respuesta++;
            printf("i: %d\n", i);
        }
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}

int isStepNumber(long long int n){//Comprueba si n es un "step number", donde todos los dígitos consecutivos tienen una diferencia de uno entre sí mismos
    int step = 1, aux; //Step es una variable booleana. Aux almacena el dígito anterior
    if (n < 10) step = 0; //Se declarán los n de un sólo dígito como
    else{
        aux = n % 10;
        n /= 10;
        while (step == 1 && n > 0){
            if ((n % 10 != (aux+1) && n % 10 != (aux-1))) step = 0; //Se comprueba que haya una diferencia de uno entre los dígitos
            aux = n % 10;
            n /= 10;
        }
    }
    return step;
}
