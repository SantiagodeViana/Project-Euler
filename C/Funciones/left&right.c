//Funciones usadas en Project Euler #037

int left(int n){ //Desde la izquierda
    int i = 1, j;
    while (i < n) i *= 10;
    while (i >= 1){
        j = n % i;
        if (isPrime(j) == 0) return 0;
        i /= 10;
    }
    if (isPrime(j) == 1) return 1;
    return 0;
}

int right(int n){ //Desde la derecha
    int i = 1, j;
    while (i < n){
        j = n / i;
        if (isPrime(j) == 0) return 0;
        i *= 10;
    }
    if (isPrime(j) == 1) return 1;
    return 0;
}
