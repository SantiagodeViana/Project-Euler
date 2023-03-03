#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Euclides (int n, int m); //Algoritmo de Euclides

/* PROJECT EULER 66:

 * El teorema de Bezout garantiza que siempre existirá una ecuación tal que ax + by = d
 * Sabemos también que d es el MCD(a, b), y por lo tanto, cuando d es igual a 1, a y b son números coprimos
 * En este problema, la ecuación diafántica ofrecida es x2 - Dy2 = 1

 * Pero se pueden establecer las siguientes condiciones:

 * 1) Se descartan los valores de D cuando sea un cuadrado
 * 2) Según el teorema de Bezout, "x" y "y" tienen que ser números coprimos
 * 3) Tenemos la certeza de que la ecuación tiene infinitas soluciones, por lo que basta con detener el programa
    cuando la ecuación se cumpla y quedarse con el valor de x

*/

int main()
{
    int i=1, j=1, D, max = 0, respuesta = 0, N; //Sea i "x", j "y"; Sean 'x' y 'y' valores auxiliares para guardar soluciones; x = 0, y = 0
    //aux = 0, limite = 1
    for (D=2; D<=1000; D++){ //Todos los valores de D menores o iguales
    //D: 9, 52, 1000
        if ((D != 4 && D != 9 && D != 16 && D != 25 && D != 36 && D != 49 && D != 64 && D != 81 && D != 100 && D != 121 && D != 144 && D != 169 && D != 196 && D != 225 && D != 256 && D != 289 && D != 324 && D != 361 && D != 400 && D != 441 && D != 484 && D != 529 && D != 576 && D != 625 && D != 676 && D != 729 && D != 784 && D != 841 && D != 900 && D != 961) /* un cuadrado */){  //Se descartan de la búsqueda los cuadrados, ya que no tienen solución
        //Cómo se puede comprobar si un número es cuadrado? ???  (sqrt(D) * sqrt(D)) ???
            N = 1; //N denota el upper límit de ambos valores. Se buscarán todas las iteraciones poco a poco
            while (((i*i) - (D*(j*j))) != 1){ //Se ejecutan los bucles hasta que se cumpla la ecuación

                j = N;
                for(i=1 ; i<=N && (i*i) < (D*(j*j)) && ((i*i) - (D*(j*j)) != 1); ){ //Se buscan los valores de x
                // ((i*i) < (D*(j*j))   || ((D*(j*j))) != 1
                    if (((i*i) - (D*(j*j))) != 1) i++;
                    if ((i*i) - (D*(j*j)) == 1){
                        if (i > max){
                            max = i;
                            respuesta = D;
                        }
                    }
                }
                if ((i*i) - (D*(j*j)) != 1){ //En caso de que no se consigan soluciones, se siguen buscando
                    i = N;
                    for(j=1 ; ((j<=N) && ((i*i) >= (D*(j*j))) && (i*i) - (D*(j*j)) != 1); ){ //Se buscan los valores de y
                    // ((i*i) < (D*(j*j))    || ((D*(j*j))) != 1
                        if (((i*i) - (D*(j*j))) != 1) j++;
                        if ((i*i) - (D*(j*j)) == 1){
                            if (i > max){
                                max = i;
                                respuesta = D;
                            }
                        }
                    }
                }
                N++; //De no encontrar, se aumenta el upper limit
            }
            printf("D:%d, x:%d, Respuesta:%d (Max:%d)\n", D, i, respuesta, max);
            i = 1; //Reinicio variable i
            j = 1; //Reinicio variable j
            N = 1; //Reinicio variable límite
            //aux = 0; ////Reinicio variable auxiliar
        }
    }
    printf("La respuesta es:%d\n", respuesta);
    printf("\nFin del programa\n");

    return 0;
}

int Euclides (int n, int m){ //Regresa MCD de a y b, donde 0 < b <= a
    int a = n, b = m; //De manera predeterminada se asume que n es mayor que m
    if (a == b) return a; //Si a = b, son iguales al MCD
    if ((a%2 == 0) && (b%2 ==0)) return 2; //Ad hoc: Ambos números pares, es reducible
    //if (a < 0) a *= (-1); //Si a es negativo, se convierte en positivo
    //if (b < 0) a *= (-1); //Si b es negativo, se convierte en positivo
    else if (n < m){ //Si n es menor que m,
        a = m;
        b = n;
    }
    while ((a != 0) && (b != 0) && (a != 1) && (b != 1) && (a % b != 0)){ //Los restos se van turnando, de mayor a menor; // && (b % a != 0 &&
        if ((b != 0) && (a != 1) && (b != 1)) a = (a % b);
        if ((a != 0) && (a != 1) && (b != 1)) b = (b % a);
    }
    if (b == 0) return a; //En el caso de los pares, devolver el resto diferente de 0
    else if (a == 0) return b; //En el caso de los pares, devolver el resto diferente de 0
    else if (a < b) return a;
    else if (b < a) return b;
    return 1;
}

/*while ((((i*i) - (D*(j*j))) != 1) && (aux == 0)){ //Siempre que la ecuación no se cumpla                for (j=1; j<= ;j++){
//Solución por fuerza bruta, buscando todas las soluciones mínimas
    while ((i*i) <= (D*(j*j))){ //for (i=1; i<= ;i++){
        i++;
        if ((((i*i) - (D*(j*j))) == 1) && (i > aux)) aux = i; //printf("Potencia:%d - %d ", (i*i), (D*(j*j)));
    }
    limite = i;
    i = 1; //Reinicio variable i
    while ((j < limite) && (((i*i) - (D*(j*j))) != 1)){ //for (i=1; i<= ;i++){
        if ((i*i) <= (D*(j*j))) i++;
        if ((((i*i) - (D*(j*j))) == 1) && (i > respuesta)){
            respuesta = i; //printf("Potencia:%d - %d ", (i*i), (D*(j*j)));
            if (i > aux) respuesta = i; //Si x es una solución mínima, asignar
        }
        j++;
    }
    if (aux > respuesta) respuesta = aux; //Asignar valor de la primera búsqueda
    //if ((((i*i) - (D*(j*j))) != 1) && (i > respuesta)) respuesta = aux;
    //j = 1;
    //if ((i*i) - (D*(j*j)) != 1) j++;
    //while ((Euclides (j, i) != 1) || ((i^2) > (D*(j^2)))) j++;
}*/
