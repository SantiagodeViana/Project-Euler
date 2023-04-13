//Función usada en Project Euler #387

int rightTruncatableStrongHarshadPrime(long long int n){
    if (isPrime(n) != 1) return 0;
    else if (n < 10) return 0; //Menores que 10 return 0?
    else{
        n /= 10;
        if (strongHarshad(n) == 1 && rightTruncatableHarshad(n) == 1) return 1;
    }
    return 0;
}
