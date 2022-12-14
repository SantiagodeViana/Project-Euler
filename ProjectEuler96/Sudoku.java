public class Sudoku {
    public static int solucion(int[][]matriz, boolean[][]visitados) {
        int respuesta = 0;
        Matriz.inicializarVisitados(matriz, visitados);
        solucionAux(matriz, visitados, 0, 0);

        for (int j = 0; j < 2; j++) {
            if (j == 0) respuesta += (matriz[0][j] * 100);
            else if (j == 1) respuesta += (matriz[0][j] * 10);
            else if (j == 2) respuesta += (matriz[0][j]);
        }

        return respuesta;
    }

    public static boolean solucionAux(int[][]matriz, boolean[][]visitados, int fila, int columna) {
        int valor = 1;
        int i = fila, j= columna;
        boolean solucion = false;
        if (visitados[visitados.length - 1][visitados.length - 1]) {
            solucion = true;
        } else {
            for (; i < matriz.length; i++) { //Se empiezan todos los caminos
                for (; j < matriz.length; j++) {
                    while (!visitados[i][j] && valor < 10 && !solucion) { //Considerando todos los posibles candidatos para rellenar casilla
                        if (Sudoku.factible(matriz, valor, i, j)) {
                            visitados[i][j] = true;
                            matriz[i][j] = valor;
                            solucion = solucionAux(matriz, visitados, i, j);
                            if (!solucion) {
                                matriz[i][j] = 0;
                                visitados[i][j] = false;
                            }
                        }
                        valor++;
                    }
                }
                j=0;
            }
        }
        return solucion;
    }

    public static boolean factible(int[][] matriz, int valor, int fila, int columna) {
        boolean aceptable = true;
        int i = 0, j = 0;
        while (aceptable && ((i < matriz.length-1) || (j < matriz.length-1))) { //Comprobación para evitar repeticiones en fila o columna
            if (matriz[fila][j] == valor || matriz[i][columna] == valor) aceptable = false;
            if (j < matriz.length - 1) j++; //Moviendo columnas para verificar
            else if (i < matriz.length - 1) i++; //Moviendo filas para verificar
        }
        //Reiniciando contadores
        i = 0;
        j = 0;
        //Manipulando valores para determinar cuadrante:
        fila /= 3;
        columna /= 3;
        fila *= 3;
        columna *= 3;
        while (aceptable && ((i < 2) || (j < 2))) { //Comprobación para evitar repeticiones en un mismo cuadrante
            if (matriz[fila + i][columna + j] == valor) aceptable = false;
            if (j < 2) j++;
            else{
                j = 0;
                i++;
            }
        }
        return aceptable;
    }
}
