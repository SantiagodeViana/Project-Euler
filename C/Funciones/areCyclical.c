//Función usada en Project Euler #61

int areCyclical(int n, int m){ //Compara si un par de números son cíclicos
    int cyclical = 0, powN = 1, powM = 1;
    while (powN <= n) powN *= 10; //Se mide n
    while (powM <= m) powM *= 10; //Se mide m
    if (powN == powM){ //Los números deben tener la misma longitud para ser cíclicos
        powN = sqrt(powN); //Mitad del número
        if (n % powN == m / powN) cyclical = 1; //Los números son cíclicos si la parte derecha de n es igual a la parte izquierda de m;
    }
    return cyclical;
}
