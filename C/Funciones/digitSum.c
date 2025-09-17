//Función usada en Project Euler #119 y #387

int digitSum(long long int n){ //Función para sumar dígitos de un entero
    int suma = 0;
    while (n > 0){
        suma += n % 10;
        n/=10;
    }
    return suma;
}
