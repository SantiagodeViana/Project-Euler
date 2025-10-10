#include <stdio.h>
#include <stdlib.h>

#define N 22 //N es la cantidad de guesses

int numberMind(long long int n, long long int m, int limit);

/* Solución para el problema #185 de Project Euler
 * "Encuentra la secuencia secreta única de 16 dígitos."
 * https://projecteuler.net/problem=185                 */

int main()
{
    long long int guesses[N][2] = {{5616185650518293, 2}, {3847439647293047, 1}, {5855462940810587, 3}, {9742855507068353, 3}, {4296849643607543, 3},
    {3174248439465858, 1}, {4513559094146117, 2}, {7890971548908067, 3}, {8157356344118483, 1}, {2615250744386899, 2},
    {8690095851526254, 3}, {6375711915077050, 1}, {6913859173121360, 1}, {6442889055042768, 2}, {2321386104303845, 0},
    {2326509471271448, 2}, {5251583379644322, 2}, {1748270476758276, 3}, {4895722652190306, 1}, {3041631117224635, 3},
    {1841236454324589, 3}, {2659862637316867, 2}};
    int checks = 0, valido = 1, j;
    long long int respuesta = 9592605845884562;
    while (respuesta <= 9999999999999999 && checks < N){ //Bucle para posibles respuestas
        j = 0;
        while (j < N && valido == 1){ //Bucles para comparar con
            if (numberMind(respuesta, guesses[j][0], guesses[j][1]) == 1 && j != 14){ //Se descarta guess #15, no hay ninguna coincidencia
                checks++;
                printf("%lld - Exito: %lld", respuesta, guesses[j][0]);
            }
            else{
                valido = 0;
                printf("%lld - Fallo: %lld", respuesta, guesses[j][0]);
            }
            getchar();
            j++;
        }
        if (respuesta % 10000000 == 0) printf("Contreasena: %lld (Checks: %d)\n", respuesta, checks);
        if (checks < N){
            valido = 1;
            respuesta++;
        }
        checks = 0; //Reiniciando contador de coincidencias
    }
    printf("La respuesta es %lld\n", respuesta);
    return 0;
}

int numberMind(long long int n, long long int m, int limit){ //Comprueba la validez de n como contraseña, comparando con otras
    int valid = 1, check = 0;
    long long int aux = n;
    long long int pow = 1000000000000000, wrong = 2321386104303845;
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
