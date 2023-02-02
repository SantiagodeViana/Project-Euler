#include <stdio.h>
#include <stdlib.h>

int binary(int n);
int digitos(int n);
int XOR(int n, int m);
int decimal(int n);

int main()
{
    //printf("%d, %d, %d", 'a', 'z', 122-97);
    //La clave es i:101 j:120 k:112. "exp".
    //printf ("%c%c%c", 101, 120, 112);
    //getchar();
  
    int cipher[1455] = {36,22,80,0,0,4,23,25,19,17,88,4,4,19,21,11,88,22,23,23,29,69,12,24,0,88,25,11,12,2,10,28,5,6,12,25,10,22,80,10,30,80,10,22,21,69,23,22,69,61,5,9,29,2,66,11,80,8,23,3,17,88,19,0,20,21,7,10,17,17,29,20,69,8,17,21,29,2,22,84,80,71,60,21,69,11,5,8,21,25,22,88,3,0,10,25,0,10,5,8,88,2,0,27,25,21,10,31,6,25,2,16,21,82,69,35,63,11,88,4,13,29,80,22,13,29,22,88,31,3,88,3,0,10,25,0,11,80,10,30,80,23,29,19,12,8,2,10,27,17,9,11,45,95,88,57,69,16,17,19,29,80,23,29,19,0,22,4,9,1,80,3,23,5,11,28,92,69,9,5,12,12,21,69,13,30,0,0,0,0,27,4,0,28,28,28,84,80,4,22,80,0,20,21,2,25,30,17,88,21,29,8,2,0,11,3,12,23,30,69,30,31,23,88,4,13,29,80,0,22,4,12,10,21,69,11,5,8,88,31,3,88,4,13,17,3,69,11,21,23,17,21,22,88,65,69,83,80,84,87,68,69,83,80,84,87,73,69,83,80,84,87,65,83,88,91,69,29,4,6,86,92,69,15,24,12,27,24,69,28,21,21,29,30,1,11,80,10,22,80,17,16,21,69,9,5,4,28,2,4,12,5,23,29,80,10,30,80,17,16,21,69,27,25,23,27,28,0,84,80,22,23,80,17,16,17,17,88,25,3,88,4,13,29,80,17,10,5,0,88,3,16,21,80,10,30,80,17,16,25,22,88,3,0,10,25,0,11,80,12,11,80,10,26,4,4,17,30,0,28,92,69,30,2,10,21,80,12,12,80,4,12,80,10,22,19,0,88,4,13,29,80,20,13,17,1,10,17,17,13,2,0,88,31,3,88,4,13,29,80,6,17,2,6,20,21,69,30,31,9,20,31,18,11,94,69,54,17,8,29,28,28,84,80,44,88,24,4,14,21,69,30,31,16,22,20,69,12,24,4,12,80,17,16,21,69,11,5,8,88,31,3,88,4,13,17,3,69,11,21,23,17,21,22,88,25,22,88,17,69,11,25,29,12,24,69,8,17,23,12,80,10,30,80,17,16,21,69,11,1,16,25,2,0,88,31,3,88,4,13,29,80,21,29,2,12,21,21,17,29,2,69,23,22,69,12,24,0,88,19,12,10,19,9,29,80,18,16,31,22,29,80,1,17,17,8,29,4,0,10,80,12,11,80,84,67,80,10,10,80,7,1,80,21,13,4,17,17,30,2,88,4,13,29,80,22,13,29,69,23,22,69,12,24,12,11,80,22,29,2,12,29,3,69,29,1,16,25,28,69,12,31,69,11,92,69,17,4,69,16,17,22,88,4,13,29,80,23,25,4,12,23,80,22,9,2,17,80,70,76,88,29,16,20,4,12,8,28,12,29,20,69,26,9,69,11,80,17,23,80,84,88,31,3,88,4,13,29,80,21,29,2,12,21,21,17,29,2,69,12,31,69,12,24,0,88,20,12,25,29,0,12,21,23,86,80,44,88,7,12,20,28,69,11,31,10,22,80,22,16,31,18,88,4,13,25,4,69,12,24,0,88,3,16,21,80,10,30,80,17,16,25,22,88,3,0,10,25,0,11,80,17,23,80,7,29,80,4,8,0,23,23,8,12,21,17,17,29,28,28,88,65,75,78,68,81,65,67,81,72,70,83,64,68,87,74,70,81,75,70,81,67,80,4,22,20,69,30,2,10,21,80,8,13,28,17,17,0,9,1,25,11,31,80,17,16,25,22,88,30,16,21,18,0,10,80,7,1,80,22,17,8,73,88,17,11,28,80,17,16,21,11,88,4,4,19,25,11,31,80,17,16,21,69,11,1,16,25,2,0,88,2,10,23,4,73,88,4,13,29,80,11,13,29,7,29,2,69,75,94,84,76,65,80,65,66,83,77,67,80,64,73,82,65,67,87,75,72,69,17,3,69,17,30,1,29,21,1,88,0,23,23,20,16,27,21,1,84,80,18,16,25,6,16,80,0,0,0,23,29,3,22,29,3,69,12,24,0,88,0,0,10,25,8,29,4,0,10,80,10,30,80,4,88,19,12,10,19,9,29,80,18,16,31,22,29,80,1,17,17,8,29,4,0,10,80,12,11,80,84,86,80,35,23,28,9,23,7,12,22,23,69,25,23,4,17,30,69,12,24,0,88,3,4,21,21,69,11,4,0,8,3,69,26,9,69,15,24,12,27,24,69,49,80,13,25,20,69,25,2,23,17,6,0,28,80,4,12,80,17,16,25,22,88,3,16,21,92,69,49,80,13,25,6,0,88,20,12,11,19,10,14,21,23,29,20,69,12,24,4,12,80,17,16,21,69,11,5,8,88,31,3,88,4,13,29,80,22,29,2,12,29,3,69,73,80,78,88,65,74,73,70,69,83,80,84,87,72,84,88,91,69,73,95,87,77,70,69,83,80,84,87,70,87,77,80,78,88,21,17,27,94,69,25,28,22,23,80,1,29,0,0,22,20,22,88,31,11,88,4,13,29,80,20,13,17,1,10,17,17,13,2,0,88,31,3,88,4,13,29,80,6,17,2,6,20,21,75,88,62,4,21,21,9,1,92,69,12,24,0,88,3,16,21,80,10,30,80,17,16,25,22,88,29,16,20,4,12,8,28,12,29,20,69,26,9,69,65,64,69,31,25,19,29,3,69,12,24,0,88,18,12,9,5,4,28,2,4,12,21,69,80,22,10,13,2,17,16,80,21,23,7,0,10,89,69,23,22,69,12,24,0,88,19,12,10,19,16,21,22,0,10,21,11,27,21,69,23,22,69,12,24,0,88,0,0,10,25,8,29,4,0,10,80,10,30,80,4,88,19,12,10,19,9,29,80,18,16,31,22,29,80,1,17,17,8,29,4,0,10,80,12,11,80,84,86,80,36,22,20,69,26,9,69,11,25,8,17,28,4,10,80,23,29,17,22,23,30,12,22,23,69,49,80,13,25,6,0,88,28,12,19,21,18,17,3,0,88,18,0,29,30,69,25,18,9,29,80,17,23,80,1,29,4,0,10,29,12,22,21,69,12,24,0,88,3,16,21,3,69,23,22,69,12,24,0,88,3,16,26,3,0,9,5,0,22,4,69,11,21,23,17,21,22,88,25,11,88,7,13,17,19,13,88,4,13,29,80,0,0,0,10,22,21,11,12,3,69,25,2,0,88,21,19,29,30,69,22,5,8,26,21,23,11,94};
    int respuesta[1455];
    int i, j, k, x; //i, j y k son los contadores fuerza bruta de la hipotética contraseña. x es el contador del array
  
    //int valid = 0,
    int answer = 0;
  
    //printf("%d, %d", decimal(XOR(binary(65), binary(42))), decimal(XOR(binary(107), binary(42))));
    //getchar();
  
    /*for (i=97; i<=122; i++){ //Fuerza bruta de primera letra de la clave    //for (i=97; i<=122; i++){
        for (j=97; j<=122; j++){ //Fuerza bruta de segunda letra de la clave
            for (k=97; k<=122; k++){ //Fuerza bruta de tercera letra de la clave
                for (x=0; x<=1455; x++){ //Recorrido de array para decifrar mensaje
                    if (x%3 == 0) respuesta[x] = decimal(XOR(binary(i), binary(cipher[x]))); //Letras cifradas por la primera letra de la clave
                    //printf("Respuesta:%d, XOR:%d, i:%d/%d, Cipher:%d/%d", decimal(XOR(binary(i), binary(cipher[x]))), XOR(binary(i), binary(cipher[x])), i, binary(i), cipher[x], binary(cipher[x]));
                    //getchar();
                    else if (x%3 == 1) respuesta[x] = decimal(XOR(binary(j), binary(cipher[x]))); //Letras cifradas por la segunda letra de la clave
                    else if (x%3 == 2) respuesta[x] = decimal(XOR(binary(k), binary(cipher[x]))); //Letras cifradas por la tercera letra de la clave
                }
                //for (x=0; x<=1455; x++){
                //    if ((respuesta[x] >= 97 && respuesta[x] <= 122) || (respuesta[x] >= 65 && respuesta[x] <= 90) || respuesta[x] == 32) valid++; //97 es a, 122 es z; son los caracteres válidos de ASCIIw
                //}
                //if (valid >= 1300){ //Si la mayoria de los caracteres son válidos
                if (i==101 && j==120 && k==112){ //&& k==110
                    for (x=0; x<1455; x++){
                        answer += respuesta[x];
                        printf("%c", respuesta[x]);
                        //if ((respuesta[x] >= 97 && respuesta[x] <= 122) || respuesta[x] == 32)
                        //else break;
                    }
                printf("\n i:%d j:%d k:%d \n", i, j, k);
                //getchar(); //i:101 j:120 k:112
                }
                //}
                //valid = 0; //Se reinicia el valor de caracteres válidos
            }
        }
    }*/
    for (x=0; x<=1455; x++){ //Recorrido de array para decifrar mensaje
        if (x%3 == 0) respuesta[x] = decimal(XOR(binary(101), binary(cipher[x])));
        else if (x%3 == 1) respuesta[x] = decimal(XOR(binary(120), binary(cipher[x]))); //Letras cifradas por la segunda letra de la clave
        else if (x%3 == 2) respuesta[x] = decimal(XOR(binary(112), binary(cipher[x]))); //Letras cifradas por la tercera letra de la clave
    }
    for (x=0; x<1455; x++){
        answer += respuesta[x];
        printf("%c", respuesta[x]);
    }
    printf("La respuesta es: %d.\n", answer);
    printf("Fin del programa.\n");
    return 0;
}

