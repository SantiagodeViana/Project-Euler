//Función usada en Project Euler #387

int isRightTruncatableStrongHarshadPrime(long long int n){
    if (isPrime(n) != 1) return 0;
    else if (n < 10) return 0; //Menores que 10 return 0?
    else{
        n /= 10;
        if (isStrongHarshad(n) == 1 && isRightTruncatableHarshad(n) == 1) return 1;
    }
    return 0;
}
