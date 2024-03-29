#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isPrime(int n);
int isCoprime(int n, int m);
int Euclides (int n, int m);
int Totient(int n);
int numeros(int n);
int isPermutable(int n, int m, int length);

// EULER 70
/* 15/12/2020:

 * Phi de un número primo n es n-1, ya que ningún número es divisible por él salvo sí mismo.
 * Sabiendo esto, en su momento se intentó comprobar si los números primos y su phi eran permutables, sin éxito
 * Se intentó lo mismo con una variación: los cuadrados de primos

 * 22/2/2021:
 Se reemplazó la función isCoprime por el Algoritmo de Euclides, el cual debería hacer la función de Totient mucho más eficiente
 Hay que revisar resultados de la prueba con los cuadrados de los primos.

*/

int main()
{
    int i, phi; //j, k, diferencia = 1, 220000, respuesta = 1000000,   , limite = 210000, desgaste = 0
    //for (i=10000000; (i>=1 && (isPrime(i) != 1)); i--);
    //printf("%f\n", floor(sqrt(9999991)));
    //printf("%d\n", isPrime(3163));
    //for (i=1; i<=1000000; i++){
    //for (i=25   0000; i>=1; i--){
    //if ((i%2 != 0) && (i%3 != 0) && (i%5 != 0) && (i%7 != 0) && (i%11 != 0) && (i%13 != 0) && (i%17 != 0) && (i%19 != 0)){ //Se descartan múltiplos de primeros primos para ahorrar cálculos
    //ratio = (float) (phi/i);
    //for (i=1; i<=1000000; i++){
    //if (phi != -1){ //&& phi < respuesta
    //if ((desgaste %5 == 0) && (desgaste<500000)) limite--; //El limite se reduce por una unidad por cada 5 unidades que el numerador se reduzca

    /* *****************************
    La respuesta se visualiza
    */
 
    FILE *save;
    save = fopen ("C:\\Users\\santiago.viana\\Desktopsave.txt", "a");
    for (i=0; i>=1; i--){ //Primera permutación par: 992416, , desgaste++
        if (i%2 == 0){ //Corigiendo: el radio debe ser el menor posible; descartando otros posibles divisores; && i%3 != 0 && i%5 != 0 && i%7 != 0 && i%11 != 0
            phi = Totient(i);
            if (isPermutable(i, phi, numeros(i)) == 1){
                printf("i:%d phi:%d\n", i, phi);
                fprintf(save, "i:%d phi:%d\n", i, phi);
            }
        }
        if (i%10000 == 0) printf("i:%d\n", i);
    }
    /*
        for (i=1000000; i>=1; i--){ //Primera permutación par: 992416
        if (isPrime(i) == 1){
            printf("i:%d\n", i);
            //getchar();
        }
        //("i:%d\n", i); // \n
    }
    */

    //
    //if (isPrime(i) == 1){
    //respuesta = phi;
    //}
    //printf("i:%d phi:%d", i, Totient(i));
    //getchar();
    //if (i%100000 == 0) printf("i:%d\n", i);
    //if (i%1000 == 0) printf("i:%d\n", i);

    printf("Fin del programa.\n");
    return 0;
}

