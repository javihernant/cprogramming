#include <stdio.h>

int countbits(int x){
    int c=0;
    for(; x>0; x=x>>1) c++;
    return c;
}

int rightrot(int x, int t, int n){
    int res = x;
    for(int i = 0; i<t; i++){
        res = res>>1 | ((res&1)<<(n-1));
    }
    return res;
}

int main(){
    int x = 0b10110;
    int y = 0;
    int n = countbits(x);
    int t = 3;

    if(n>0){
        y = rightrot(x, t, n);
    }

    printf("%d\n", y);

    return 0;
}
    
