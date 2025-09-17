#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #205 de Project Euler
 * "¿Cuál es la probabilidad de que Pyramidal Pete gane a Cubic Colin? Da tu respuesta redondeada a siete decimales de la forma 0.abcdefg"
 * https://projecteuler.net/problem=205 */

#define N1 9
#define N2 6

int main() {
    int i = N1 - 1, j = N2 - 1; // Inicialización de índices
    int sumaP = 0, sumaC = 0, overflowP = 0, overflowC = 0; // Inicialización de resultado de dados
    int pyramidalPeter[N1] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // 9 dados de 4 lados
    int cubicColin[N2] = {1, 1, 1, 1, 1, 1}; // 6 dados de 5 lados
    double numerador = 0.0, denominador = 0.0, respuesta = 0.0;
    while (overflowP == 0){
        while (overflowC == 0){
            if (cubicColin[j] == 7){ //Distinguiendo cantidad máxima del lado de la cantidad de lados
                cubicColin[j] = 1;
                j--;
                while (cubicColin[j] == 6){
                    cubicColin[j] = 1;
                    j--; //Izquierda
                }
                cubicColin[j]++;
                while (cubicColin[j] == 6 || j < N2 - 1) j++; //Derecha
            }
            denominador++;
            for (int i2 = 0; i2 < N1; i2++) sumaP += pyramidalPeter[i2]; //Esta operación puede fusionarse con las de arriba. Revisar.
            for (int j2 = 0; j2 < N2; j2++) sumaC += cubicColin[j2]; //Esta operación puede fusionarse con las de arriba. Revisar.
            if (sumaP > sumaC) numerador++; //Se suman los casos en los que Peter le gana a Colin
            respuesta = numerador/denominador;
            cubicColin[j]++;
            if (sumaC == 36) overflowC = 1;
            if (sumaP == 36) overflowP = 1;
            sumaP = 0;
            sumaC = 0; //Reiniciando valores de sumas
        }
        printf("Peter: %d%2d%2d%2d%2d%2d%2d%2d%2d Colin: %d%2d%2d%2d%2d%2d Probabilidad: %.7f\n", pyramidalPeter[0], pyramidalPeter[1], pyramidalPeter[2], pyramidalPeter[3], pyramidalPeter[4], pyramidalPeter[5], pyramidalPeter[6], pyramidalPeter[7], pyramidalPeter[8], cubicColin[0], cubicColin[1], cubicColin[2], cubicColin[3], cubicColin[4], cubicColin[5], respuesta);
        for (int j2 = 0; j2 < N2; j2++){
            cubicColin[j2] = 1; //Reiniciando dados de Colin
            overflowC = 0;
        }
        pyramidalPeter[i]++;
        if (pyramidalPeter[i] == 5){ //Distinguiendo cantidad máxima del lado de la cantidad de lados
            pyramidalPeter[i] = 1;
            i--;
            while (pyramidalPeter[i] == 4){
                pyramidalPeter[i] = 1;
                i--; //Izquierda
            }
            pyramidalPeter[i]++;
            while (pyramidalPeter[i] == 4 || i < N1 - 1) i++; //Derecha
        }
    }

    printf("La respuesta es: %.7f\n", respuesta);
    return 0;
}
