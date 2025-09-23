//Función usada en Project Euler #955

int isTriangle(long long int n){ //Comprueba si n es un número es triangular
    long double i;
    i = (-1 + sqrt(1 + 8*n)) / 2; //Se despeja n y consigue la ecuación cuadrática por efectividad
    return (i == (long long int)i); //Sólo se acepta el resultado si es un entero
}
