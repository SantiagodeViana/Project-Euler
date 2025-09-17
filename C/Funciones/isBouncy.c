//Función usada en Project Euler #112

int isBouncy (int n){
    int bounce = 1;
    if (n < 100) bounce = 0; //No hay bouncy numbers menores que 100
    else{
        if (isDecreasing(n) == 1 || isIncreasing(n) == 1) bounce = 0; //Un bouncy number no es ni incremental ni decremental
    }
    return bounce; //La operación también puede hacerse con un solo chequeo, pero el número probablemente deba ser tratado como una cadena
}
