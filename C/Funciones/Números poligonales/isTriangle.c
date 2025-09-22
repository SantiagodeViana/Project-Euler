//Función mencionada en Project Euler #61

int isTriangle(int n){ //Comprueba si n es un número es triangular
    int triangle = 0, i = 1, suma = i;
    if (n > 1){
        do {
            suma = i * (i + 1) / 2;
            if (suma == n) triangle = 1;
            else i++;
        } while (triangle == 0 && suma < n);
    } else triangle = 1;
    return triangle;
}
