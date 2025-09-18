#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #119 de Project Euler
 * https://projecteuler.net/problem=119 */

int digitSum(long long int n);
int digitPowerSum(long long int n);

int main()
{
    long long int i;
    int n = 23; //n va a ser el índice de los términos de la secuencia con la propiedad buscada
    for (i = 78200000000; n < 30; i++){ //Último número probado: 78200000000
        if (digitPowerSum(i) == 1){
            n++;
            printf("%d) %lld is a digitPowerSum\n", n, i);
        }
        if (i % 100000000 == 0) printf("i: %lld n: %d\n", i, n);
    }
    printf("\nLa respuesta es %lld", i-1);
    return 0;
}

int digitSum(long long int n){ //Función para sumar dígitos de un entero
    int suma = 0;
    while (n > 0){
        suma += n % 10;
        n/=10;
    }
    return suma;
}
int digitPowerSum(long long int n){
    int powerSum = 0, power; //powerSum es un booleano
    long long int suma;
    power = digitSum(n); //Potencia
    if (power == 1) return 0; //Se ignoran los 1
    else if (n % 2 != 0 && power % 2 == 0) return 0; //Criva para descartar factores
    else if (n % 3 != 0 && power % 9 == 0) return 0; //n % 3 siempre es igual a power % 3
    else if (n % 5 != 0 && power % 5 == 0) return 0;
    else if (n % 7 != 0 && power % 7 == 0) return 0;
    else{
        suma = power; //Resultado final
        while (suma < n){
            if (suma > n / power) break;  //Evitando casos de desbordamiento
            else suma *= power; //Se multiplica (eleva a la potencia) a la digitSum hasta determinar si es una potencia de n
        }
        if (suma == n) powerSum = 1;
    }
    return powerSum;
}
