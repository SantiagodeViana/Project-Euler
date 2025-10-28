//Función usada en Project Euler #034

int digitFactorial(int n){ //Recibiendo un n, devuelve la suma del factorial de sus dígitos
    int suma = 0;
    while (n > 0){
        suma += factorial(n%10);
        n/=10;
    }
    return suma;
}
