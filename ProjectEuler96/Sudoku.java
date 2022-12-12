public class Sudoku {
    public static void printValores(int matriz[][]){
        int N = matriz.length;
        for (int i = 0; i < N; i++) { //Inicializando matriz de visitados
            if ((i) % 3 == 0) System.out.println("______________________________");
            for (int j = 0; j < N; j++){
                if (j % 3 == 0) System.out.print("|");
                System.out.print(" " + matriz[i][j] + " ");
                if (j == N-1) System.out.print("|");
            }
            System.out.println();
            if (i == N-1) System.out.println("______________________________");
        }
    }
    public static void printVisitados (boolean visitados[][]){
        int N = visitados.length;
        for (int i = 0; i < N; i++) { //Inicializando matriz de visitados
            if ((i) % 3 == 0) System.out.println("______________________________");
            for (int j = 0; j < N; j++){
                if (j % 3 == 0) System.out.print("|");
                if (visitados[i][j] == true) System.out.print(" T ");
                else System.out.print(" F ");
                if (j == N-1) System.out.print("|");
            }
            System.out.println();
            if (i == N-1) System.out.println("______________________________");
        }
    }
}
        /*
        public static int solucion(int[][]matriz, boolean[][]visitados) {
            int valorAcumulado = 0;
            for (int i = 0; i < matriz.length - 1; i++){ //Se empiezan todos los caminos
                visitados[i][0] = true;
                valorAcumulado += matriz[i][0];
                System.out.println("Analizando fila " + i + "...");
                SudokuAux(matriz, visitados, 0, 0, sol, valorAcumulado);
                valorAcumulado -= matriz[i][0];
                visitados[i][0] = false;
            }
            return sol.getSolucion();
        }

        public static void solucionAux(int[][]matriz, boolean[][]visitados, int nivel, int i, Solucion sol, int valorAcumulado){
            if (nivel == matriz.length - 1) {

            } else {
                for (int c = 0; c < 3; c++) { // c=0 : Derecha ; c=1 : Arriba; c=2 : Abajo
                    if (c == 0 && i > 0 && !visitados[i - 1][nivel]) i--;
                    else if (c == 1 && nivel < matriz.length - 1 && !visitados[i][nivel + 1]) nivel++;
                    else if (c == 2 && i < matriz.length - 1 && !visitados[i + 1][nivel]) i++;
                    //Optimizando: aceptando solo pasos con posibles soluciones menores
                    if (!visitados[i][nivel] && (valorAcumulado < sol.getSolucion()) && (valorAcumulado < 1159)){ //((valorAcumulado < sol.getSolucion()) && (valorAcumulado < 351202))
                        visitados[i][nivel] = true;
                        valorAcumulado += matriz[i][nivel];
                        minValorAux(matriz, visitados, nivel, i, sol, valorAcumulado);
                        visitados[i][nivel] = false;
                        valorAcumulado -= matriz[i][nivel];
                        if (c == 0) i++;
                        else if (c == 1) nivel--;
                        else if (c == 2) i--;
                    }
                }
            }
        }
    }
}
*/