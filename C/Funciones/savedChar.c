//Función usada en Project Euler #89

int savedChar (char romanos[3][50]){ //Determina cuantos caracteres pueden reducirse en un número romano. Depende de la función valorRomano()
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
