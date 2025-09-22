//Función mencionada en Project Euler #61

int isPentagonal(int n){//Comprueba si n es un número es pentagonal
    int pentagonal = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * (3 * i - 1) / 2;
            if (suma == n) pentagonal = 1;
            else i++;
        } while (pentagonal == 0 && suma < n);
    } else pentagonal = 1;
    return pentagonal;
}
