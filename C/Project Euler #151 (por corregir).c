#include <stdio.h>
#include <stdlib.h> // srand(), rand()
#include <time.h>  // time()

/* Solución problema #151 de Project Euler
 * https://projecteuler.net/problem=151   */

int main()
{
    srand(time(NULL));

    int i = 0, j;
    double prob = 0, respuesta = 1;

    while(1){
        for (int k = 0; k <= 15; k++){
            if (rand () % 5 == 0) i++;
            j++;
            respuesta = (double)i/j;
        }
        respuesta *= prob;
        printf("Respuesta %f\n", respuesta);
    }

    printf("Hello world!\n");
    return 0;
}
