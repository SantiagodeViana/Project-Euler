//Función mencionada en Project Euler #112

int isIncreasing (int n){
    int aux, inc = 1;
    if (n > 9){
        aux = n % 10;
        while (n > 0 || inc == 1){
            n /= 10;
            if (n % 10 > aux) inc = 0;
            aux = n % 10;
        }
    }
    return inc;
 }
