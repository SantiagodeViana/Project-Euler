//Función mencionada en Project Euler #112

int isDecreasing (int n){
     int aux, dec = 1;
    if (n > 9){
        aux = n % 10;
        while (n > 0 || dec == 1){
            n /= 10;
            if (n % 10 < aux) dec = 0;
            aux = n % 10;
        }
    }
    return dec;
 }
