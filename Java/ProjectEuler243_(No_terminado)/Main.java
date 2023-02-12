public class Main {
    public static void main (String[] args) {
        int respuesta = Integer.MAX_VALUE, i = 1; //25605369 - primos; 9203787 - impares probados
        double meta = 15499.0/94744.0, aux; //Se declara el radio objetivo; aux es una variable temporal que almacenarà los radios paulatinamente
        do{ //meta = 0.1635881955585578
            //if (Resilience.esPrimo(i)){ //Se analizan números primos, que tienen probabilidades de tener más coprimos
            aux = (double) Resilience.resilientRatio(i) / (double) (i-1); //Radio de fracciones resilientes
            if (aux < meta) respuesta = i; // (aux < meta)
            //System.out.println("Una posible solución es " + i + ": Radio=" + Resilience.resilientRatio(i) + "/" + (i - 1));
            //}
            i += 2;
            //System.out.println(i + ": Radio=" + Resilience.resilientRatio(i) + "/" + (i - 1));
            if (i % 999 == 0) System.out.println("i:" + i);
        } while (respuesta == Integer.MAX_VALUE);
        System.out.println("La respuesta es: " + respuesta);
    }
}
