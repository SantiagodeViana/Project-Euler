#include <stdio.h>

/* Solución para el problema #205 de Project Euler
 * "¿Cuál es la probabilidad de que Pyramidal Pete gane a Cubic Colin? Da tu respuesta redondeada a siete decimales de la forma 0.abcdefg"
 * https://projecteuler.net/problem=205 */

int main() {
    int ladosPiramidales[8] = {1, 1, 1, 1, 1, 1, 1, 1}; // 8 elementos
    int ladosCubicos[6] = {1, 1, 1, 1, 1, 1}; // 6 elementos
    int n1 = 8; // Inicializamos n1 con el tamaño del array ladosPiramidales
    int n2 = 6; // Inicializamos n2 con el tamaño del array ladosCubicos
    double denominador = 0.0, numerador = 0.0, respuesta;
    while (ladosCubicos[0] != 6 && ladosCubicos[1] != 6 && ladosCubicos[2] != 6 && ladosCubicos[3] != 6 && ladosCubicos[4] != 6 && ladosCubicos[5] <= 6 && ladosPiramidales[0] != 4 && ladosPiramidales[1] != 4 && ladosPiramidales[2] != 4 && ladosPiramidales[3] != 4 && ladosPiramidales[4] != 4 && ladosPiramidales[5] != 4 && ladosPiramidales[6] != 4 && ladosPiramidales[7] != 4) { // Primer bucle (mueve los valores de ladosPiramidales y ladosCubicos)
        while (ladosCubicos[n2-1] > 6) { // Segundo bucle (secuencia de movimientos de ladosCubicos)
            ladosCubicos[n2-1] = 1;
            n2--;
            ladosCubicos[n2-1]++;
            if (ladosCubicos[n2-1] <= 6) n2 = 6;
            denominador++;
        }
        
        for (int i = 0; i < 8; i++) ladosPiramidales[i] = 1; // Re-inicialización de ladosPiramidales para la siguiente iteración

        printf("%d%d%d%d%d%d%d%d   %d%d%d%d%d%d   %.7f   %.7f   %.7f\n", ladosPiramidales[0], ladosPiramidales[1], ladosPiramidales[2], ladosPiramidales[3], ladosPiramidales[4], ladosPiramidales[5], ladosPiramidales[6], ladosPiramidales[7], ladosCubicos[0],  ladosCubicos[1], ladosCubicos[2], ladosCubicos[3], ladosCubicos[4], ladosCubicos[5], numerador, denominador, respuesta);
        ladosCubicos[n2-1]++; // Avance de ladosCubicos
        while (ladosPiramidales[n1-1] > 4) {
            ladosPiramidales[n1-1] = 1;
            n1--;
            ladosPiramidales[n1-1]++;
            if (ladosPiramidales[n1-1] <= 4) n1 = 8;
        }

        // Determinación del numerador
        if (ladosPiramidales[0] + ladosPiramidales[1] + ladosPiramidales[2] + ladosPiramidales[3] + ladosPiramidales[4] + ladosPiramidales[5] + ladosPiramidales[6] + ladosPiramidales[7] > ladosCubicos[0] + ladosCubicos[1] + ladosCubicos[2] + ladosCubicos[3] + ladosCubicos[4] + ladosCubicos[5]) numerador++;
        denominador++;
        respuesta = numerador / denominador;
        ladosPiramidales[n1-1]++;
    }
    
    printf("La respuesta es: %.7f\n", respuesta);
    return 0;
}
