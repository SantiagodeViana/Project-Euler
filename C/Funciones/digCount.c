//Función usada en Project Euler #156

int digCount(int n, int d){ //Devuelve las veces en las que d aparece en n
    int digs = 0;
    while (n > 0){
        if (n % 10 == d) digs++;
        n /= 10;
    }
    return digs;
}
