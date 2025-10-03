#include <stdio.h>
#include <stdlib.h>

int threeDigitSum(long long int n);

int main()
{
    int respuesta = 0;
    long long int n;
    for (n = 10000000000000000000; n <= 99999999999999999999; n++){
        if (threeDigitSum(n) == 1){
            respuesta++;
            printf("n: %d  Respuesta:%d\n", n, respuesta);
        }
    }
    printf("La respuesta es: %d\n", respuesta);
    return 0;
}

int threeDigitSum(long long int n){ //Comprueba que ningunos tres dígitos consecutivos superen 10
    int sum, aux = 0, aux2 = n % 10;
    while (n > 0 && sum <= 9){
        sum = (n%10) + aux + aux2;
        aux2 = aux;
        aux = n % 10;
    }
    if (sum <= 9) return 1;
    else return 0;
}
