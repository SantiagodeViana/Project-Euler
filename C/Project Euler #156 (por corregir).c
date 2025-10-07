#include <stdio.h>
#include <stdlib.h>

 /* Solución para el problema #156 de Project Euler
  * "Sea s(d) la suma de todas las soluciones para las cuales f(n, d) = n. Encuentra Σ s(d) para 1 ≤ d ≤ 9."
  * https://projecteuler.net/problem=156            */

int digCount(long long int n, int d);

int main()
{
    //FILE *save;
    //save = fopen ("C:\\Users\\Desktop\\Desktopsave.txt", "a");
    long long int f = 0; //f(n, d)
    long long int respuesta = 0;
    for (int d = 1; d <= 9; d++){ //Bucle de d
        for (long long int n = 0; n <= 99999999999; n++){ //Bucle de n
            f += digCount(n, d);
            if (f == n){
                respuesta += n;
                printf("d:%d %lld) Respuesta %lld\n", d, n, respuesta);
                //fprintf("d:%d %d) Respuesta %lld\n", d, n, respuesta);
            }
        }
        f = 0; //Reiniciando f(n, d)
    }
    printf("\nLa respuesta es %lld\n", respuesta);
    return 0;
}

int digCount(long long int n, int d){ //Devuelve las veces en las que d aparece en n
    int digs = 0;
    while (n > 0){
        if (n % 10 == d) digs++;
        n /= 10;
    }
    return digs;
}