int binary(int n){ //Función que recibe un número en base digital y la convierte en base binaria
    int i, digitos = 0, potencia = 2;
    int j = 1, binario = 0;
    while (potencia <= n){ //Se calculan los digitos del binario
        potencia *= 2;
        digitos++;
    }
    potencia /= 2; //Es posible eliminar esta línea?
    for (i = 1; i <= digitos; i++) j *= 10; //j será el sumador de los binarios
    while (potencia != 1){
        if (n >= potencia){ //Cuando el número es superior a la potencia de base 2, se resta y se procede a marcar con un 1 en esa potencia
            binario += j;
            n -= potencia;
        }
        if (potencia == 1) potencia++;
        potencia /= 2;
        j /= 10;
    }
    if (n == 1) binario++; //Se agrega un 1 al final si n es impar
    return binario;
}
int digitos(int n){ //Cuenta los dígitos de una cifra
    int respuesta = 0, i = 1;
    while (i <= n){
        i*=10;
        respuesta++;
    }
    return respuesta;
}
int XOR(int n, int m){ //Recibe dos números binarios y aplica la operación lógica XOR con ellos
    //Evitar entradas con leading zeros: por alguna razón causa la entrada del parámetro como un número decimal
    int i, respuesta = 0, baseB = 1;  // ***** i = digitos
    if (digitos(n) >= digitos(m)) for (i=1; i<digitos(n); i++) baseB*=10; //Se calcula divisor
    else if (digitos(n) < digitos(m)) for (i=1; i<digitos(m); i++) baseB*=10;
    while(baseB >= 1){
        if ((n/baseB) != (m/baseB)) respuesta += baseB; // A != B => 1
        //else if ((n/baseB) == (m/baseB)) respuesta *= 10; //else if ((n/baseB) == (m/baseB))
        if (n >= baseB) n %= baseB; //Se "recortan" las entradas
        if (m >= baseB) m %= baseB;
        baseB /= 10; //En el caso de que sean iguales, el 0 es implícito
    }
    return respuesta;
}
int decimal (int n){ //Recibe un número en base binaria y la convierte a base digital
    int i, respuesta = 0, base2 = 1, base10 = 2;
    for (i=1; i<digitos(n); i++){
        base10*=2; //Se calcula la máxima potencia de 2
        if (i >= 1) base2*=10; //Se calcula el mayor dígito en numeración binaria
    }
    base10 /= 2; //Se reducen las potencias
    while (base10 != 1){
        if (n/base2 == 1) respuesta += base10; //Si el número binario coincide con la potencia respectiva, se suma el correspondiendo valor en decimalZ
        n %= base2;
        base2 /= 10;
        base10 /= 2; //Se reducen las potencias
    }
    if (n == 1) respuesta ++;
    return respuesta;
    /*
     * Aquí también la operación modular da errores
     * Probablemente debido a una imposibilidad matemática, como la división entre cero.
     */
}
  /*
    PRUEBAS DE FUNCIÓN XOR
    //printf("%d\n", XOR(10, 101));
    //printf("%d\n", XOR(111, 001)); PROBLEMA DE OPERACIÓN MODULAR, usar el compilador posteriormente
    printf("%d\n", XOR(101, 1110));
    printf("%d\n", XOR(11, 11));
    printf("%d\n", XOR(11010, 101));
    printf("%d\n", XOR(11, 10010));
    printf("%d\n", XOR(1110, 10));
    printf("%d\n", XOR(10, 11001));
    printf("%d\n", XOR(10011, 101));
    printf("%d\n", XOR(10, 1111));
    printf("%d\n", XOR(1100, 111));
    printf("%d\n", XOR(100, 11));
    printf("%d\n", XOR(111, 1));

    PRUEBAS DE FUNCIÓN DECIMAL

    printf("%d\n", decimal(1111)); //15
    printf("%d\n", decimal(10101)); //21
    printf("%d\n", decimal(1));
    printf("%d\n", decimal(11110)); //30
    printf("%d\n", decimal(1001)); //9
  */
