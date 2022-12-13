public class Sudoku {
    public static void solucion(int[][]matriz, boolean[][]visitados) {
        solucionAux(matriz, visitados, 0, 0);
    }

    public static void solucionAux(int[][]matriz, boolean[][]visitados, int fila, int columna) {
        int valor = 1;
        if (fila == matriz.length - 1 && columna == matriz.length - 1) {
            Matriz.printValores(matriz);
            //System.out.println("Se ha encontrado una solución");
        } else {
            for (int i = fila; i < matriz.length; i++) { //Se empiezan todos los caminos
                for (int j = columna; j < matriz.length; j++) {
                    while (!visitados[i][j] && valor < 10 && !visitados[i][j]) { //Considerando todos los posibles candidatos para rellenar casilla
                        if (Sudoku.factible(matriz, valor, i, j)) {
                            visitados[i][j] = true;
                            matriz[i][j] = valor;
                            solucionAux(matriz, visitados, i, j);
                            visitados[i][j] = false;
                        }
                        valor++;
                    }
                }
            }
        }
    }

    public static boolean factible(int[][] matriz, int valor, int fila, int columna) {
        boolean aceptable = true;
        int i = 0, j = 0;
        while (aceptable && ((i < matriz.length) && (j < matriz.length))) {
            if (matriz[fila][j] == valor || matriz[i][columna] == valor) aceptable = false;
            if (j < matriz.length) j++;
            else if (i < matriz.length) i++;
        }
        return aceptable;
    }
}
