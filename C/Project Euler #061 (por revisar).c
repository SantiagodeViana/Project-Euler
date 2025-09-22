#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int areCyclical(int n, int m, int o);

int main()
{
    int respuesta, x3, x4, x5, i, j, k; //Respuesta, tipos de números e índices
    for (i = 1; i < 150; i++){
        x3 = i * (i + 1) / 2; //Triangular
        for (j = 1; j < 100; j++){
            x4 = j * j; //Cuadrado
            for (k = 1; k < 100; k++){
                x5 = k * (3 * k - 1) / 2; //Pentagonal
                if (areCyclical(x3, x5, x4) == 1){ //Se consideran todos los ciclos posibles
                    respuesta = x3 + x4 + x5;
                    printf("i:%d, j%d, k:%d   Respuesta:%d\n", x3, x4, x5, respuesta);
                }
            }
        }
        //printf("i:%d, j%d, k:%d   Respuesta:%d\n", x3, x4, x5, respuesta);
    }
    printf("La respuesta es  %d\n", respuesta);
    return 0;
}
int areCyclical(int n, int m, int o, int p, int q, int r){
    int cyclical = 0, powN = 1, powM = 1, powO = 1;
    while (powN <= n) powN *= 10; //Se mide n
    while (powM <= m) powM *= 10; //Se mide m
    while (powO <= o) powO *= 10; //Se mide o
    while (powP <= P) powP *= 10; //Se mide p
    while (powQ <= q) powQ *= 10; //Se mide q
    while (powR <= r) powR *= 10; //Se mide r
    if (powN == powM && powM == powO && powO == powP && powP == powQ && powQ == powR){ //Los números deben tener la misma longitud para ser cíclicos
        if (powN != 10 && powM != 10 && powO != 10 && powP != 10 && powQ != 10 && powR != 10){ //Los números de un solo dígito no son cíclicos
            powN = sqrt(powN); //Mitad del número
            cyclical = (n % powN == m / powN) && (m % powN == o / powN) && (o % powN == p / powN) && (p % powN == q / powN) && (q % powN == r / powN) && (r % powN == n / powN); //Los números son cíclicos si la parte derecha de n es igual a la parte izquierda de m;
        }
    }
    return cyclical;
}
