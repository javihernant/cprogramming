#include <stdio.h>
#include <string.h>
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

void itoa(char n, char s[]){
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
        s[i++] = '0' + (un % 10);
    }while((un/=10) > 0);

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
    itoa(n, str);
    printf("%s\n", str);

    return 0;
}
