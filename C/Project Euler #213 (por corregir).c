#include <stdio.h>
#include <stdlib.h>

#define N 30

int main()
{
    int circus[N-1][N-1] = {1, 1, 1, ..., 1};
    for(int i; i <= 50; i++){ //Saltos
        for(int j=0; j < N; j++){ //Pulgas
            for(int k = 0; k < N; k++){
                switch (choice){ //Pendiente de considerar pulgas en "paredes"
                    case 0:
                        i++;
                        break;
                    case 1:
                        j--;
                        break;
                    case 2:
                        k++;
                        break;
                    case 3:
                        k--;
                        break;
                }
            }
        }
    }
    printf("Hello world!\n");
    return 0;
}
