public class Suma {
    /* Recibe un entero y un array del tamaño del entero;
     * Devuelve la cantidad de maneras posibles de sumarlo
     * Método mediante fuerza bruta
     */
    public static int sumWays(int [] sumandos, int n){
        /* N denota la cantidad de posibles sumandos en el momento, empezando por 2;
         * Es diferente a sumandos.length
         * "Respuesta" son las posibles formas de sumar la entrada;
         * Empieza en 1, porque todos los enteros se pueden expresar como (1 + 1 + ... + 1)
         */
        int N = 1, suma = n, respuesta = 0, i = 0;
        sumandos[0] = n;
        while (N != n) { //Ejecución mientras no se llegue a la mínima expresión de los sumandos
            if (suma == n) {
                respuesta++; //Cuando los sumados coinciden con la entrada, se ha conseguido una manera
                if (sumandos[N - 1] >= n - 1) {
                    N++; //Se amplía la cantidad de posibles sumandos de ser necesario
                    suma = N; //Al ser inicializada, la suma va a ser igual al número de sumandos (la cantidad de 1s)
                    for (i = 0; i < N; i++) sumandos[i] = 1; //Reiniciando posibles sumandos
                }
                if (sumandos[i] >= n-1) sumandos[i] = 1; //Reiniciando posición anterior
                if (i < N-1) i++; //Si no se ha llegado al último índice, se continúa
                if (sumandos[i] < n) sumandos[i]++; //
                suma = 0;
                for (i = 0; i< N; i++) suma += sumandos[i];
            }
            i = 0; //Se recorre el array de izquierda a derecha
            sumandos[i]++; //Si la suma sigue siendo menor, se siguen buscando
            suma++;
        }
        return respuesta;
    }
}
