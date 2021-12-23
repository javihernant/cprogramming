#include<stdio.h>
#define MAXLINE 1000 

int ggetline(char line[], int len);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = ggetline(line,MAXLINE)) > 0){
        if(len > 80){
            printf("%s",line);
        }
    }
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

    /*if array is full but still there are chars left in the line, keep counting them (without storing them) */
    if(c!='\n' && c!=EOF){
        while((c=getchar())!=EOF && c!='\n'){
            i++;
        }

        if(c == '\n') i++;

    }

    return i;
}

