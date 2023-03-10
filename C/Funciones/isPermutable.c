//Función usada en Project Euler #52

int isPermutable(int n, int m, int length){ //Se guardan los digitos del número
    int i, j, cont = 1, digitos[length]; //Se declaran contadores y array; "cont" lleva la coincidencia de los digitos
    for (i=1; i <= length-1; i++){ //Se rellena el array
        digitos[i] = (n % 10);
        n /= 10;
    }
    //Se comprueba si los digitos coinciden
    for (i=1; i <= length-1; i++){ //Recorre los digitos de m
        j=1;
        while ((cont == i) && (j <= length-1)){//Recorre los digitos de n, el array; si se encuentra una coincidencia (cont++), se prosigue
            if (digitos[j] == (m % 10)) cont++;
            j++;
        }
        if (cont < i) return 0; //Si hay algún digito que no coincida, no es permutable
        else if (cont == length) return 1; //cont=5 cuando todos los digitos coinciden, permutable
        m /= 10;
        }
    return 0;
}
