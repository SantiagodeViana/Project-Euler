#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Psudocódigo:
     * Optimizar código - Generar todas las hipotenusas posibles:
     * Tener solo tres bucles: 'x', 'y', 'z'
     * Sumar los cuadrados de los dos primeros
     * Comprobar que sea igual a un valor de z, sumando hasta que se consiga
     * Si se comprueba, almanecar en un array
     * Si no se comprueba, proceder a la siguiente suma
     * Repetir hasta llegar al límite
     * (Esto debería servir como una buena práctica de modificación de arrays

    13/11/2021: Desbordamiento  */

    int x, y, z, respuesta = 0;
    long long int xC, yC, zC;
    for(x=1; x <= 1500000; x++){
        for(y=(x+1); y <= 1500000; y++){
            for(z=(y+1); z <= 1500000; z++){
                    xC = x*x; yC = y*y; zC = z*z;
                    if (xC + yC == zC){
                        respuesta++;//Pitágoras: Suma de los cuadrados de los catetos igual a cuadrado hipotenusa
                        printf("Respuesta:%d - %d - x:%d y:%d z:%d\n", respuesta, (x+y+z), x, y, z);
                    }
                    //printf("x:%d y:%d z:%d\n", x, y, z);
            }
            //if (y % 100 == 0) printf("x:%d y:%d\n", x, y);
        }
    }
    printf("La respuesta es: %d\n", respuesta);
    printf("Fin del programa.\n");
    return 0;
}

/*
    int x, y, z, respuesta = 17687;
    //Respuesta 415; x: 3; y: 408980; z:1492933
    //Respuesta:3657; x: 9; y: 519092; z: 1321713
    //Respuesta:9327; x: 21; y: 511736; z: 866891
    //Respuesta:17687; x: 37; y: 1031224; z: 1394235
    for(x=37; x <= 1500000;x++){
        for(y=(x+1); y <= 1500000;y++){
            if (x==37 && y < 1031224) y = 1031224;//Continuación
            for(z=(y+1); z <= 1500000;z++){
                if (x==37 && y == 1031224 && z < 1394235) z = 1394235;
                    if ((x*x + y*y) == (z*z)){
                        respuesta++;//Pitágoras: Suma de los cuadrados de los catetos igual a cuadrado hipotenusa
                        printf("Respuesta:%d - %d - x:%d y:%d z:%d\n", respuesta, (x+y+z), x, y, z);
                    }
                    //printf("x:%d y:%d z:%d\n", x, y, z);
            }
            //if (y % 100 == 0) printf("x:%d y:%d\n", x, y);
        }
    }
    printf("La respuesta es: %d\n", respuesta);
    printf("Fin del programa.\n");
    return 0;
    */
