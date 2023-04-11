//Función usada en Project Euler #59 y #387

int digitos(int n){ //Cuenta los dígitos de una cifra
    int respuesta = 0, i = 1;
    while (i <= n){
        i*=10;
        respuesta++;
    }
    return respuesta;
}
