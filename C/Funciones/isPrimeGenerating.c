//Función usada en Project Euler #357

int isPrimeGenerating(int n){ //Modelo sacado de overview de Problema 3 de Project Euler
    int i;
    if (n == 1 || n == 2) return 1; //Devuelve 1 cuando es generador dde primos
    else if (isPrime(n) == 1) return 0; //Devuelve 0 cuando no lo es
    else{
        for(i=1; i <= floor(sqrt(n)) ; i++){
            if (n % i == 0){ //Si se consigue un divisor
                if (isPrime(i + n/i) != 1) return 0;
            }
        }
    }
    return 1;
}
