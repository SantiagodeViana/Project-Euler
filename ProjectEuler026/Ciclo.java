public class Ciclo {
   public static int longitudCiclo(double n){ //Método para determinar longitud de ciclo recurrente. Recibe double como entrada
       boolean repetido = false;
       int i = 0, N = 16, longitud = 0; //N: tamaño array; longitud: mide el ciclo;
       int [] decimal = new int [N];
       decimal[0] = -1;
       double j = 1.0;
       while (j < N && !repetido){
           j++;
           n *= 10.0;
           if (i != 0) n -= decimal[i-1] * 10; //En caso de haber empezado el bucle, uno sólo se queda con una unidad
           decimal[i] = (int) (n % 10); //Se adquiere un decimal al mismo tiempo
           for (int k = 0; k <= i && !repetido; k++){ //Bucle para comprobar repeticiones en el ciclo
               if (decimal[k] == decimal[i]) repetido = true;
               else if (k == i) longitud++;
           }
           System.out.println("La longitud del ciclo es: " + Ciclo.longitudCiclo());
           i++;
       }
        return longitud;
    }

    /*
        double respuesta, aux;
        respuesta = 1.0 / 7.0;
        int N = 16;
        int [] decimal = new int [N];
        int i = 0;
        aux = respuesta;
        for (double j = 1.0; j < N; j++){
            aux *= 10.0;
            if (i != 0) aux -= decimal[i-1] * 10;
            decimal[i] = (int) (aux % 10);
            i++;
            System.out.println("Fracción: " + aux);
        }
        System.out.print("Parte decimal: ");
        for (i = 0; i < N; i++) System.out.print(decimal[i] + ", ");
     */
}
