//Función usada en Project Euler #125

int isPalindromicSum(long long int n){ //Comprueba si un palíndromo n puede expresar como la suma de cuadrados
    int p = 1, aux, suma = 0, check = 0;
    if (isPalindromic(n) == 1){ //n debe ser un palíndromo
        while (p < sqrt(n) && check == 0){ //Se evalúan candidatos hasta conseguir uno o quedarse con una sola potencia
            aux = p;
            while(suma < n){ //Suma de cuadrados consecutivos
                suma += aux * aux;
                aux++;
            }
            if (suma == n) check = 1; //Condición que confirma que n es una "suma palidrómica"
            suma = 0;
            p++;
        }
    }
    return check;
}
