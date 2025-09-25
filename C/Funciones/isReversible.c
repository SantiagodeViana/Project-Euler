//Función usada en Project Euler #145

int isReversible(int n){ //Comprueba si todos los dígitos de la suma de n y su inverso son impares
    int suma, reversible = 1; //reversible es una variable booleana
    suma = n + revert(n);
    while (suma > 0 && reversible == 1){
        reversible = ((suma % 10) % 2 == 1); //Se evalúa cada dígito uno por uno si son impares
        suma /= 10;
    }
    return reversible;
}
