#include <stdio.h>
#define swap(t,x,y) {           \
                    t temp = x; \
                    x = y;      \
                    y = temp;   \
                    }

int main(){
    int x = 4;
    int y = 1;
    swap(int, x, y);
    printf("x:%d, y:%d\n", x, y);
    return 0;
}
