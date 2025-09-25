//Función usada en Project Euler #145

int revert(int n){ //Invierte input n
    int reverse = 0;
    if (n < 0 || n % 10 == 0) return 0; //Se descartan casos con leading zeros
    while (n > 0) {
        reverse = reverse * 10 + (n % 10);
        n /= 10;
    }
     return reverse;
}
