public class PathSum {
    public static int minValor(int[][]matriz, boolean[][]visitados) {
        int valorAcumulado = 0;
        Solucion sol = new Solucion(Integer.MAX_VALUE);
        for (int i = 0; i < matriz.length - 1; i++){ //Se empiezan todos los caminos
            visitados[i][0] = true;
            valorAcumulado += matriz[i][0];
            System.out.println("Empezando desde fila " + i + "...");
            MatrixDebugger.show(visitados, i, 0, valorAcumulado, sol.getSolucion(), -1, "Start row marked; before initial recursive call"); // DEBUG
            minValorAux(matriz, visitados, 0, 0, sol, valorAcumulado);
            valorAcumulado -= matriz[i][0];
            visitados[i][0] = false;
            MatrixDebugger.show(visitados, i, 0, valorAcumulado, sol.getSolucion(), -1, "Start row unmarked"); // DEBUG
        }
        return sol.getSolucion();
    }
    public static void minValorAux(int[][]matriz, boolean[][]visitados, int nivel, int i, Solucion sol, int valorAcumulado){
        MatrixDebugger.show(visitados, i, nivel, valorAcumulado, sol.getSolucion(), -1, "Enter minValorAux"); // DEBUG
        if (nivel == matriz.length - 1) {
            if (valorAcumulado < sol.getSolucion()){
                sol.setSolucion(valorAcumulado);
                MatrixDebugger.show(visitados, i, nivel, valorAcumulado, sol.getSolucion(), -1, "After sol.setSolucion"); // DEBUG
                System.out.println("Una posible solución es: " + sol.getSolucion());
            }
        } else {
            for (int c = 0; c < 3; c++) {
                if (c == 0 && i > 0 && !visitados[i - 1][nivel]) i--;
                else if (c == 1 && nivel < matriz.length - 1 && !visitados[i][nivel + 1]) nivel++;
                else if (c == 2 && i < matriz.length - 1 && !visitados[i + 1][nivel]) i++;
                MatrixDebugger.show(visitados, i, nivel, valorAcumulado, sol.getSolucion(), c, "After direction conditions; before visit condition"); // DEBUG
                //Optimizando: aceptando solo pasos con posibles soluciones menores
                if (!visitados[i][nivel] && (valorAcumulado < sol.getSolucion()) && (valorAcumulado < 150000)){ //150000 es un límite arbitrario que busca limitar búsquedas y conseguir una solución menor
                    visitados[i][nivel] = true;
                    valorAcumulado += matriz[i][nivel];
                    MatrixDebugger.show(visitados, i, nivel, valorAcumulado, sol.getSolucion(), c, "Marked and added; before recursive call"); // DEBUG
                    minValorAux(matriz, visitados, nivel, i, sol, valorAcumulado);
                    MatrixDebugger.show(visitados, i, nivel, valorAcumulado, sol.getSolucion(), c, "Returned from recursive call"); // DEBUG
                    visitados[i][nivel] = false;
                    valorAcumulado -= matriz[i][nivel];
                    MatrixDebugger.show(visitados, i, nivel, valorAcumulado, sol.getSolucion(), c, "Unmarked and subtracted"); // DEBUG
                    if (c == 0) i++; //c=0: Derecha
                    else if (c == 1) nivel--; //c=1: Arriba
                    else if (c == 2) i--; //c=2: Abajo
                    MatrixDebugger.show(visitados, i, nivel, valorAcumulado, sol.getSolucion(), c, "After coordinate restoration"); // DEBUG
                }
            }
        }
    }
}
