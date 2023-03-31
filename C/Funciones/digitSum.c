//Función usada en Project Euler #387

int digitSum(long long int n){ //Función para sumar dígitos de un entero
    int i, suma = 0;
    for (i=0; i<=digitos(n)+1;i++){
        suma += n % 10;
        n/=10;
    }
    return suma;
}
