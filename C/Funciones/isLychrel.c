//Función usada en Project Euler #55

int isLychrel(long long int n){ //La función evalúa si es un número Lychrel: aquel que no puede generar palíndromos al sumar su inverso sucesivamente
    int i = 1, Lychrel = 1; //Lychrel es el booleano que devuelve la función
    long long int aux, reverse, total, left = 1, right = 1;
    if (n > 10){ //Los números de un dígito no pueden generar palíndromos
        total = n;
        do{ //Do while porque hay números palíndromos que a su vez son Lychrel
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
