//Función usada en Project Euler #23

bool isAbundant(int n){ //Función para determinar si el número es abundante
     if (n < 12) return false; //No hay números abundantes menores de 12
     else if (n % 2 != 0 ) return false; //No hay números abundantes primos ni impares
     else{
          int divisor = 1, total = 0;
          while (divisor <= (n / 2)){              
              if (n%divisor == 0) total += divisor;              
              divisor += 1;
          }if (total > n) return true;
          else if (total <= n) return false;
     }
}
