#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Solución para el problema #66 de Project Euler
 * "Encuentra el valor de D ≤ 1000 en soluciones mínimas de x para las que se obtiene el mayor valor de x."
 * https://projecteuler.net/problem=66

 * Ecuación de Pell, intenta resolverse mediante el método de Chakravala. Puede continuar intentándose con fracciones continuas
 * Actualmente el código presenta problemas por overflow, ha sido convertido a Python
 */

int main()
{
    //Forma a^2 - Db^2 = k
    int a, b, k, aux, D, m, respuesta = 0;
    long long int x, y, max = 0;
    for (D = 2; D <= 1000; D++){
        a = floor(sqrt(D)); //Comienza escogiéndose el a más cercano de la raíz cuadrada de D
        b = 1; //Comenzamos con un b también pequeño, 1
        k = (a*a) - (D*b*b);
        //Los condiciones de parada pueden ser k = +-1, k=+-2 o k+-4
        //También se contempla el caso en el que D es un cuadrado, donde k = 0 y  no hay soluciones
        while (k != 0 && k != 1 && k != -1){ //&& k != 2 && k != -2 && k != 4 && k != -4
            m = D;
            for (aux = 1; aux <= D; aux++){ //Tiene que buscarse un m tal que |m^2 - D| sea lo menor posible
                if ((((a + b*aux) % k) == 0) && (abs(aux*aux - D) < abs(m*m - D))) m = aux; //m debe ser divisible por la expresión
            }
            //Iteraciones para actualizar valores
            aux = (a * m + D * b) / abs(k);
            b = (a + b * m) / abs(k);
            k = (m * m - D) / k;
            a = aux;
            //printf("Triple: (%d, %d, %d)\n", a, b, k);
        }
        if (k != 0){
            x = ((a * a) + (D * b * b)) / abs(k); // x = a^2 + Dy^2
            y = 2 * a * b; //y = 2ab
        }
        if (x > max){
            max = x;
            respuesta = D; //La respuesta será D que ofrezca el mayor valor de x en el intervalo
        }
        printf("D:%d, x:%lld, Respuesta:%d (x: %lld)\n", D, x, respuesta, max);
    }
    return 0;
}
