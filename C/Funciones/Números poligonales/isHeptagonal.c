//Función mencionada en Project Euler #61

int isHeptagonal(int n){ //Comprueba si n es un número es heptagonal
    int heptagonal = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * (5 * i - 3) / 2;
            if (suma == n) heptagonal = 1;
            else i++;
        } while (heptagonal == 0 && suma < n);
    } else heptagonal = 1;
    return heptagonal;
}
