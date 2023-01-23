public class Arbol {
    public static void inicializar(int matriz[][], boolean visitados[][]) {
        int N = visitados.length;
        for (int i = 0; i < N; i++) { //Inicializando matriz de aristas visitadas
            for (int j = 0; j < N; j++) {
                visitados[i][j] = false;
            }
        }
    }
    public static void printValores(int matriz[][]){
        int N = matriz.length;
        for (int i = 0; i < N; i++) { //Inicializando matriz de visitados
            for (int j = 0; j < N; j++){
                System.out.print("|");
                if (matriz[i][j] == Integer.MAX_VALUE) System.out.print(" -- ");
                else System.out.print(" " + matriz[i][j] + " ");
            }
            System.out.print("|");
            System.out.println();
        }
    }
    /*public static boolean buscarCiclos(int matriz[][], boolean[][]){
        boolean ciclico = false;

        return ciclico;
    }*/
}
