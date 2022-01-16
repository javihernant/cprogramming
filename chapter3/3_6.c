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

void itoa(int n, char s[], int min){
    int i;
    int sign = 0;
    if (n < 0){
        sign = 1;
        n = -n;
    }

    i = 0; 
    do{
        s[i++] = '0' + (n%10);
    }while((n /= 10) > 0);

    for(; i<min; i++)
        s[i] = '0';

    if(sign)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

/* working with chars for being more manageable (only 8bits) */
int main(){
    char str[10];
    int n = -118;
    itoa(n, str, 6);
    printf("%s\n", str);

    return 0;
}
