#include <stdio.h>
#define LEN 100

int r_itoa(int, char [], int);
void itoa(int, char []);

int main(){
    char num[LEN];
    itoa(-184, num);
    printf("%s\n",num);
    return 0;
}

void itoa(int n, char s[]){
    int i, sign;

    if (sign = (n<0)){
        n = -n;
    }

    r_itoa(n, s, sign);
}

int r_itoa(int n, char s[], int sign){
    int i;
    if(n/10){
        i = r_itoa(n/10, s, sign) + 1;
    }else{
        i = 0;
        if (sign){
            s[i++] = '-';
        }
    }
    s[i] = n % 10 + '0';
    return i;
}
