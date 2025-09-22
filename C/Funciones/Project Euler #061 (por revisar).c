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
    printf("%d\n", isCyclical(9090, 1234));
    printf("%d\n", isCyclical(2468, 1357));
    printf("%d\n", isCyclical(1111, 2222));
    printf("%d\n", isCyclical(9876, 5432));
    printf("%d\n", isCyclical(1234, 5678));
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
