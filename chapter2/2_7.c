#include <stdio.h>

int invert(int x, int p, int n){
    return (x & (~0 << (p+1) | ~(~0 << (p+1-n)))) | (~x & ~(~0 << (p+1) | ~(~0 << (p+1-n))));
}

int main(){
    int x = 0b10110;
    int n = 3;
    int p = 3;

    printf("%d\n", invert(x, p, n));

    return 0;
}
    
