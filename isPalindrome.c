//Comprueba si un entero es pal�ndromo
//Funci�n pendiente por ser optimizada
int palindrome(long long int n){ //Long long int deber�a presentar problemas cuando es mayor a 2^18
    int i = 1, j, length = 0, digitos[20], temp = n; //i es el multiplicador de 10
    if (n < 10) return 1; //Acepta n�mero de un d�gito como pal�dromos; cambiar a conveniencia
    while (i <= n){
        i *= 10;
        length++;
    }
    i /= 10; //Se puede borrar esta l�nea?
    for (j=0; j < length/2; j++){
        if (i == 0) digitos[j] = 0;
        else digitos[j] = (temp/i); // Se va rellenando el array con los primeros n�meros
        temp %= i; //Se va acortando el n�mero de izquierda a derecha
        i/= 10;
    }
    temp = n;
    for (j = 0; j < length/2; j++){
        if ((temp % 10) != digitos[j]) return 0;
        temp /= 10; //Se va reduciendo n
    }
    return 1;
}
