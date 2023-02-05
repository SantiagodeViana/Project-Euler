int binary(int n){ //Función que recibe un número en base digital y la convierte en base binaria
    int i, digitos = 0, potencia = 2;
    int j = 1, binario = 0;
    while (potencia <= n){ //Se calculan los digitos del binario
        potencia *= 2;
        digitos++;
    }
    potencia /= 2; //Es posible eliminar esta línea?
    for (i = 1; i <= digitos; i++) j *= 10; //j será el sumador de los binarios
    while (potencia != 1){
        if (n >= potencia){ //Cuando el número es superior a la potencia de base 2, se resta y se procede a marcar con un 1 en esa potencia
            binario += j;
            n -= potencia;
        }
        if (potencia == 1) potencia++;
        potencia /= 2;
        j /= 10;
    }
    if (n == 1) binario++; //Se agrega un 1 al final si n es impar
    return binario;
}
