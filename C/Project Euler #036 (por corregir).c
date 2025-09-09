#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #36 de Project Euler
 * "Encuentra la suma de todos los números, menores que un millón, que son palíndromos en base 10 y base 2."
 * https://projecteuler.net/problem=36            
 *
 * Devuelve como respuesta 872162, pero la respuesta es 872187, 24 más
 * El presente código excluye a los números de base 10 de un digito.
 * Considerar para futuros programas
 */

long long int binary(int n);
int palindrome(long long int n); //Trae problemas de desbordamiento para binarios
int binaryPalindrome (int n);

int main()
{
    int i, suma = 0;
    long long int binario = 0;
    for (i = 10; i <= 1000000; i++){ //Se comprueban palíndromos base 2 y base 10 menores a un millón
        binario = binary(i);
        //binaryPalindrome(11);
        if (palindrome(i) == 1){ //Si es palindromo base 10
            //printf("Base 10: %d\n", i);
            if (binaryPalindrome(i) == 1){
                suma += i;
                printf("Base 10: %d Base 2: %lld Suma: %d\n", i, binario, suma); //Si es palindromo base 2
                //printf("Base 10: %d\n", i);
            }
        }
        //printf("Base 10: %d Base 2: %lld\n", i, binario);
        //printf("i:%d %d\n", i, binary(i));
    }
    printf("Suma: %d \n", suma); //Si es palindromo base 2
    printf("La respuesta es: %lld \n", suma); //Si es palindromo base 2
    return 0;
}

long long int binary(int n){
    int i, digitos = 0, potencia = 2;
    long long int j = 1, binario = 0;
    while (potencia <= n){
        potencia *= 2;
        digitos++;
        //printf("potencia:%d digitos:%d\n", potencia, digitos);
    }
    potencia /= 2;
    for (i = 1; i <= digitos; i++){
        j *= 10;
        //printf("j:%lld\n", j);
    }
    while (potencia != 1){
        //printf("n:%d potencia:%d j:%lld binario:%lld\n", n, potencia, j, binario);
        if (n >= potencia){
            binario += j;
            n -= potencia;
        }
        if (potencia == 1) potencia++;
        potencia /= 2;
        j /= 10;
    }
    if (n == 1) binario++;
    return binario;
}
int palindrome(long long int n){ //Comprueba si es palíndromo
    int i = 1, j, length = 0, digitos[20], temp = n; //En Euler 36 no se esperan tener valores mayores de 10^6 o 2^20.
    //Long long int debería presentar problemas cuando es mayor a 2^18
    //i es multiplicador de 10
    if (n < 10) return 1;
    while (i <= n){
        i *= 10;
        length++;
    }
    i /= 10;
    for (j=0; j < length/2; j++){
        if (i == 0) digitos[j] = 0;
        else digitos[j] = (temp/i);// Se va rellenando el array con los primeros números
        //printf("primero: %d\n", (temp/i));
        temp %= i; //Se va acortando el número de izquierda a derecha
        i/= 10;
    }
    temp = n;
    for (j = 0; j < length/2; j++){
        if ((temp % 10) != digitos[j]) return 0;
        //printf("segundo: %d\n", (temp % 10));
        temp /= 10; //Se va reduciendo n
    }
    return 1;
}

int binaryPalindrome (int n){ //Creando especialmente para evitar problemas de desbordamiento
    int i, digitos = 0, potencia = 2, binario[20];
    if ((n % 2 == 0) || (n % 10 == 0)) return 0; //"There can be no leading zeros", por lo que los números pares no son palíndromos
    //Tampoco los menores a 10 ni aquellos que terminen en 0 //(n < 10) ||
    while (potencia <= n){
        potencia *= 2;
        digitos++;
        //printf("potencia:%d digitos:%d\n", potencia, digitos);
    }
    potencia /= 2;
    for (i=0; potencia != 1; i++){
        //printf("n:%d potencia:%d j:%lld binario:%lld\n", n, potencia, j, binario);
        if (n >= potencia){
            n -= potencia;
            binario[i] = 1;
        }
        else binario[i] = 0;
        potencia /= 2;
    }
    binario[i] = 1;
    for (i=0; i <= digitos/2; i++){
        if (binario[i] != binario[digitos-i]) return 0;
    }
    return 1;
}

/*
int palindrome(int n){ //Comprueba si es palíndromo; cambiando a uso de arrays
    int i = 1, digitos = 0;
    while (i < n){
        i *= 10;
        digitos++;
    }
    if (digitos == 1) return 0;
    if (digitos % 2 != 0 || (n/i == n%i)) return 1;
    if (digitos % 2 != 0 || (n/(i*10) == n%(i/10))) return 1;
    return 0;
}
    int input = -1;
    printf("Introduce un numero para determinr si es plindromo. Presiona 0 para salir.\n");
    while (input !=0){
        scanf("%d", &input);
        printf("%d\n", palindrome(100));
        printf("%d\n", palindrome(1002));
        printf("%d\n", palindrome(537));
        printf("%d\n", palindrome(735));
    }
*/
