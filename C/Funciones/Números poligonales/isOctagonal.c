//Función mencionada en Project Euler #61

int isOctagonal(int n){ //Comprueba si n es un número es octogonal
    int octagonal = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * (3 * i - 2);
            if (suma == n) octagonal = 1;
            else i++;
        } while (octagonal == 0 && suma < n);
    } else octagonal = 1;
    return octagonal;
}
