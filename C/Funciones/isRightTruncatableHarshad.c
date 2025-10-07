//Función usada en Project Euler #387

int isRightTruncatableHarshad(long long int n){ //Desde la derecha
    int i = 1, j;
    if (n < 10) return 0;
    else{
        while (i < n){
            j = n / i;
            if (isHarshad(j) == 0) return 0; //Mientras recursivamente siempre siga dando números Harshad
            i *= 10;
        }
    }
    return 1;
}
