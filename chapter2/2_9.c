#include <stdio.h>

/* -1 in a 2-complement machine is represented with all bits set to 1. x-1 is x+(-1), so right most 1-bit is turned to a
 * 0 (1+1 = 10), while 1 is carried out until overflow */
/* counts 1-bits */
int bitcount(unsigned int x){
    int c=0;
    for(; x>0; x &= x-1) c++;
    return c;
}

int main(){
    int x = 0b11010110;
    int n = bitcount(x);

    printf("1-bit count: %d\n", n);

    return 0;
}
    
