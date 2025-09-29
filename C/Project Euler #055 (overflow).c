#include <stdio.h>
#include <stdlib.h>

/* Solución para el problema #55 de Project Euler
 * "¿Cuántos números Lychrel hay por debajo de diez mil?"
 * https://projecteuler.net/problem=55            */

int isPalindrome(long long int n);
int isLychrel(long long int n);

int main()
{
    int respuesta = 0;
    for (int i = 1; i <= 10000; i++){
        if (isLychrel(i) == 1) respuesta++;
    }
    printf("La respuesta es %d\n", respuesta);
    return 0;
}

int isPalindrome(long long int n){
    int palindrome = 1, i = 0, digs = 0; //Declarando digs como contador de digs para reconocer cuando se parte n. Shift guarda el dígito que se mueve de derecha a izquierda
    long long int aux = 0, pow = 1, left, right;
    if (n >= 10){
        while (pow < n){ //Se mide n
            pow *= 10;
            digs++;
        }
        pow = 1; //Reiniciando pow
        while (i < digs/2){ //Se mide parte derecha antes de cortar
            pow *= 10;
            i++;
        }
        left = n % pow; //Se copia la parte derecha para ir copiando a la izquierda
        if (digs % 2 != 0) right = n % (pow*10); //Se considera medio de número en casos impares
        else right = n % pow; //Se recorta la derecha
        while (pow > 1 && left > 0){ //Se mueve la parte derecha a la izquierda, dígito por dígito
            while (pow > left) pow /= 10;
            aux = left / pow; //Se agarra el siguiente dígito
            while (pow < right) pow *= 10;
            right += aux * pow; //Se prepara para sumar en la izquierda
            while (pow > left) pow /= 10;
            left %= pow;
        }
        if (right != n) palindrome = 0; //Si el número es diferente después de los cambios, no es palíndromo
    }
    return palindrome;
}
int isLychrel(long long int n){ //La función evalúa si es un número Lychrel: aquel que no puede generar palíndromos al sumar su inverso sucesivamente
    int i = 1, Lychrel = 1; //Lychrel es el booleano que devuelve la función
    long long int aux, reverse, total, left = 1, right = 1;
    if (n > 10){ //Los números de un dígito no pueden generar palíndromos
        total = n;
        do{ //Do while porque hay números palíndromos que a su vez son Lychrel
            //printf("Total: %lld\n", total);
            reverse = total;
            while (reverse > left * 10) left *= 10; //Midiendo reverse
            while (left > 0){ //Bucle para revertir número
                aux += (reverse / left) * right; //Aux almacena y suma el siguiente dígito
                right *= 10;
                reverse %= left;
                left /= 10;
            };
            total += aux; //Actualizando reverso
            left = 1;
            right = 1; //Reiniciando variables
            aux = 0;
            i++;
        } while (i < 50 && (isPalindrome(total) == 0) && total < LLONG_MAX / 100);
        if (total > LLONG_MAX / 100) Lychrel = 1;
        else if (i < 50) Lychrel = 0;
    }
    return Lychrel;
}
