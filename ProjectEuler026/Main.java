public class Main {
    public static void main(String[] args) {
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
    }
}
