public class PrimeSet {

    /* Optimiza el tiempo de ejecición a O(log(n)), pero no puede acceder a primos mayores a los elementos del array

    public static boolean busquedaBinaria(int[] primos, int n){;
        if (n < 0 || n > primos[primos.length-1]) return false;
        else return busquedaBinariaAux(primos, n, 0, primos.length-1);
    }
    public static boolean busquedaBinariaAux(int[] primos, int n, int io, int iN){
        boolean encontrado = false;
        int i = 0;
        int k = (iN+io) / 2;
        if (io == iN){
            if (n != primos[k]) return false;
        }
        if (n == primos[k]) return true;
        else{
            while (!encontrado && io != iN){
                if (n <= primos[k]) return busquedaBinariaAux(primos, n, io, k);
                else return busquedaBinariaAux(primos, n, k+1, iN);
            }
        }
        return encontrado;
    }*/

    public static boolean concatenatedPair(int n1, int n2){
        boolean pairSet = false;
        int cifras = 10, aux, cadena;
        while (cifras < n1) cifras *= 10;
        aux = n2 * cifras;
        cadena = aux + n1;
        //System.out.println(cadena);
        if (esPrimo(cadena)){
            cifras = 10;
            while (cifras < n2) cifras *= 10;
            aux = n1 * cifras;
            cadena = aux + n2;
            //System.out.println(cadena);
            pairSet = esPrimo(cadena);
        }
        return pairSet;
    }

    private static boolean esPrimo(int n){//Función para determinar si un número es primo, basada en la Criba de Eratóstenes
        if (n == 1) return true; ////*Cambiar a 0 o mantener a conveniencia del programa
        else if (n < 4) return true; //Si son menores de 4, son primos
        else if (n % 2 == 0) return false; //Si son pares, no son primos
        else if (n < 9) return true; //Si son menores de 9 e impares, son primos
        else if (n % 3 == 0) return false; //Si son múltiplos de 3, no son primos
        else{
            int r = (int) Math.floor(Math.sqrt(n));
            int f = 5;
            while (f <= r){
                if (n % f == 0) return false;
                else if (n % (f + 2) == 0) return false;
                else f += 6;
            }
            return true;
        }
    }
}
