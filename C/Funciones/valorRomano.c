//Función usada en Project Euler #89

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
