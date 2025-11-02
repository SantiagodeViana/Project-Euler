#include <stdio.h>
#include <stdlib.h>

#define 1000000000

int isHamming (int n, int div);

int main()
{
    int respuesta = 0;
    for (int i = 0; i < N; i++){
        if (isHamming (i, 100) == 1) respuesta++;
    }
    return 0;
}

int isHamming (int n, int div){ //customización div
    int hamming = 1; //divCount
    if (n < div) return hamming;
}
