#include <stdio.h>
#include <stdlib.h>

int divCount(int n);

int main()
{
    int respuesta = 0, count = divCount(2), count2 = divCount(1);
    for (int i = 1; i < 10000000; i++){
        count = divCount(i + 1);
        if (count == count2){
            respuesta++;
            printf("n: %d", i);
            getchar();
        }
        count2 = count; //Guardando cuenta previa
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}


int divCount(int n){ //Cuenta los divisores de n
    int i = 1, count = 0; //Índice y suma de divisores
    while (i <= (n/2)){
        if (n % i == 0) count++;
        i++;
    }
    return div;
}
