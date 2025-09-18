//Función usada en Project Euler #119

#include <stdio.h>
#include <stdlib.h>

long long int digitPowerSum(long long int n){
    int powerSum = 0, power; //powerSum es un booleano
    long long int suma;
    power = digitSum(n); //Potencia
    if (n % 2 != 0 && power % 2 == 0) return 0; //Criva para descartar factores
    else if (n % 3 != 0 && power % 3 == 0) return 0;
    else if (n % 5 != 0 && power % 5 == 0) return 0;
    else if (n % 7 != 0 && power % 7 == 0) return 0;
    else{
        suma = power; //Resultado final
        while (suma < n && power != 1){
            if (suma > n / power) break;  //Evitando casos de desbordamiento
            else suma *= power; //Se multiplica (eleva a la potencia) a la digitSum hasta determinar si es una potencia de n. Se ignoran los 1
        }
        if (suma == n) powerSum = 1;
    }
    return powerSum;
}
