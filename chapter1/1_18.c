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
        printf("%s",line); 
    }

    return 0;
}

int ggetline(char line[], int len)
{
    int i;
    char c;
    int last_blank; /*points at last blank space encountered. If a non-blank char is encountered, it gets -1 */

    for(i=0; i<len-1 && ((c=getchar())!=EOF) && c!='\n'; ++i){
        if(c == ' ' || c == '\t'){
            if(last_blank == -1) {
                last_blank = i;
            }
        }else{
            last_blank = -1;
        }

        line[i] = c;
    }

    if(last_blank != -1){
        i = last_blank;
    }

    if(c=='\n'){
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

