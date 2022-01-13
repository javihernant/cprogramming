#include <stdio.h>

int setbits(int x, int p, int n, int y){
    return (x & ((~0 << (p+1)) | ~(~0 << (p+1-n)))) | ((y & ~(~0 << n)) << (p+1-n));
}

int main(){
    int x = 0b10110;
    int y = 0b11101;
    int n = 3;
    int p = 3;

    printf("%d\n", setbits(x, p, n, y));

    return 0;
}
    
