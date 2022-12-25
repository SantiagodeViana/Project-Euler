public class Main {
    // Solución para el problema #5 de Project Euler
    // "¿Cuál es el menor número positivo divisible por todos los números del 1 al 20?"
    // https://projecteuler.net/problem=5
    public static void main(String[] args) {
        int respuesta = 20;
        boolean aceptable = false; //Boolean para reconocer respuesta
        while (!aceptable){
            boolean multiplo = true; //Boolean para analizar que el candidato sea múltiplo de todos los números
            for (int i = 2; i <= 20 && multiplo; i++) {
                if (respuesta % i != 0) multiplo = false;
            }
            if (multiplo) aceptable = true;
            else respuesta += 20;
        }
        System.out.println("La respuesta es: " + respuesta);
    }
}
