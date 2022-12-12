public class Main {
    public static void main(String[] args) {
        /*  Solución para el problema #96 de Project Euler
         *  https://projecteuler.net/problem=96          */

        int [][] matriz = {{0, 0, 3, 0, 2, 0, 6, 0, 0}, {9, 0, 0, 3, 0, 5, 0, 0, 1}, {0, 0, 1, 8, 0, 6, 4, 0, 0}, {0, 0, 8, 1, 0, 2, 9, 0, 0}, {7, 0, 0, 0, 0, 0, 0, 0, 8}, {0, 0, 6, 7, 0, 8, 2, 0, 0}, {0, 0, 2, 6, 0, 9, 5, 0, 0}, {8, 0, 0, 2, 0, 3, 0, 0, 9}, {0, 0, 5, 0, 1, 0, 3, 0, 0}};
        int N = matriz.length;
        boolean[][] visitados = new boolean [N][N];

        Matriz.inicializarVisitados(matriz, visitados);
        Matriz.printValores(matriz);
        Matriz.printVisitados(visitados);

        //System.out.println("La solución es final es: " + Sudoku.Solucion(matriz, visitados));
    }
}

/*
        for (int i = 0; i < N; i++) { //Inicializando matriz de visitados
            if ((i) % 3 == 0) System.out.println("______________________________");
            for (int j = 0; j < N; j++){
                if (matriz[i][j] == 0) visitados[i][j] = true;
                else visitados[i][j] = false;
                if (j % 3 == 0) System.out.print("|");
                System.out.print(" " + matriz[i][j] + " ");
                if (j == N - 1) System.out.print("|");
            }
            System.out.println();
            if (i == N-1) System.out.println("______________________________");
        }
 */
