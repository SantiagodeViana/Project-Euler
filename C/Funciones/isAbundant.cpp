//Función usada en Project Euler #23

int isAbundant(int n){ //Función que determina si un número es abundante
    int divisores = 1, i; //Todos los números son divisibles entre 1
    if (n < 12) return 0; //No hay numeros abundantes menores de 12
    for (i = 2; i <= (n/2); i++){
        if (n%i == 0) divisores += i; //Se consigue la suma del total de divisores
        if (divisores > n){
            //printf("i:%d\n", n);
            return 1; //1: Abundante
        }
    }
    return 0; //0: No abundante
}
