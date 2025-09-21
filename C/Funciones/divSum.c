//Función usada en Project Euler #95 y amicablePair.c

int divSum(int n){ //Función para sumar divisores de n
    int i = 1, div = 0; //Índice y suma de divisores
    while (i <= (n/2)){
        if (n % i == 0) div += i;
        i++;
    }
    return div;
}
