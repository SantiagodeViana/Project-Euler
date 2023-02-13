bool isPrime(int n){ //Función para determinar si un numero es primo.
    if (n == 1)return false;
    else if (n < 4)return true;
    else if (n % 2 == 0)return false;
    else if (n < 9)return true;
    else if (n % 3 == 0)return false;
    else{
		double r = sqrt(n); 
		int f = 5;         
        while (f <= r){
            if ((n % f) == 0) return false;
            else if (n % (f + 2) == 0) return false;
            else f += 6;                
        }return true;
    }return true;
}
