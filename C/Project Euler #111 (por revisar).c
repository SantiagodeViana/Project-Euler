#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n);
void PE111(int n, int d);
int digRep(int n, int d);

int main()
{
    printf("Repeticiones de 1:\n");
    printf("%d\n", digRep(1117, 1));
    printf("%d\n", digRep(1151, 1));
    printf("%d\n", digRep(1171, 1));
    printf("%d\n", digRep(1181, 1));
    printf("%d\n", digRep(1511, 1));
    printf("%d\n", digRep(1811, 1));
    printf("%d\n", digRep(2111, 1));
    printf("%d\n", digRep(4111, 1));
    printf("%d\n", digRep(8111, 1));

    //PE111(6, 1);
    return 0;
}

void PE111(int n, int d){ //Función "madre" con un solo bucle que engloba a las tres funciones del problema
    /* M(n, d) representa la cantidad máxima de dígitos repetidos para un primo de n dígitos, donde d es el dígito repetido
     * N(n, d) representa la cantidad de dichos primos
     * S(n, d) representa la suma de dichos primos */
    int functionM = 0, functionN = 0, functionS = 0, j = 1, k;
    for (int i = 1; i < n; i++) j *= 10; //Preparando índice j para bucle principal
    k = j*10; //Upper bound
    for (j ; j < k; j++){
        printf("j: %d\n", j);

        if(isPrime(j) == 1){ //Hace falta condición previa
            functionN++; //Se cuenta primo...
            functionS += j; //...y se suma al total
        }
    }
}

int isPrime(int n){ //Función para determinar si un numero es primo, basada en la Criba de Eratóstenes
    if (n == 1) return 0; //Cambiar a 1 o mantener a conveniencia del programa
    else if (n < 4) return 1; //Si son menores de 4, son primos
    else if (n % 2 == 0) return 0; //Si son pares, no son primos
    else if (n < 9) return 1; //Si son menores de 9 e impares, son primos
    else if (n % 3 == 0) return 0; //Si son múltiplos de 3, no son primos
    else{
        int r = floor(sqrt(n));
        int f = 5;
        while (f <= r){
            if (n % f == 0) return 0;
            else if (n % (f + 2) == 0) return 0;
            else f += 6;
        }
        return 1;
    }
}

int digRep(int n, int d){ //Cuenta la cantidad de dígitos repetidos en un n, donde d es el dígito repetido
    int rep = 0; //Cantidad de veces en las que d aparece
    while (n > 0){
        if (n % 10 == d) rep ++;
        n/=10;
    }
    return rep;
}
