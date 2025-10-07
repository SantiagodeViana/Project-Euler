//Función usada en Project Euler #387

int isStrongHarshad(long long int n){
    if (n % digitSum(n) != 0) return 0;
    else if (n < 10) return 0;
    else if (isPrime(n/digitSum(n)) == 1) return 1; //Si l división de la suma de sus dígitos es un número primo
    return 0;
}
