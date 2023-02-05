import java.util.HashMap;
import java.util.Map;

public class Ciclo { //Implementación de mapa de hash basado en http://www.javaproblems.com/2013/11/project-euler-problem-26-reciprocal_27.html
    public static int longitudCiclo(int n) {
        Map<Integer, Integer> iToLong = new HashMap<Integer, Integer>();
        int i = 1, longitud = 0;
        while (!iToLong.containsKey(i)) {
            iToLong.put(i, longitud);
            i = i * 10 % n;
            longitud++;
        }
        return longitud - iToLong.get(i);
    }
}
