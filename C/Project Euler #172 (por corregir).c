#include <stdio.h>
#include <stdlib.h>

int isCandidate(long long int n);

 /* Solución del problema #172 de Project Euler
  * "¿Cuántos números de 18 dígitos (sin ceros a la izquierda) existen tal que ningún dígito se encuentre más de tres veces en n?"
  * https://projecteuler.net/problem=172
  * El programa actual tarda demasiado en conseguir la respuesta */

int main()
{
    long long int respuesta = 0;
    for (long long int i = 100011222333444555; i <= 999999999999999999; i++){ //Búsqueda en todos los números de 18 dígitos
        if (isCandidate(i) == 1) respuesta++;
        if (i % 100000000 == 0) printf("%lld) Respuesta: %lld\n", i, respuesta);
    }
    printf("La respuesta es: %lld\n", respuesta);
    return 0;
}

int isCandidate(long long int n){ //Modificando función digCount, se comprueba que n no repita ningún dígito más de 3 veces
    long long int aux; //Aux almacena n para operaciones
    int candidato = 1, d = 0, count = 0;//Candidato es un booleano, d denota el dígito evaluado, y count los cuenta
    while (d < 10 && candidato == 1){ //Mientras se evalúen dígitos o no se descarten candidatos
        aux = n;
        while (aux > 0 && count <= 3){
            if (aux % 10 == d) count++;
            aux /= 10;
        }
        if (count > 3) candidato = 0;
        d++; //Evaluando el siguiente dígito
        count = 0; //Reiniciando count
    }
    return candidato;
}
