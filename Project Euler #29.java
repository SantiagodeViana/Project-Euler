public class Main {
    public static void main(String[] args) {
        double[] soluciones = new double [100 * 100];
        int i = 0, respuesta = 0;
        for (int a = 2; a <= 100; a++){ //Base
            for (int b = 2; b <= 100; b++){ //Exponente
                while(Math.pow(a, b) != soluciones[i] && i < soluciones.length -1) i++; //Confirmando que la potencia no esté repetida
                if (Math.pow(a, b) != soluciones[i]){
                    i=0;
                    while (soluciones[i] != 0 && i < soluciones.length -1) i++;
                    soluciones[i] = Math.pow(a, b);
                }
                i = 0;
            }
        }
        while (soluciones[respuesta] != 0 && i < soluciones.length -1) respuesta++;
        System.out.println("La solucion es: " + respuesta);
    }
}
