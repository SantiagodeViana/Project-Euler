//Función usada en Project Euler #36

int binaryPalindrome (int n){ //Creando especialmente para evitar problemas de desbordamiento
    int i, digitos = 0, potencia = 2, binario[20];
    if ((n % 2 == 0) || (n % 10 == 0)) return 0; //There can be no leading zeros, por lo que los números pares no son palíndromos
    //Tampoco los menores a 10 ni aquellos que terminen en 0 //(n < 10) ||
    while (potencia <= n){
        potencia *= 2;
        digitos++;
        //printf("potencia:%d digitos:%d\n", potencia, digitos);
    }
    potencia /= 2;
    for (i=0; potencia != 1; i++){
        //printf("n:%d potencia:%d j:%lld binario:%lld\n", n, potencia, j, binario);
        if (n >= potencia){
            n -= potencia;
            binario[i] = 1;
        }
        else binario[i] = 0;
        potencia /= 2;
    }
    binario[i] = 1;
    for (i=0; i <= digitos/2; i++){
        if (binario[i] != binario[digitos-i]) return 0;
    }
    return 1;
}
