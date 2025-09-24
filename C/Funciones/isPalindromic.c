//Función usada en Project Euler #125

int isPalindromic(long long int n){ //Función para comprobar si un entero es palíndromo
    long long int pow = 1, left, right;
    if (n < 0) return 0;
    else if (n < 10) return 1;
    while (n / pow >= 10) pow *= 10; //Midiendo n
    while (n > 0) {
        left  = n / pow;
        right = n % 10;
        if (left != right) return 0;
        //Se quitan los extremos en cada iteración
        n = (n % pow) / 10;
        pow /= 100;
    }
     return 1;
}
