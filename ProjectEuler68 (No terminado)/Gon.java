public class Gon {
    private static int valor;
    private static boolean[][] visitados = {{false, true, true, false, true, false}, {true, false, true, false, false, true}, {true, true, false, true, false, false}, {false, false, true, false, false, false}, {true, false, false, false, false, false}, {false, true, false, false, false, false}};
    private static int [] gon = new int [6];
    public static int getValor(){
        return valor;
    }
    public static void setValor(int n){
        valor = n;
    }
}
