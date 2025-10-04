#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* Solución para el problema #89 de Project Euler
 * "Encuentra el número de caracteres que se ahorran escribiendo números romanos en su expresión mínima."
 * https://projecteuler.net/problem=89            */

int valorRomano(char romanos[3][50], int indice);
int savedChar (char romanos[3][50]);

int main()
{  
    FILE *listaRomanos; 
    int i = 0, respuesta = 0;
    //char temp [15]; //Array temporal para recibir y llenar
    char romanos[3][50];
    listaRomanos = fopen ("C:\\Users\\Santiago\\Desktop\\p089_roman.txt", "r"); //Hay que usar doble raya para que sea reconocido por el programa
    if(listaRomanos==NULL) printf("No se puede acceder al fichero.");

    while(fgets(romanos, 50, listaRomanos)){ //Bucle para almacenar
        respuesta += savedChar(romanos); //Suma la cantidad de letras ahorradas
        printf("i:%d Respuesta:%d Valor:%d %s", i+1, respuesta, valorRomano(romanos, 0), romanos);
        i++;
    }

    respuesta++; //La última entrada no tiene break line; como tal, se suma un caracter más
    printf("\nRespuesta:%d\n", respuesta); //La respuesta es 743
    printf("Fin del programa.\n");
    fclose(listaRomanos); //Recomendado: Cerrar fichero
    return 0;
}


int valorRomano(char romanos[3][50], int indice){ //Función para determinar valor de números romanos
    int i, valor = 0; //while(romanos[i]>='A' && romanos[i]<='Z'){
    for(i=0; romanos[indice][i]>='A' && romanos[indice][i]<='Z' ; i++){
        switch(romanos[indice][i]){
            case 'M':
                valor += 1000;
                break;
            case 'D':
                valor += 500;
                break;
            case 'C':
                if (romanos[indice][i+1] == 'M'){ // CM, 900
                    valor += 900;
                    i++; //Salta también la M
                }
                else if (romanos[indice][i+1] == 'D'){ // CD, 400
                    valor += 400;
                    i++; //Salta también la D
                }
                else valor += 100;
                break;
            case 'L':
                valor += 50;
                break;
            case 'X':
                if (romanos[indice][i+1] == 'C'){ // XC, 90
                    valor += 90;
                    i++; //Salta también la C
                }
                else if (romanos[indice][i+1] == 'L'){ // XL, 40
                    valor += 40;
                    i++; //Salta también la L
                }
                else valor += 10;
                break;
            case 'V':
                valor += 5;
                break;
            case 'I':
                if (romanos[indice][i+1] == 'X'){ // IX, 9
                    valor += 9;
                    i++; //Salta también la X
                }
                else if (romanos[indice][i+1] == 'V'){ // IV, 4
                    valor += 4;
                    i++; //Salta también la V
                }
                else valor += 1;
                break;
        }
    }
    return valor;
}
int savedChar (char romanos[3][50]){ //Determina cuantos caracteres pueden reducirse
    int respuesta = 0, minChar = 0, originalChar = valorRomano(romanos, 0), temp = 0; //Caracteres mínimos que se pueden usar para el número
    while (originalChar > 0){
        if (originalChar >= 1000){ //M
            temp = originalChar/1000;
            minChar += temp; //Sumando Ms por cantidad de miles
            originalChar -= temp*1000; //Restando miles
            temp = 0;
        }
        else if (originalChar >= 900){ //CM
            temp = 2;
            minChar += 2; //Sumando CM
            originalChar -= 900; //Restando 900
            temp = 0;
        }
        else if (originalChar >= 500){ //D
            temp = originalChar/500;
            minChar += temp; //Sumando Ds por cantidad de quinientos
            originalChar -= temp*500; //Restando quinientos
            temp = 0;
        }
        else if (originalChar >= 400){ //CD
            temp = 2;
            minChar += 2; //Sumando CD
            originalChar -= 400; //Restando 400
            temp = 0;
        }
        else if (originalChar >= 100){ //C
            temp = originalChar/100;
            minChar += temp; //Sumando Cs por cantidad de centenas
            originalChar -= temp*100; //Restando centenas
            temp = 0;
        }
        else if (originalChar >= 90){ //XC
            temp = 2;
            minChar += 2; //Sumando XC
            originalChar -= 90; //Restando 90
            temp = 0;
        }
        else if (originalChar >= 50){ //L
            temp = originalChar/50;
            minChar += temp; //Sumando Ls por cantidad de cincuentas
            originalChar -= temp*50; //Restando cincuentas
            temp = 0;
        }
        else if (originalChar >= 40){ //XL
            temp = 2;
            minChar += 2; //Sumando XL
            originalChar -= 40; //Restando 40
            temp = 0;
        }
        else if (originalChar >= 10){ //X
            temp = originalChar/10;
            minChar += temp; //Sumando Xs por cantidad de decenas
            originalChar -= temp*10; //Restando decenas
            temp = 0;
        }
        else if (originalChar >= 9){ //IX
            temp = 2;
            minChar += 2; //Sumando IX
            originalChar -= 9; //Restando 9
            temp = 0;
        }
        else if (originalChar >= 5){ //V
            temp = originalChar/5;
            minChar += temp; //Sumando Vs por cantidad de cincos
            originalChar -= temp*5; //Restando cinco
            temp = 0;
        }
        else if (originalChar >= 4){ //IV
            temp = 2;
            minChar += 2; //Sumando IV
            originalChar -= 4; //Restando 900
            temp = 0;
        }
        else if (originalChar >= 1){ //I
            temp += originalChar;
            minChar += temp; //Sumando Is por cantidad de unidades
            originalChar -= temp; //Restando unidades
        }
    }
    respuesta = (strlen(romanos)-1) - minChar; //Se resta del length el break line, con la excepción a la última entrada
    return respuesta;
}

/*
printf("Length:%d\n", strlen(romanos));

!feof (listaRomanos
fgets(listaRomanos, strlen (listaRomanos), &romanos[i]);

        while(romanos[j][i] != "\n"){
            fscanf(listaRomanos, "%c", &romanos[j][i]);
            printf("%c", romanos[j][i]);
            j++;
        }
        printf("\n i:%d j:%d", i, j);
        i++;
        j=0; //Se reinicia valor de j

    char prueba[15]= "hello world";
    int i;
    for (i=0; i<=15 &&;i++){
        printf("%c\n", prueba[i]);
    }
*/
