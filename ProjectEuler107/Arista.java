public class Arista {
    private static int fila;
    private static int columna;

    public static int getFila(){
        return fila;
    }

    public static int getColumna(){
        return columna;
    }
    public static void setCandidato(int i, int j){
        fila = i;
        columna = j;
    }
}
