#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isCyclical(int n, int m);
int isTriangle(int n);
int isSquare(int n);
int isPentagonal(int n);
int isHexagonal(int n);
int isHeptagonal(int n);
int isOctagonal(int n);

int main()
{
    int respuesta, i, j, k;
    for (i = 1000; i < 10000; i++){
        for (j = 1000; j < 10000; j++){
            for (k = 1000; k < 100000; k++){
                if (isCyclical(i, j) == 1 && isCyclical(j, k) == 1 && isCyclical(k, i) == 1){
                    if ((isTriangle(i) == 1 && isSquare(j) == 1 && isPentagonal(k) == 1) || (isTriangle(j) == 1 && isSquare(k) == 1 && isPentagonal(i) == 1)
                     || (isTriangle(k) == 1 && isSquare(i) == 1 && isPentagonal(j) == 1)){ //El conjunto debe tener números de un tipo único en cada caso
                            respuesta = i + j + k;
                            printf("i:%d, j%d, k:%d   Respuesta:%d\n", i, j, k, respuesta);
                      }
                }
            }
            if (j % 1000 == 0) printf("i:%d, j%d, k:%d   Respuesta:%d\n", i, j, k, respuesta);
        }
    }
    printf("La respuesta es  %d\n", respuesta);
    return 0;
}

int isTriangle(int n){
    int triangle = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * (i + 1) / 2;
            if (suma == n) triangle = 1;
            else i++;
        } while (triangle == 0 && suma < n);
    } else triangle = 1;
    return triangle;
}
int isSquare(int n){
    int square = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * i;
            if (suma == n) square = 1;
            else i++;
        } while (square == 0 && suma < n);
    } else square = 1;
    return square;
}
int isPentagonal(int n){
    int pentagonal = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * (3 * i - 1) / 2;
            if (suma == n) pentagonal = 1;
            else i++;
        } while (pentagonal == 0 && suma < n);
    } else pentagonal = 1;
    return pentagonal;
}
int isHexagonal(int n){
    int hexagonal = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * (2 * i - 1);
            if (suma == n) hexagonal = 1;
            else i++;
        } while (hexagonal == 0 && suma < n);
    } else hexagonal = 1;
    return hexagonal;
}
int isHeptagonal(int n){
    int heptagonal = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * (5 * i - 3) / 2;
            if (suma == n) heptagonal = 1;
            else i++;
        } while (heptagonal == 0 && suma < n);
    } else heptagonal = 1;
    return heptagonal;
}
int isOctagonal(int n){
    int octagonal = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * (3 * i - 2);
            if (suma == n) octagonal = 1;
            else i++;
        } while (octagonal == 0 && suma < n);
    } else octagonal = 1;
    return octagonal;
}
int isCyclical(int n, int m){
    int cyclical = 0, powN = 1, powM = 1;
    while (powN <= n) powN *= 10; //Se mide n
    while (powM <= m) powM *= 10; //Se mide m
    if (powN == powM){ //Los números deben tener la misma longitud para ser cíclicos
        powN = sqrt(powN); //Mitad del número
        if (n % powN == m / powN) cyclical = 1; //Los números son cíclicos si la parte derecha de n es igual a la parte izquierda de m;
    }
    return cyclical;
}
