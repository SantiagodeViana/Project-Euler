//Función usada en Project Euler #21 y mencionada en #95

int amicablePair(int n, int m){ //La función confirma si la suma de los divisores del par introducido es igual al otro número, formando un "par amigable"
    return ((divSum(n) == m) && (divSum(m) == n));
}
