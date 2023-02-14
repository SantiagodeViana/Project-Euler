/* Revisar
 * Solución para el problema #23 de Project Euler
 * "Encuentra la suma de todos los números enteros positivos que no pueden escribirse como suma de dos números abundantes."
 * https://projecteuler.net/problem=23 */

#include <iostream>
#include <math.h>  
using namespace std;

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

int main (){
    int n, array_size;
    array_size = 28123, n = 0 ;
	int abundant[array_size];
    for (int i = 0; i < array_size; i++){ //Se llena el arreglo de números abundantes
        if (isAbundant(i+1) == true){
           abundant[n] = i+1;
           //cout << abundant[n] << "  "<< n << endl;
           n++;
        }
    }
    array_size = n; //El tamaño del arreglo se reduce a la cantidad de n números abundantes
    int sum, respuesta = 0, menor = 0, mayor = 0;
    for (int number = 1; number <= 28123*2; number++){
        sum = abundant[menor] + abundant[mayor];
        while (number != sum){ //Mientras el número sea diferente a la suma
              if (mayor >= n){
                    mayor = 0;
                    menor ++; //Se vuelven a sumar los números
                    sum = abundant[menor] + abundant[mayor];               
              }if (number != sum){
                 mayor++;
                 sum = abundant[menor] + abundant[mayor];
                 //cout << sum << endl;
                 if (abundant[menor] > abundant[mayor]){
                         respuesta += number, number++;
                         cout << respuesta << endl;
                         mayor = 0, menor = 0;  
                 }         
              }
        }     
    }cout << "La respuesta es " << respuesta << endl;
    return 0;
}

//Suma todos los números impares menores de 28123*2, por propiedad ninguno de estos números es la suma de números abundantes
