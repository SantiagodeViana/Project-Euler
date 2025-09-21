//Función usada en Project Euler #60

int concatenate(int n, int m){ //Función para concadenar n a la izquierda de m
    int pow = 1;
    while (pow <= m) pow *= 10; //Se mide m
    return ((n * pow) + m);
}
