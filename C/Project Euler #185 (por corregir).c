#include <stdio.h>
#include <stdlib.h>

#define N 22 //N es la cantidad de guesses

void numberMind(long long int n, long long int m, long long int check, long long int wrong, int num);

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
    for (int i = 0; i < N; i++){
        printf("%d) %lld (%d correcto(s)):\n", i+1, guesses[i][0], guesses[i][1]);
        numberMind(guesses[i][0], 0, 9592605845884562, 2321386104303845, i+1); 
    }
    printf("La respuesta es \n");
    return 0;
}

void numberMind(long long int n, long long int m, long long int check, long long int wrong, int num){ //Ayuda a visualizar las coincidencias entre dos números, escribiendo sus posiciones
    if (num < 10) printf("   ");
    else printf("    "); //El parámetro num sólo se usa para facilitar la lectura del
    long long int pow = 1000000000000000;
    while (n > 0){ //Evaluando de izquierda a derecha
        //if (n/pow == wrong/pow) printf("X"); //Número equivocado
        if (n/pow == check/pow) printf("O"); //Coincidencia
        //else if (n/pow == m/pow) printf("%d", n/pow); //Coincidencia
        else printf("_");
        n %= pow;
        m %= pow;
        check %= pow;
        wrong %= pow;
        pow /= 10;
    }
    getchar();
}
