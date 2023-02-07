//Función usada en Project Euler #59

int decimal (int n){ //Recibe un número en base binaria y la convierte a base digital
    int i, respuesta = 0, base2 = 1, base10 = 2;
    for (i=1; i<digitos(n); i++){
        base10*=2; //Se calcula la máxima potencia de 2
        if (i >= 1) base2*=10; //Se calcula el mayor dígito en numeración binaria
    }
    base10 /= 2; //Se reducen las potencias
    while (base10 != 1){
        if (n/base2 == 1) respuesta += base10; //Si el número binario coincide con la potencia respectiva, se suma el correspondiendo valor en decimalZ
        n %= base2;
        base2 /= 10;
        base10 /= 2; //Se reducen las potencias
    }
    if (n == 1) respuesta ++;
    return respuesta;
    /*
     * Aquí también la operación modular da errores
     * Probablemente debido a la división entre cero.
     */
}
