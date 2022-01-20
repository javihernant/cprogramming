#include<stdio.h>

#define LEN 1000

int ggetline(char *str, int n);

int main(){
    char s[LEN];
    while(ggetline(s, LEN) > 0){
        printf("%s",s);
    }
    return 0;
}

int ggetline(char *str, int n)
{
    char c;
    int count = 0;
    while(count<(n-1) && (c=getchar()) != '\n' && c != EOF){
        *str = c;
        str++;
        count++;
    }
    
    if(c == '\n'){
        count++;
        *str = c;
        str++;
    }

    *str = '\0';
    return count;
}

