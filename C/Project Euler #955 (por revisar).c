#include <stdio.h>
#include <math.h>

int isTriangle(long long int n);

int main()
{
    int i = 0, t = 1; //t cuenta números triangulares
    long long int an = 4, am = 3, aux; //an registra término actual, am registra término previo
    while (t < 70){
        aux = an; //Se guarda valor actual
        if (isTriangle(an) == 1){
            t++;
            printf("%d) %lld\n", t, an);
            an++; //an + 1
        }
        else an = ((2*an) - am + 1); //2an - 2n-1 + 1
        am = aux; //Se actualiza el valor previo
        i++;
    }

    return 0;
}

int isTriangle(long long int n){ //Comprueba si n es un número es triangular
    long double i;
    i = (-1 + sqrt(1 + 8*n)) / 2;
    return (i == (long long int)i);
}
