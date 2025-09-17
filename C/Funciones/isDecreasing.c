//Función mencionada en Project Euler #112 y función isBouncy

int isDecreasing (int n){
    int aux = n % 10, dec = 1;
    while (n >= 10 && dec == 1){
        n /= 10;
        if (n % 10 < aux) dec = 0;
        aux = n % 10;
    }
    return dec;
 }
