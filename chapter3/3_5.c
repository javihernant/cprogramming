#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#define LEN 100

void reverse(char s[]){
    int i, j;
    char temp;
    for(i=0, j=strlen(s)-1; i<j; i++, j--){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

}

char to_char(int d){
    if(d<10){
        return '0' + d;
    }else{
        return 'a' + (d%10);
    }

}

void itob(char n, char s[], int b){
    assert(b<=16);
    unsigned char un;
    int sign = 0;
    int i;
    if (n < 0){
        sign = 1;
        n += 1;
        un = -n;
        un += 1;
    }else{
        un = n;
    }

    i = 0; 
    do{
        s[i++] = to_char(un%b);
    }while((un/=b) > 0);

    if(sign)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

/* working with chars for being more manageable (only 8bits) */
int main(){
    /* Unexpected behaviour */
    printf("Positive of %d = %d\n", CHAR_MIN, (char)-CHAR_MIN);

    char str[10];
    char n = -128;
    itob(n, str, 16);
    printf("%s\n", str);

    return 0;
}
