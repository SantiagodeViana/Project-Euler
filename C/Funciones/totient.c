//Función usada en Project Euler #70

int Totient(int n){ //Calcula la función phi de una función (números no divisibles)
    int i, respuesta = 0;
    if (isPrime(n) == 1) return (n - 1);
    else{
        for (i=1; i<n ;i++){
            if (Euclides(n, i) == 1) respuesta++; //Versión más eficiente con Algoritmo de Euclides en vez de función "isCoprime"
            //if (respuesta > limite) return -1; //Se agreg condicional ad hoc: se dejarán de buscar aquellos coeficientes que sobrepasen el límite
        }
    }
    //if (i % 100 == 0) printf("%d\n", i);
    return respuesta;
}
