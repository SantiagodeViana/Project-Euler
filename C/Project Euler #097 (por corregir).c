#include <stdio.h>
#include <stdlib.h>

////EULER 97
//Sólo probando los límites de long long
//Jamás se puede resolver el problema por fuerza bruta con estas condiciones

int main()
{
    long long i;
    while(1 != 0){
        i += 10000000000000;
        if (i % 10000000000000 == 0) printf("%llu\n", i);
    }
    return 0;
}
