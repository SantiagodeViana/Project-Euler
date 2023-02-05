import java.util.HashMap;
import java.util.Map;

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
