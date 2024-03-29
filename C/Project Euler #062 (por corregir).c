#include <stdio.h>
#include <stdlib.h>

int isPermutable(long long int n, long long int m, int length);
int digitos(long long int n);

//EULER 62
//Problema de desbordamiento

int main()
{
    int i, j, k, l, m;
        for (i=1; i<50000; i++){ //El rango, algo arbitrario, está basado en el ejemplo: ocho dígitos.
        for (j=i+1; (j<50000 && digitos(i*i*i) == digitos(j*j*j)); j++){
            if ((isPermutable(i*i*i, j*j*j, digitos(i*i*i)) == 1) && (isPermutable(j*j*j, i*i*i, digitos(i*i*i)) == 1)){
                for (k=j+1; (k<50000 && digitos(j*j*j) == digitos(k*k*k)); k++){
                    if ((isPermutable(i*i*i, k*k*k, digitos(j*j*j)) == 1) && (isPermutable(j*j*j, k*k*k, digitos(j*j*j)) == 1) && (isPermutable(k*k*k, j*j*j, digitos(j*j*j)) == 1)){
                        for (l=k+1; (l<50000 && digitos(k*k*k) == digitos(l*l*l)); l++){
                            if ((isPermutable(i*i*i, l*l*l, digitos(k*k*k)) == 1) && (isPermutable(j*j*j, l*l*l, digitos(k*k*k)) == 1) && (isPermutable(k*k*k, l*l*l, digitos(k*k*k)) == 1) && (isPermutable(l*l*l, i*i*i, digitos(k*k*k)) == 1) && (isPermutable(l*l*l, j*j*j, digitos(k*k*k)) == 1) && (isPermutable(l*l*l, k*k*k, digitos(k*k*k)) == 1)){
                                for (m=l+1; (m<50000 && digitos(l*l*l) == digitos(m*m*m)); m++){
                                    if ((isPermutable(i*i*i, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(j*j*j, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(k*k*k, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(l*l*l, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, i*i*i, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, j*j*j, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, k*k*k, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, l*l*l, digitos(m*m*m)) == 1)){
                                        printf ("i:%d\n", i); //("m:%lld, i3:%lld, j3:%lld, k3:%lld, l3:%lld, m3:%lld\n", m, i*i*i, j*j*j, k*k*k, l*l*l, m*m*m) ("i:%d, j:%d, k:%d, l:%d, m:%d\n", i*i*i, j*j*j, k*k*k, l*l*l, m*m*m)
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        //if (i > 1000) printf ("i:%d, i3:%d, j3:%d, k3:%d, l3:%d, m3:%d\n", i, i*i*i, j*j*j, k*k*k, l*l*l, m*m*m);
    }
    /*
    for (i=1115; i<1500; i++){
        printf("%i:%d - %lld\n", i, i*i*i);
    }

    for (i=1115; i<50000; i++){ //El rango, algo arbitrario, está basado en el ejemplo: ocho dígitos.
        for (j=i+1; (j<50000 && digitos(i*i*i) == digitos(j*j*j)); j++){
            if ((isPermutable(i*i*i, j*j*j, digitos(i*i*i)) == 1) && (isPermutable(j*j*j, i*i*i, digitos(i*i*i)) == 1)){
                for (k=j+1; (k<50000 && digitos(j*j*j) == digitos(k*k*k)); k++){
                    if ((isPermutable(i*i*i, k*k*k, digitos(j*j*j)) == 1) && (isPermutable(j*j*j, k*k*k, digitos(j*j*j)) == 1) && (isPermutable(k*k*k, j*j*j, digitos(j*j*j)) == 1)){
                        for (l=k+1; (l<50000 && digitos(k*k*k) == digitos(l*l*l)); l++){
                            if ((isPermutable(i*i*i, l*l*l, digitos(k*k*k)) == 1) && (isPermutable(j*j*j, l*l*l, digitos(k*k*k)) == 1) && (isPermutable(k*k*k, l*l*l, digitos(k*k*k)) == 1) && (isPermutable(l*l*l, i*i*i, digitos(k*k*k)) == 1) && (isPermutable(l*l*l, j*j*j, digitos(k*k*k)) == 1) && (isPermutable(l*l*l, k*k*k, digitos(k*k*k)) == 1)){
                                for (m=l+1; (m<50000 && digitos(l*l*l) == digitos(m*m*m)); m++){
                                    if ((isPermutable(i*i*i, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(j*j*j, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(k*k*k, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(l*l*l, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, i*i*i, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, j*j*j, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, k*k*k, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, l*l*l, digitos(m*m*m)) == 1)){
                                        printf ("m:%lld, i3:%lld, j3:%lld, k3:%lld, l3:%lld, m3:%lld\n", i, i*i*i, j*j*j, k*k*k, l*l*l, m*m*m); //("i:%d, j:%d, k:%d, l:%d, m:%d\n", i*i*i, j*j*j, k*k*k, l*l*l, m*m*m)
                                    }
                                }
                                printf ("m:%lld, i3:%lld, j3:%lld, k3:%lld, l3:%lld, m3:%lld\n", i, i*i*i, j*j*j, k*k*k, l*l*l, m*m*m);
                            }
                        }
                        printf ("m:%lld, i3:%lld, j3:%lld, k3:%lld, l3:%lld, m3:%lld\n", i, i*i*i, j*j*j, k*k*k, l*l*l, m*m*m);
                    }
                }
                printf ("m:%lld, i3:%lld, j3:%lld, k3:%lld, l3:%lld, m3:%lld\n", i, i*i*i, j*j*j, k*k*k, l*l*l, m*m*m);
            }
            printf ("j:%lld, i3:%lld, j3:%lld, k3:%lld, l3:%lld, m3:%lld\n", j, i*i*i, j*j*j, k*k*k, l*l*l, m*m*m);
        }
    }
    for (i=1; i<50000; i++){ //El rango, algo arbitrario, está basado en el ejemplo: ocho dígitos.
        for (j=i+1; (j<50000 && digitos(i*i*i) == digitos(j*j*j)); j++){
            if ((isPermutable(i*i*i, j*j*j, digitos(i*i*i)) == 1) && (isPermutable(j*j*j, i*i*i, digitos(i*i*i)) == 1)){
                for (k=j+1; (k<50000 && digitos(j*j*j) == digitos(k*k*k)); k++){
                    if ((isPermutable(i*i*i, k*k*k, digitos(j*j*j)) == 1) && (isPermutable(j*j*j, k*k*k, digitos(j*j*j)) == 1) && (isPermutable(k*k*k, j*j*j, digitos(j*j*j)) == 1)){
                        for (l=k+1; (l<50000 && digitos(k*k*k) == digitos(l*l*l)); l++){
                            if ((isPermutable(i*i*i, l*l*l, digitos(k*k*k)) == 1) && (isPermutable(j*j*j, l*l*l, digitos(k*k*k)) == 1) && (isPermutable(k*k*k, l*l*l, digitos(k*k*k)) == 1) && (isPermutable(l*l*l, i*i*i, digitos(k*k*k)) == 1) && (isPermutable(l*l*l, j*j*j, digitos(k*k*k)) == 1) && (isPermutable(l*l*l, k*k*k, digitos(k*k*k)) == 1)){
                                for (m=l+1; (m<50000 && digitos(l*l*l) == digitos(m*m*m)); m++){
                                    if ((isPermutable(i*i*i, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(j*j*j, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(k*k*k, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(l*l*l, m*m*m, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, i*i*i, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, j*j*j, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, k*k*k, digitos(m*m*m)) == 1) && (isPermutable(m*m*m, l*l*l, digitos(m*m*m)) == 1)){
                                        printf ("m:%lld, i3:%lld, j3:%lld, k3:%lld, l3:%lld, m3:%lld\n", m, i*i*i, j*j*j, k*k*k, l*l*l, m*m*m); //("i:%d, j:%d, k:%d, l:%d, m:%d\n", i*i*i, j*j*j, k*k*k, l*l*l, m*m*m)
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (i > 1000) printf ("i:%d, i3:%d, j3:%d, k3:%d, l3:%d, m3:%d\n", i, i*i*i, j*j*j, k*k*k, l*l*l, m*m*m);
    }
    */
    //
    //printf("1:%d 2:%d 3:%d\n", i*i*i, (i+1)*(i+1)*(i+1), (i+2)*(i+2)*(i+2)); //printf("1:%d 2:%d 3:%d 4:%d 5:%d", i, i*2, i*3, i*4, i*5, i*);
    printf("Fin del programa\n");
    return 0;
}

    /*
    printf("%d\n", digitos(100));
    printf("%d\n", digitos(1));
    printf("%d\n", digitos(10000));
    printf("%d\n", digitos(25));
    printf("%d\n", digitos(7500));
    */

int isPermutable(long long int n, long long int m, int length){ //Se guardan los digitos del número
    int i, j, cont = 0, cont2 = 0, temp = -1, temp2 = -1, digitos[length]; //Se declaran contadores y array; "cont" lleva la coincidencia de los digitos
    //if (digitos(n) != digitos(m)) return 0;
    if (n == m) return 0;
    for (i=0; i <= length-1; i++){ //Se rellena el array
        digitos[i] = (n % 10);
        n /= 10;
    }
    //Se comprueba si los digitos coinciden
    for (i=0; i <= length-1; i++){ //Recorre los digitos de m
        temp = digitos[i];
        temp2 = m;
        for (j=0; j <= length-1; j++){ //Bucle para determinar dígito y contarlo
            if (digitos[j] == temp) cont++;
        }
        while(temp2 != 0){ //Se comparan las cifras
            if (temp2%10 == temp) cont2++;
            temp2 /= 10;
        }
        if (cont != cont2) return 0;
        cont = 0; //Se reinicia el contador de dígitos
        cont2 = 0;
    }
    return 1;
}

int digitos(long long int n){
    int respuesta = 0, i = 1;
    while (i <= n){
        i*=10;
        respuesta++;
    }
    return respuesta;
}

/*
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
*/