int isPrime(int n){//Función para determinar si un numero es primo.
    if (n == 1) return 1; ////*Cambiar a 0 o mantener a conveniencia del programa
    else if (n < 4) return 1; //Si son menores de 4, son primos
    else if (n % 2 == 0) return 0; //Si son pares, no son primos
    else if (n < 9) return 1; //Si son menores de 9 e impares, son primos
    else if (n % 3 == 0) return 0; //Si son múltiplos de 3, no son primos
    else{ //Criva de Erastóstenes
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
int isCoprime(int n, int m){ //Determina si un par de números son coprimos
    int i, menor;
    if (n > m) menor = m;
    else menor = n; //Declarando menor número
    if (n == 1) return 1; //Caso ad hoc, borrar después: 1 será coprimo de todos los denominadores
    else if (n % 2 == 0 && m % 2 == 0) return 0; //Abreviación: Si ambos son pares, no lo son
    else if (n % 3 == 0 && m % 3 == 0) return 0; //Múltiplos de 3
    else if (n % 5 == 0 && m % 5 == 0) return 0; //Múltiplos de 5
    else if (n % 7 == 0 && m % 7 == 0) return 0; //Múltiplos de 7
    else if (n > m && n % m == 0) return 0;
    else if (n < m && m % n == 0) return 0; //Si un número es divisor del otro, no son coprimos
    else if (isPrime(n) == 1 && isPrime(m) == 1) return 1;
    else{
        for (i=2; i <= menor; i++){
            if ((isPrime(i) == 1) && (n%i==0 && m%i==0)) return 0; //Si los números comparten un primo como divisor, no son coprimos
        }
        return 1; //De lo contrario, sí lo son
    }
}
int Totient(int n){ //Calcula la función phi de una función (números no divisibles
    int i, respuesta = 0;
    if (isPrime(n) == 1) return (n - 1);
    else{
        for (i=1; i<n ;i++){
            if (Euclides(n, i) == 1) respuesta++; //Versión más eficiente con Algoritmo de Euclides en vez de función "isCoprime"
            //if (respuesta > limite) return -1; //Se agreg condicional ad hoc: se dejarán de buscar aquellos coeficientes que sobrepasen el límite
        }
    }
    //if (i % 100 == 0) printf("%d\n", i);
    return respuesta;
}
int Euclides (int n, int m){ //Regresa MCD de a y b, donde 0 < b <= a
    int a = n, b = m; //De manera predeterminada se asume que n es mayor que m
    if (a == b) return a; //Si a = b, son iguales al MCD
    //if (a < 0) a *= (-1); //Si a es negativo, se convierte en positivo
    //if (b < 0) a *= (-1); //Si b es negativo, se convierte en positivo
    if ((a%2 == 0) && (b%2 == 0)) return 2; //Ad hoc: Si ambos son pares, es diferente de 1
    else if (n < m){ //Si n es menor que m,
        a = m;
        b = n;
    }
    while ((a != 0) && (b != 0) && (a != 1) && (b != 1) && (a % b != 0)){ //Los restos se van turnando, de mayor a menor; // && (b % a != 0 &&
        if ((b != 0) && (a != 1) && (b != 1)) a = (a % b);
        if ((a != 0) && (a != 1) && (b != 1)) b = (b % a);
    }
    if (b == 0) return a; //En el caso de los pares, devolver el resto diferente de 0
    else if (a == 0) return b; //En el caso de los pares, devolver el resto diferente de 0
    else if (a < b) return a;
    else if (b < a) return b;
    return 1;
}
int numeros(int n){
    int respuesta = 0, i = 1;
    while (i <= n){
        i*=10;
        respuesta++;
    }
    return respuesta;
}
int isPermutable(int n, int m, int length){ //Se guardan los digitos del número
    int i, j, cont = 0, cont2 = 0, temp = -1, temp2 = -1, digitos[length]; //Se declaran contadores y array; "cont" lleva la coincidencia de los digitos
    if (numeros(n) != numeros(m)) return 0;
    if (n == m) return 0;
    for (i=0; i <= length-1; i++){ //Se rellena el array
        digitos[i] = (n % 10);
        n /= 10;
    }
    //Se comprueba si los digitos coinciden
    for (i=0; i <= length-1; i++){ //Recorre los digitos de m
        temp = digitos[i];
        temp2 = m;
        for (j=0; j <= length-1; j++){ //Bucle para determinar dígito y contarlo
            if (digitos[j] == temp) cont++;
        }
        while(temp2 != 0){ //Se comparan las cifras
            if (temp2%10 == temp) cont2++;
            temp2 /= 10;
        }
        if (cont != cont2) return 0;
        cont = 0; //Se reinicia el contador de dígitos
        cont2 = 0;
    }
    return 1;
}

    /*

    for (i=8113602; i>=1; i--){ //Primera permutación par: 992416, , desgaste++    ; i=1000000, 567873
    //99000000, 9500000, 9350000, 9345000, 9250000
        if (i%2 == 0){ //Corigiendo: el radio debe ser el menor posible; descartando otros posibles divisores; && i%3 != 0 && i%5 != 0 && i%7 != 0 && i%11 != 0
            phi = Totient(i);
            if (isPermutable(i, phi, numeros(i)) == 1) printf("i:%d phi:%d\n", i, phi);
        }
        if (i%10000 == 0) printf("i:%d\n", i);
    }

    for (i=3162; i>=1; i--){ //3162^3162 es el mayor factor primo menor que 10^7
        if (isPrime(i) == 1){
            diferencia++; //Se resta a la función phi la cantidad de factores primos que hayan
            printf("Primo:%d\n", i);
            for (j=10000000; j>=1; j--){ //Este bucle es una función Totient a la inversa: Va descartando los factores de los números después de los primos
                 if (j % i == 0){
                    for (k=2; (k<=i && j%k !=0) ; k++);
                    if (k == i && isPermutable(j, j-diferencia, numeros(j)) == 1){
                        printf("j:%d phi:%d Primo:%d", j, j-diferencia, i);
                        getchar();
                    }
                }
            }
        }
    }

    for (i=3162; i>=1; i--){ //3162^3162 es el mayor factor primo menor que 10^7
        if (isPrime(i) == 1){
            //diferencia += 2; //Se resta a la función phi la cantidad de factores primos que hayan
            printf("Primo:%d\n", i);
            if (isPermutable(i*i, i-2, numeros(i)) == 1){
                printf("i:%d phi:%d\n", i*i, i*i-2);
                getchar();
            }
        }
    }

    for (j=1; j<=10000000; j++){
    if (isPrime(i) == 1){
        if (isPermutable(i, j , numeros(i)) == 1) printf("i:%d j:%d\n", i, j);
        //if (isPermutable(i, Totient(i) , numeros(i)) == 1) printf("i:%d phi:%d\n", i, i-1);
        //if (isPermutable(i, Totient(i), numeros(i)) == 1) printf("i:%d phi:%d\n", i, i-1);
    }

    for (i=10000000; j<=1500; i--){
    if (isPrime(i) == 1){
        printf("i:%d j:%d\n", i, j);
        primos[j] = i;
        j++;
    }

    printf("i:%d phi:%d\n", 21, Totient(21));
    printf("i:%d phi:%d\n", 63, Totient(63));
    printf("i:%d phi:%d\n", 291, Totient(291));
    printf("i:%d phi:%d\n", 502, Totient(502));
    printf("i:%d phi:%d\n", 2518, Totient(2518));
    printf("i:%d phi:%d\n", 2817, Totient(2817));
    printf("i:%d phi:%d\n", 2991, Totient(2991));
    printf("i:%d phi:%d\n", 4435, Totient(4435));
    printf("i:%d phi:%d\n", 5229, Totient(5229));
    printf("i:%d phi:%d\n", 5367, Totient(5367));
    printf("i:%d phi:%d\n", 5637, Totient(5637));
    printf("i:%d phi:%d\n", 9999991, Totient(9999991));
    printf("i:%d phi:%d\n", 9999973, Totient(9999973));
    printf("i:%d phi:%d\n", 9999971, Totient(9999971));
    printf("i:%d phi:%d\n", 9975253, Totient(9975253));
    printf("i:%d phi:%d\n", 9975223, Totient(9975223));
    printf("i:%d phi:%d\n", 9975197, Totient(9975197));
*/
