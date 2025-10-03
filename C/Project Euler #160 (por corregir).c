#include <stdio.h>
#include <stdlib.h>

int factTrail(int n); //n!

int main()
{
    printf("Hello world!\n");
    return 0;
}

int factTrail(int n){
    int zeros = 0;
    while (zeros < 5 && n > 0){ //
        if (n % 10 == 0) zeros++;
        else if (zeros < 5) zeros = 0;
        n /= 10;
    }
    if (zeros == 5) return n;
    else return -1;
}
