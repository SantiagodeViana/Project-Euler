#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #78 de Project Euler
 * https://projecteuler.net/problem=78
 */

int partitions(int n);

int main()
{
    int n = 5, respuesta;
    respuesta = partitions(n);
    printf("La respuesta es %d", respuesta);
    return 0;
}

int partitions(int n){ //Devuelve el número de particiones de un n mediante un divide y vencerás. Diseñado para PE #76, #77 y #78
  int x, y;
  if (n != 1){
    x = ceil(n);
    y = floor(n);
    return (partitions(x) + partitions(y));
  }
  else return 1;
}
