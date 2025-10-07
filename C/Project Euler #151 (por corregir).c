#include <stdio.h>
#include <stdlib.h> // srand(), rand()
#include <time.h>  // time()

/* Solución problema #151 de Project Euler
 * "Excluyendo el primer y último lote de la semana, calcula el número esperado de veces (durante cada semana)
 * que el supervisor encuentra una sola hoja de papel en el sobre."
 * https://projecteuler.net/problem=151
 * ¿Se puede resolver recursivamente? ¿Es más eficiente? */

int main()
{
    srand(time(NULL));

    int i = 0, j = 0, A2 = 1, A3 = 1, A4 = 1, A5 = 1; //i son posibilidades encontradas, j es el resto
    int total = A2 + A3 + A4 + A5, aux; //aux almacenará la hoja escogida
    int R1 = A2, R2 = R1 + A3, R3 = R2 + A4, R4 = R3 + A5; //Definiendo "rangos" del total de hojas para permitir decisión aleatoria
    double prob = 0, respuesta = 1;

    while(1){//Repetir simulaciones indefinidamente
        for (int k = 0; k <= 14; k++){ //14 batches, excluyendo el primero y el último
            aux = (rand () % total) + 1; //Operación modular, ++ para incluir a j entre las opciones
            //Las hojas se cortan a la mitad hasta conseguir una hoja A5
            if (aux < R2){ //Rango 1, hoja A2 sacada del sobre o cortada
                A2--;
                A3 += 2;
            }
            if (aux < R3){ //Rango 2, hoja A3 sacada del sobre o cortada
                A3--;
                A4 += 2;
            }
            if (aux < R4){ //Rango 3, hoja A4 sacada del sobre o cortada
                A4--;
                A5 += 2;
            }
            if (aux >= R4){ //Rango 4, hoja A5 sacada del sobre
                if (total == 1) i++; //Posibilidad encontrada: la hoja A5 es la única en el sobre
                A5--; //A5 usada
            }
            j++; //Hojas sacadas
            total = A2 + A3 + A4 + A5; //Actualizando total de hojas
            R1 = A2, R2 = R1 + A3, R3 = R2 + A4, R4 = R3 + A5; //Actualizando rangos

        }
        prob = (double)i/j;
        i = 0, j = 0; //Reiniciando decisiones de la semana
        respuesta *= prob;
        printf("Respuesta %.12f\n", respuesta);
    }
    return 0;
}
