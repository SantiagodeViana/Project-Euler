#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #49 de Project Euler
 * "¿Qué número de 12 cifras se forma concatenando los tres términos de esta secuencia?"
 * https://projecteuler.net/problem=49        */

int isPrime(int n);
int isPermutable(int n, int m);

int main(){
    int i, j, k, l=0;
    for (i=1000; i < 10000; i++){
        if (isPrime(i) == 1){ //Sólo evaluar con números primos
            for (j=i; j < 10000; j++){
                if ((isPrime(j) == 1) && (j != i)){ //Si el segundo número es primo y es diferente
                    for (k=j; k < 10000; k++){
                        if ((isPrime(k) == 1) && (k != j) && (i-j == j-k)){ //Si el tercer número es primo y es diferente
                            if ((isPermutable(i, j)) && isPermutable(j, k)){ //Imprimir aquellos resultados que sean permutables
                                l++;
                                printf("%3d, %3d, %3d, l: %3d\n", i, j, k, l); //Si es primo, diferente y concuerdan sus diferencias
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int isPrime(int n){//Función para determinar si un numero es primo.    if (n == 1) return 0;
    if (n == 1) return 0;
    else if (n < 4) return 1; //Si son menores de 4, son primos
    else if (n % 2 == 0) return 0; //Si son pares, no son primos
    else if (n < 9) return 1; //Si son menores de 9 e impares, son primos
    else if (n % 3 == 0) return 0; //Si son múltiplos de 3, no son primos
    else{ //Criba de Erastóstones
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
int isPermutable(int n, int m){ //Se guardan los digitos del número
    int i, j, cont = 1, digitos[5]; //Se declaran contadores y array; "cont" lleva la coincidencia de los digitos
    for (i=1; i <= 4; i++){ //Se rellena el array
        digitos[i] = (n % 10);
        //printf("%d\n", digitos[i]);
        n /= 10;
    }
    //Se comprueba si los digitos coinciden
    for (i=1; i <= 4; i++){ //Recorre los digitos de m
        j=1;
        while ((cont == i) && (j <= 4)){//Recorre los digitos de n, el array; si se encuentra una coincidencia (cont++), se prosigue
            if (digitos[j] == (m % 10)) cont++;
            j++;
        }
        if (cont < i) return 0; //Si hay algún digito que no coincida, no es permutable
        else if (cont == 5) return 1; //cont=5 cuando todos los digitos coinciden; permutable
        m /= 10;
        }
    return 0;
}
