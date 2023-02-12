public class Resilience {
    public static int resilientRatio (int n){
        int ratio = 0;
        for (int i = 1; i <= n; i++){
            if (Resilience.isCoprimo(i, n)) ratio++;
            if ((double) i/ (double) (n-1) > 15499.0/94744.0) return (n-1); //Modificado para parar búsquedas al superar objetivo
        }
        return ratio;
    }

    public static boolean isCoprimo (int n, int m){ //Regresa MCD de a y b, donde 0 < b <= a
        int a = n, b = m, resto = -1; //De manera predeterminada se asume que n es mayor que m
        if (a == b) resto = a; //Si a = b, son iguales al MCD
        if (a < 0) a *= (-1); //Si a es negativo, se convierte en positivo
        if (b < 0) a *= (-1); //Si b es negativo, se convierte en positivo
        else if (n < m){ //Si n es menor que m,
            a = m;
            b = n;
        }
        while ((a != 0) && (b != 0) && (a != 1) && (b != 1) && (a % b != 0)){ //Los restos se van turnando, de mayor a menor; // && (b % a != 0 &&
            if ((b != 0) && (a != 1) && (b != 1)) a = (a % b);
            if ((a != 0) && (a != 1) && (b != 1)) b = (b % a);
        }
        if (b == 0) resto = a; //En el caso de los pares, devolver el resto diferente de 0
        else if (a == 0) resto = b; //En el caso de los pares, devolver el resto diferente de 0
        else if (a < b) resto = a;
        else if (b < a) resto = b;
        if (resto == 1) return true;
        else return false;
    }

    public static boolean esPrimo(int n){//Función para determinar si un número es primo, basada en la Criba de Eratóstenes
        if (n == 1) return true; //Cambiar a 0 o mantener a conveniencia del programa
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
