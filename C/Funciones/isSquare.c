//Función mencionada en Project Euler #61

int isSquare(int n){ //Comprueba si n es un número es cuadrado
    int square = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * i;
            if (suma == n) square = 1;
            else i++;
        } while (square == 0 && suma < n);
    } else square = 1;
    return square;
}
