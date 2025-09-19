//Función usada en Project Euler #71, #72 y #73

int isCoprime(int n, int m){ //Determina si un par de números son coprimos
    int i, menor;
    if (n > m) menor = m;
    else menor = n; //Declarando menor número
    if (n == 1) return 1; //Caso ad hoc, borrar después: 1 será coprimo de todos los denominadores
    else if (n == m) return 0; //Si son iguales no son coprimos
    else if (n % 2 == 0 && m % 2 == 0) return 0; //Abreviación: Si ambos son pares, no lo son
    else if (n % 3 == 0 && m % 3 == 0) return 0; //Múltiplos de 3
    else if (n % 5 == 0 && m % 5 == 0) return 0; //Múltiplos de 5
    else if (n % 7 == 0 && m % 7 == 0) return 0; //Múltiplos de 7
    else if (n > m && n % m == 0) return 0;
    else if (n < m && m % n == 0) return 0; //Si un número es divisor del otro, no son coprimos
    else if (isPrime(n) == 1 && isPrime(m) == 1) return 1;
    else{
        for (i=11; i <= menor; i+= 6){ //Se buscan factores primos
            if ((n%i==0 && m%i==0)) return 0; //Si los números comparten un primo como divisor, no son coprimos
            else if ((n%(i+2)==0 && m%(i+2)==0)) return 0;
        }
        return 1; //De lo contrario, sí lo son
    }
}
