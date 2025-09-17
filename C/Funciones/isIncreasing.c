//Función usada en Project Euler #112 y función isBouncy

int isIncreasing (int n){
    int aux = n % 10, inc = 1;
    while (n >= 10 && inc == 1){
        n /= 10;
        if (n % 10 > aux) inc = 0;
        aux = n % 10;
    }
    return inc;
 }
