#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);

/*    Solución para el problema #29 de Project Euler
 *    "¿Cuántos términos distintos hay en la secuencia generada por a^b para 2 ≤ a ≤ 100 y 2 ≤ b ≤ 100?"
 *    https://projecteuler.net/problem=29         
 
 *    Potencias de 2: 4*, 8, 16*, 32, 64*
 *    Potencias de 3: 9*, 27, 81*
 *    Potencias de 4: 16*, 64*
 *    Potencias de 5: 25*
 *    Potencias de 6: 36*
 *    Potencias de 7: 49*
 *    Potencias de 8: 64*
 *    Potencias de 9: 81*
 *    Potencias de 10: 100*
 */

/* PATRONES ENCONTRADOS:
 *    Después de un análisis en una tabla de excel, estos han sido los patrones encontrados:
 * 1) Imprimir todas las potencias del 1 al 10
 * 2) Deberán excluirse las potencias de los cuadrados de la mitad inferior del límite
 *    Cuadrados: 4*, 9*, 16, 25, 36, 49, 64, 81, 100
 * 3) Deberán excluirse las potencias de las potencias de la mitad inferior del límite de exponente par
 *    Potencias a considerar: 8, 27, 32
 *
 *    Respuesta obtenida errada: 9138
 *    Revisar código
 */

int main(){
    int i, j, respuesta = 0, N = 100; //Contadores 'i' y 'j' como 'a' y 'b' respectivamente, respuesta y límite N
    for (i=2; i <= N; i++){
        for (j=2; j <= N; j++){
            if (i != 4 && i != 8 && i != 9 && i != 16 && i != 25 && i != 27 && i != 32 && i != 36 && i != 49 && i != 64 && i != 81 && i != 100) respuesta++; //Se excluyen todos aquellos números que sean cuadrados de los 10 primeros números
            else if ((i == 8 || i == 27 || i == 32) && (j % 2 != 0) && (j > (N/2))) respuesta++; //En el caso de las potencias, se excluyen aquellas cuyo exponente sea par y menores a la mitad del límite
            else if ((i == 4 || i == 9 || i == 16 ||i == 25 || i == 36 || i == 49 || i == 64 || i == 81 || i == 100) && (j > (N/2))) respuesta++; //En el caso de los cuadrados, se excluyen todos aquellos cuyos exponentes sean menor al límite
        }
    }
    printf("La respuesta es %d\n", respuesta);
    printf("Fin del programa\n");
    return 0;
}

int isPrime(int n){//Función para determinar si un numero es primo, basada en la Criba de Eratóstenes
    if (n == 1) return 1;
    else if (n < 4) return 1; //Si son menores de 4, son primos
    else if (n % 2 == 0) return 0; //Si son pares, no son primos
    else if (n < 9) return 1; //Si son menores de 9 e impares, son primos
    else if (n % 3 == 0) return 0; //Si son múltiplos de 3, no son primos
    else{
        int r = floor(sqrt(n));
        int f = 5;
        while (f <= r){
            if (n % f == 0) return 0;
            else if (n % (f + 2) == 0) return 0;
            else f += 6;
        }
        return 1;
    }
}
