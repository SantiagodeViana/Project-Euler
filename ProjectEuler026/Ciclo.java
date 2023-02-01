public class Ciclo { //Actualmente mide a veces la longitud del ciclo con una unidad de exceso
    public static int longitudCiclo(double n){ //Método para determinar longitud de ciclo recurrente. Recibe double como entrada
        boolean repetido = false;
        int i = 0, N = 16, longitud = 0, rep = 0; //N: tamaño array; longitud: mide el ciclo;
        int [] decimal = new int [N];
        decimal[0] = -1;
        while (i < N && !repetido){
            n *= 10.0;
            if (i != 0) n -= decimal[i-1] * 10; //En caso de haber empezado el bucle, uno sólo se queda con una unidad
            decimal[i] = (int) (n % 10); //Se adquiere un decimal al mismo tiempo
            for (int j = 0; j <= i && !repetido; j++){ //Bucle para comprobar repeticiones en el ciclo
                if (decimal[j] == decimal[i] && i != 0 && i != j){
                    repetido = true;
                    /* Este bucle confirma si la repetición es genuina
                     * Si 5 dìgitos se repiten, o durante toda la longitud, se considera como la longitud final del ciclo */
                    while (rep < 5 && i+rep < longitud && repetido){
                        if (decimal[j+rep] != decimal[i+rep]) repetido = false;
                        else rep++;
                    }
                    if (repetido == false){
                        longitud +=rep;
                        j += rep;
                    }
                }
                else if (j == i && !repetido) longitud++;
            }
            i++;
        }
        return longitud;
    }
}
