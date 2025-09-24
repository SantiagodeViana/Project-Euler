//Función para comprobar si un entero es palíndromo

int isPalindromic(long long int n){
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


