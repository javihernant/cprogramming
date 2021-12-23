#include<stdio.h>
#define MAXLINE 1000 

int ggetline(char line[], int len);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = ggetline(line,MAXLINE)) > 0){
        for(int i=len-1; i>=0; i--){
            putchar(line[i]);
        }
    }

    return 0;
}

int ggetline(char line[], int len)
{
    int i;
    char c;

    for(i=0; i<len-1 && ((c=getchar())!=EOF) && c!='\n'; ++i){
        line[i] = c;
    }

    if(c=='\n'){
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

