#include <iostream>
using namespace std;

/* Solución para el problema #205 de Project Euler
 * "¿Cuál es la probabilidad de que Pyramidal Pete gane a Cubic Colin? Da tu respuesta redondeada a siete decimales de la forma 0.abcdefg"
 * https://projecteuler.net/problem=205 */

int main (){
    int ladosPiramidales[8] {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int ladosCubicos[5] {1, 1, 1, 1, 1, 1};
    int n1 = ladosPiramidales[].length;
    int n2 = ladosCubicos[].length;
    double denominador, numerador, respuesta;
    while (ladosCubicos(0) != 6 && ladosCubicos(1) != 6 && ladosCubicos(2) != 6 && ladosCubicos(3) != 6 && ladosCubicos(4) != 6 && ladosCubicos(5) <= 6 && ladosPiramidales(0) != 4 && ladosPiramidales(1) != 4 && ladosPiramidales(2) != 4 && ladosPiramidales(3) != 4 && ladosPiramidales(4) != 4 && ladosPiramidales(5) != 4 && ladosPiramidales(6) != 4 && ladosPiramidales(7) != 4 && ladosPiramidales(8) != 4){ 
          if (ladosPiramidales(0) != 4 && ladosPiramidales(1) != 4 && ladosPiramidales(2) != 4 && ladosPiramidales(3) != 4 && ladosPiramidales(4) != 4 && ladosPiramidales(5) != 4 && ladosPiramidales(6) != 4 && ladosPiramidales(7) != 4 && ladosPiramidales(8) != 4){
             while (ladosCubicos(n2) > 6){
                   ladosCubicos(n2) = 1;
                   n2 --;
                   ladosCubicos(n2) ++;
                   if (ladosCubicos(n2) <= 6) n2 = ladosCubicos.Length - 1;
                   denominador ++;
             }
          ladosPiramidales(0) = 1, ladosPiramidales(1) = 1, ladosPiramidales(2) = 1, ladosPiramidales(3) = 1, ladosPiramidales(4) = 1, ladosPiramidales(5) = 1, ladosPiramidales(6) = 1, ladosPiramidales(7) = 1, ladosPiramidales(8) = 1;
          cout << ladosPiramidales(0) << ladosPiramidales(1) << ladosPiramidales(2) << ladosPiramidales(3) << ladosPiramidales(4) << ladosPiramidales(5) << ladosPiramidales(6) << ladosPiramidales(7) << ladosPiramidales(8) << "   " << ladosCubicos(0) << ladosCubicos(1) << ladosCubicos(2) << ladosCubicos(3) << ladosCubicos(4) << ladosCubicos(5) << "   " << numerador << "   " << denominador << "   " << respuesta;
          ladosCubicos(n2) ++
          }
          while ladosPiramidales(n1) > 4{
                ladosPiramidales(n1) = 1;
                n1 --;
                ladosPiramidales(n1) ++;
                if (ladosPiramidales(n1) <= 4) n1 = ladosPiramidales.Length - 1                
          }
          if (ladosPiramidales(0) + ladosPiramidales(1) + ladosPiramidales(2) + ladosPiramidales(3) + ladosPiramidales(4) + ladosPiramidales(5) + ladosPiramidales(6) + ladosPiramidales(7) + ladosPiramidales(8)) > (ladosCubicos(0) + ladosCubicos(1) + ladosCubicos(2) + ladosCubicos(3) + ladosCubicos(4) + ladosCubicos(5)) numerador ++ //Segundo bucle: Determina el numerador
          denominador ++;
          respuesta = numerador / denominador;
          ladosPiramidales(n1) ++;
        }        
        cout << "La respuesta es: " << respuesta;
        return 0;
}
