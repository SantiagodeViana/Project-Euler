#include <stdio.h>
#include <stdlib.h>

#define N 6 //N es la cantidad de guesses

int numberMind(long long int n, long long int m, int limit);

/* Solución para el problema #185 de Project Euler
 * "Encuentra la secuencia secreta única de 16 dígitos."
 * https://projecteuler.net/problem=185                 */

int main()
{
    long long int guesses[N][2] = {{90342, 2}, {70794, 0}, {39458, 2}, {34109, 1}, {51545, 2}, {12531, 1}};
    int checks = 0, valido = 1, j;
    long long int respuesta = 10000;
    while (respuesta <= 99999 && checks < N){ //Bucle para posibles respuestas
        j = 0;
        while (j < N && valido == 1){ //Bucles para comparar con
            if (numberMind(respuesta, guesses[j][0], guesses[j][1]) == 1 && j != 1) checks++; //Se descarta guess #15, no hay ninguna coincidencia
            else valido = 0;
            j++;
        }
        printf("Contresena: %lld (Checks: %d)\n", respuesta, checks);
        if (checks < N){
            checks = 0; //Reiniciando contador de coincidencias
            valido = 1;
            respuesta++;
        }
    }
    printf("La respuesta es %lld\n", respuesta);
    return 0;
}

int numberMind(long long int n, long long int m, int limit){ //Comprueba la validez de n como contraseña, comparando con otras
    int valid = 1, check = 0;
    long long int aux = n;
    long long int pow = 10000, wrong = 70794;
    while (aux > 0 && valid == 1){ //Guess #15 no tiene ningún acierto. Si hay alguna coincidencia, ya se descarta la opción
        if (aux%10 == m%10) valid = 0;
        aux /= 10;
        wrong /= 10;
    }
    if (valid == 1){
        while (n > 0 && check <= limit){ //Las coincidencias deben ser exactas para ser una contraseña válida
            if (n%10 == m%10) check++;
            n /= 10;
            m /= 10;
            pow /= 10;
        }
    }
    if (limit != check) valid = 0;
    return valid;
}
