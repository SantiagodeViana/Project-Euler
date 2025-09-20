#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int digFact(int n);
int digFactChain(int n);

/* Solución para el problema #74 de Project Euler
 * https://projecteuler.net/problem=74                     */

int main()
{
    int respuesta = 0;
    printf("f(145): %d\n", digFactChain(145));
    printf("f(169): %d\n", digFactChain(69));
    printf("f(871): %d\n", digFactChain(871));
    printf("f(872): %d\n", digFactChain(872));
    printf("f(69): %d\n", digFactChain(69));
    printf("f(78): %d\n", digFactChain(78));
    for (int i = 10; i <= 1000000; i++){
        if (digFactChain(i) == 60){
            respuesta++;
            printf("i: %d\n", i);
        }
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}

int factorial(int n){
  if (n == 0) return 1; //Paso base
  else return (n * factorial(n-1)); //Llamada recursiva
}
int digFact(int n){ //Recibiendo un n, devuelve la suma del factorial de sus dígitos
    int suma = 0;
    while (n > 0){
        suma += factorial(n%10);
        n/=10;
    }
    return suma;
}
int digFactChain(int n){ //Devuelve la cantidad de términos no repetitivos
    int tortuga, liebre, noRep = 0; //Función basada en el algoritmo de detección de ciclos de Floyd.
    if (n == 145 || n == 40585) return 1; //digFact(n)= n cuando = 145 o 40585, no producen términos no repetitivos
    else{
        tortuga = digFact(n);
        liebre = digFact(digFact(n));
        printf("Tortuga: %d Liebre: %d\n", tortuga, liebre);
        while (tortuga != liebre){ //Se busca el ciclo
            tortuga = digFact(tortuga); //Tortuga: un paso
            liebre = digFact(digFact(liebre)); //Liebre: dos pasos
            printf("Tortuga: %d Liebre: %d", tortuga, liebre);
            getchar();
        }
        printf("Ciclo encontrado\n");
        tortuga = n; //La tortuga vuelve al comienzo
        printf("Tortuga: %d Liebre: %d\n", tortuga, liebre);
        while (tortuga != liebre){ //Se calculan los pasos denotan antes de que empiece el ciclo
            tortuga = digFact(tortuga);
            liebre = digFact(liebre); //Tortuga y liebre ahora a misma velocidad
            noRep++;
            printf("Tortuga: %d Liebre: %d Pasos: %d\n", tortuga, liebre, noRep);
        }
        return noRep;
    }
}
