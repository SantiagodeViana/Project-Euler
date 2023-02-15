import java.util.HashMap;
import java.util.Map;

/* Solución para el problema #26 de Project Euler
 * "Encuentra el valor de d < 1000 para el que 1/d contiene el ciclo recurrente más largo en su parte de fracción decimal"
 * https://projecteuler.net/problem=26 */

public class Main {
    public static void main(String[] args) {
        int respuesta = 0;
        for (int i = 2; i < 1000; i++) {
            if (Ciclo.longitudCiclo(i) > respuesta) {
                System.out.println("Una posible respuesta es: " + i);
                respuesta = i;
            }
        }
        System.out.println("La respuesta es: " + respuesta);
    }
}
