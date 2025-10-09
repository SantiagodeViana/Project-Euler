public class Main {
    public static void main(String[] args) {
        /* Solución para el problema #83 de Project Euler
         *
         *  https://projecteuler.net/problem=83    */

        int N = matriz.length;
        boolean[][] visitados = new boolean [N][N];
        for (int i = 0; i < N; i++) { //Inicializando matriz de visitados
            for (int j = 0; j < N; j++){
                if (i == 0 && j == 0) visitados[i][j] = false;
            }
        }

        System.out.println("La solución es final es: " + PathSum.minValor(matriz, visitados));
    }
}
