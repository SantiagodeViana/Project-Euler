public class Main {
    public static void main (String[] args){
        //Lista de primos de hasta 8 dígitos; permitirá un acceso estático para mejorar la rapidez del programa
        int [] primos = new int[100000000];
        int respuesta = Integer.MAX_VALUE, p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0, N = 0;
        for (int i = 2; i <= 100000000; i++){ //Rellenando lista
            if (PrimeSet.esPrimo(i)){
                primos[N] = i;
                N++;
            }
            if (i % 1000000 == 0) System.out.println("Rellenando array de primos (" + i/1000000 + "%)");
        }
        System.out.println("Array rellenado"); //N=5761457 
        for (int a = 0; a < 1000; a++){ //Último primo de 4 dígitos en i: 1230; 7-1000 
            System.out.println("a= " + a);
            for (int b = a+1; b < 1000; b++){
                for (int c = b+1; c < 1000; c++){
                    for (int d = c+1; d < 1000; d++){
                        for (int e = d+1; e < 1000; e++){
                            if (primos[a] + primos[b] + primos[c] + primos[d] + primos[e]< respuesta) {
                                if (PrimeSet.concatenatedPairSet(primos, primos[a], primos[b], primos[c], primos[d], primos[e], N)){
                                    respuesta = primos[a] + primos[b] + primos[c] + primos[d] + primos[e];
                                    p1 = primos[a];
                                    p2 = primos[b];
                                    p3 = primos[c];
                                    p4 = primos[d];
                                    p5 = primos[e];
                                    System.out.println("Una posible respuesta es: " + respuesta + " (" + p1 + "+" + p2 + "+" + p3 + "+" + p4 + "+" + p5 +")");
                                }
                            }
                        }
                    }
                }
            }
        }
        System.out.println("La respuesta es: " + respuesta + " (" + p1 + "+" + p2 + "+" + p3 + "+" + p4 + "+" + p5 +")");
    }
}
