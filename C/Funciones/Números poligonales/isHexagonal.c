//Función mencionada en Project Euler #61

int isHexagonal(int n){ //Comprueba si n es un número es hexagonal
    int hexagonal = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * (2 * i - 1);
            if (suma == n) hexagonal = 1;
            else i++;
        } while (hexagonal == 0 && suma < n);
    } else hexagonal = 1;
    return hexagonal;
}
