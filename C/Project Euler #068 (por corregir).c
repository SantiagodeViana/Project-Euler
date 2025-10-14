#include <stdio.h>
#include <stdlib.h>

#define N 6 //2RLTisJA

int main()
{
    int i = 0;
    int gon[] = {1, 1, 1, 1, 1, 1}; //Expresando gon como array unidimensional
    int s1, s2, s3; //Strings, ramas
    while (gon[N-1] < 7){
        while (gon[i] < 7 && i < N-1){
            gon[i] = 1;
            i++;
            gon[i]++;
        }
        s1 = gon[0] + gon[1] + gon[2];
        s2 = gon[5] + gon[2] + gon[4];
        s3 = gon[1] + gon[4] + gon[3];
        if (s1 == s2 && s2 == s3){
            printf("Solucion: %d, %d, %d; %d, %d, %d; %d, %d, %d;\n",
            gon[0], gon[1], gon[2], gon[5], gon[2], gon[4], gon[1] + gon[4] + gon[3]);
        }
    }

    return 0;
}
