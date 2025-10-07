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

    /* d:2 0) Respuesta 0
        d:2 28263827) Respuesta 28263827
        d:2 35000000) Respuesta 63263827
        d:2 242463827) Respuesta 305727654
        d:2 500000000) Respuesta 805727654
        d:2 528263827) Respuesta 1333991481
        d:2 535000000) Respuesta 1868991481
        d:2 10000000000) Respuesta 11868991481
        d:2 10028263827) Respuesta 21897255308
        d:2 10035000000) Respuesta 31932255308
        d:2 10242463827) Respuesta 42174719135
        d:2 10500000000) Respuesta 52674719135
        d:2 10528263827) Respuesta 63202982962
        d:2 10535000000) Respuesta 73737982962 
        d:3 371599983) Respuesta 371599983
        d:3 371599984) Respuesta 743199967
        d:3 371599985) Respuesta 1114799952
        d:3 371599986) Respuesta 1486399938
        d:3 371599987) Respuesta 1857999925
        d:3 371599988) Respuesta 2229599913
        d:3 371599989) Respuesta 2601199902
        d:3 371599990) Respuesta 2972799892
        d:3 371599991) Respuesta 3344399883
        d:3 371599992) Respuesta 3715999875
        d:3 500000000) Respuesta 4215999875
        d:3 10000000000) Respuesta 14215999875
        d:3 10371599983) Respuesta 24587599858
        d:3 10371599984) Respuesta 34959199842
        d:3 10371599985) Respuesta 45330799827
        d:3 10371599986) Respuesta 55702399813
        d:3 10371599987) Respuesta 66073999800
        d:3 10371599988) Respuesta 76445599788
        d:3 10371599989) Respuesta 86817199777
        d:3 10371599990) Respuesta 97188799767
        d:3 10371599991) Respuesta 107560399758
        d:3 10371599992) Respuesta 117931999750
        d:3 10500000000) Respuesta 128431999750
        d:3 20000000000) Respuesta 148431999750
        d:3 20371599983) Respuesta 168803599733
        d:3 20371599984) Respuesta 189175199717
        d:3 20371599985) Respuesta 209546799702
        d:3 20371599986) Respuesta 229918399688
        d:3 20371599987) Respuesta 250289999675
        d:3 20371599988) Respuesta 270661599663
        d:3 20371599989) Respuesta 291033199652
        d:3 20371599990) Respuesta 311404799642
        d:3 20371599991) Respuesta 331776399633
        d:3 20371599992) Respuesta 352147999625
        d:3 20500000000) Respuesta 372647999625 */
