//Función mencionada en Project Euler #95
int isPerfect(int n){ 
    //Un número perfecto es aquel n cuya suma de divisores es igual a n
    int i = 1, perfect = 1, divisores = 0; //i es el contador del bucle, perfect un booleano, y divisores la suma de los divisores de n
    if (n < 6) perfect = 0; //El primer número perfecto es 6
    while (perfect == 1 || i <= (n/2)){ //Se buscan todos los divisores de n y se suman
        if (n % i == 0){
            divisores += i;
            if (divisores > n) perfect = 0; //n no es un número perfecto si la suma de los divisores excede n
        }
        i++;
    }
    return perfect;
}
