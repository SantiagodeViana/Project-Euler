public class PathSum {
    public static int minValor(int[][]matriz, boolean[][]visitados) {
        int valorAcumulado = 0;
        Solucion sol = new Solucion(Integer.MAX_VALUE);
        for (int i = 0; i < matriz.length - 1; i++){ //Se empiezan todos los caminos
            visitados[i][0] = true;
            valorAcumulado += matriz[i][0];
            System.out.println("Empezando desde fila " + i + "...");
            minValorAux(matriz, visitados, 0, 0, sol, valorAcumulado);
            valorAcumulado -= matriz[i][0];
            visitados[i][0] = false;
        }
        return sol.getSolucion();
    }
    public static void minValorAux(int[][]matriz, boolean[][]visitados, int nivel, int i, Solucion sol, int valorAcumulado){
        if (nivel == matriz.length - 1) {
            if (valorAcumulado < sol.getSolucion()){
                sol.setSolucion(valorAcumulado);
                System.out.println("Una posible solución es: " + sol.getSolucion());
            }
        } else {
            for (int c = 0; c < 3; c++) {
                if (c == 0 && i > 0 && !visitados[i - 1][nivel]) i--;
                else if (c == 1 && nivel < matriz.length - 1 && !visitados[i][nivel + 1]) nivel++;
                else if (c == 2 && i < matriz.length - 1 && !visitados[i + 1][nivel]) i++;
                //Optimizando: aceptando solo pasos con posibles soluciones menores
                if (!visitados[i][nivel] && (valorAcumulado < sol.getSolucion()) && (valorAcumulado < 150000)){ //150000 es un límite arbitrario que busca limitar búsquedas y conseguir una solución menor
                    visitados[i][nivel] = true;
                    valorAcumulado += matriz[i][nivel];
                    minValorAux(matriz, visitados, nivel, i, sol, valorAcumulado);
                    visitados[i][nivel] = false;
                    valorAcumulado -= matriz[i][nivel];
                    if (c == 0) i++; //c=0: Derecha
                    else if (c == 1) nivel--; //c=1: Arriba
                    else if (c == 2) i--; //c=2: Abajo
                }
            }
        }
    }
}
