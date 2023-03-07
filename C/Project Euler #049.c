#include <stdio.h>
#include <stdlib.h>
#include <math.h>

////EULER 49
//Conseguir tres números de 4 digitos, primos, que compartan dígitos
/* Actualmente el código muestra los números que comparten digitos, sin límite de la cantidad
 * Por ejemplo, un número puede tener un "9" y otro dos.
 * Sin embargo, las restricciones son tales que ofrece 26 posibilidades y permite discernir manualmente
 * El ejemplo es el número 4: 1497, 4817 y 8147
 * El resultado del problema es el número 7: 2969, 6299 y 9629
 * La diferencia entre ellos también parece ser 3330
*/

int isPrime(int n);
int isPermutable (int n, int m);

//printf("%d", isPermutable (1234, 4321));

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

/*
//Código listo. No responde, confío en que depurando se puede resolver

    void insertarDigitos(int *lista, int n);
    int comprobarDigitos(int *lista, int n); //Se podría modificar la función para que reciba dos números en vez de un array
    insertarDigitos(digitos, 1234);
    comprobarDigitos(digitos, 4321); //Esta función no parece leer correctamente e array
    int digitos[5] = {-1, 1, 2, 3, 4};
    int ans1 = 0, ans2 = 0, ans3 = 0;
    for (i=1000; i < 10000; i++){
        if (isPrime(i) == 1){ //Sólo evaluar con números primos
            insertarDigitos (digitos, i);
            if (ans1 == 0) ans1 = i;
            if (comprobarDigitos(digitos, i) == 1){ //Comprobar dígitos
                if (ans2 == 0) ans2 = i;
                else if (ans3 == 0) ans3 = i;
            }
            else{ //Se reinician los valores de no coincidir
                ans1 = 0;
                ans2 = 0;
                ans3 = 0;
            }
            if (ans1 != 0 && ans2 != 0 && ans3 != 0){
                printf("Respuestas: %2d %2d %2d", ans1, ans2, ans3);
            }
        }
    }
    */

            /*
            for (j=1; j <= 4; j++){
                printf("%d\n", digitos[j]);
            }
            printf("\n");
            */

//printf("%d\n", digitos[j]);

/*{
    int i, j = 0;
    for (i=1000; i < 10000; i++){
        if (isPrime(i) == 1){
            j++;
            printf("%3d\n", i);
        }
    }
    printf("Hay %d primos\n", j);
    return 0;
}

    if (digitos[j] != 0){
        while (digitos[j] == (i % 10)){
            j++;
            printf("%d\n", j);
            if (j == 4) permut++;
            else permut = 0;
        }
        if (digitos[j] != (i % 10)) digitos[] = {-1, -1, -1, -1, -1}
        printf("\n");
    } */

