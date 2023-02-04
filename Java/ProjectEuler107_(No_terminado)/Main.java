public class Main {
    public static void main(String[] args){
        /* Solución para el problema #107 de Project Euler
         * "Encuentra el ahorro máximo que se puede conseguir eliminando las aristas redundantes y
         * garantizando al mismo tiempo que la red siga conectada."
         * https://projecteuler.net/problem=107            */

        int arbol[][] = {{Integer.MAX_VALUE, 16, 12, 21, Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE},
                {16, Integer.MAX_VALUE, Integer.MAX_VALUE, 17, 20, Integer.MAX_VALUE, Integer.MAX_VALUE},
                {12, Integer.MAX_VALUE, Integer.MAX_VALUE, 28, Integer.MAX_VALUE, 31, Integer.MAX_VALUE},
                {21, 17, 28, Integer.MAX_VALUE, 18, 19, 23},
                {Integer.MAX_VALUE, 20, Integer.MAX_VALUE, 18, Integer.MAX_VALUE, Integer.MAX_VALUE, 11},
                {Integer.MAX_VALUE, Integer.MAX_VALUE, 31, 19, Integer.MAX_VALUE, Integer.MAX_VALUE, 27},
                {Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, 23, 11, 27, Integer.MAX_VALUE}};

        int N = arbol.length;
        boolean[][] arbolMinimo = new boolean [N][N];
        boolean[][] visitados = new boolean [N][N];
        Arbol.inicializar(arbol, visitados); //Inicializando matriz de aristas evaluadas
        Arbol.inicializar(arbol, arbolMinimo); //Inicializando matriz de relación del árbol mínimo
        int candidato = Integer.MAX_VALUE; //Variable para escoger la menor arista

        /* Implementación del algoritmo de Kruskal:
         * Mientras no se haya encontrado al árbol mínimo, se buscan las aristas de menor valor
         * Se evitan los ciclos
         */

        for (int i = 0; i < N; i++){
            /* Sólo se necesita explorar una diagonal de la matriz porque el grafo no es direccionado,
             * lo que quiere decir que la matriz de relaciones es simétrica. */
            for (int j = 0; j < i; j++){
                if (!visitados[i][j] && candidato > arbol[i][j]){
                    candidato = arbol[i][j];
                    Arista.setCandidato(i, j);
                }
            }
        }

        Arbol.printValores(arbol);
        System.out.println("La respuesta es: ");
    }
}
