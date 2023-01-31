public class PrimeSet {
    public static boolean concatenatedPairSet(int[] primos, int n1, int n2, int n3, int n4, int n5, int N){
        boolean pairSet = true;
        int cifras = 10, aux, cadena, i = 0, j;
        int [] set= {n1, n2, n3, n4, n5};
        while (pairSet && i < set.length){
            j = i+1;
            while (pairSet && j < set.length) { //Concadenando desde la derecha
                while (cifras < set[i]) cifras *= 10;
                aux = set[j] * cifras;
                cadena = aux + set[i];
                //System.out.println(cadena);
                if (busquedaBinaria(primos, cadena, N)) { //Concadenando desde la izquierda
                    cifras = 10; //Reiniciando contador de cifras
                    while (cifras < set[j]) cifras *= 10;
                    aux = set[i] * cifras;
                    cadena = aux + set[j];
                    //System.out.println(cadena);
                    if (!busquedaBinaria(primos, cadena, N)) return false;
                }
                else return false;
                cifras = 10; //Reiniciando contador de cifras
                j++;
            }
            i++;
        }
        return pairSet;
    }

    public static boolean busquedaBinaria(int[] primos, int n, int N){
        if (n < 0 || n > primos[N]) return false;
        else return busquedaBinariaAux(primos, n, 0, N);
    }

    public static boolean busquedaBinariaAux(int[] primos, int n, int io, int iN){
        boolean encontrado = false;
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
    }

    public static boolean esPrimo(int n){//Función para determinar si un número es primo, basada en la Criba de Eratóstenes
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
