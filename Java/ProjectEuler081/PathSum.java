public class PathSum {
    public static int minValor(int[][]matriz){
        int N=matriz.length;
        int M=matriz[0].length;
        int[][] valor= new int[2][M];
        valor[(N-1)%2][M-1]=matriz[N-1][M-1];
        for(int c=M-2; c>=0; c--) valor[(N-1)%2][c] = matriz[N-1][c] + valor[(N-1)%2][c+1];
        for(int f=N-2; f>=0; f--) {
            for (int c = M - 1; c >= 0; c--) {
                if (c==M-1) valor[f%2][c] = matriz[f][c] + valor[(f+1)%2][c];
                else valor[f%2][c] = matriz[f][c] + Math.min(valor[(f+1)%2][c],valor[f%2][c+1]);
            }
        }
        return valor[0][0];
    }
}
