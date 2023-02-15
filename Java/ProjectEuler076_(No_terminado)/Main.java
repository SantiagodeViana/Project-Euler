/* Solución para el problema #76 de Project Euler
 * "¿De cuántas formas distintas se pueden escribir cien como suma de al menos dos números enteros positivos?"
 * https://projecteuler.net/problem=76 */ 

public class Main {
    public static void main(String[] args) {
        int n = 5;
        int[] sumandos = new int[n];
        System.out.println(n + " tiene " + Suma.sumWays(sumandos, n) + " sumandos");
    }
}
