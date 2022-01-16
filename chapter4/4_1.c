#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int ggetline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(){
    char line[MAXLINE];
    int i;
    int found = 0;

    while(ggetline(line, MAXLINE) > 0){
        if ((i=strrindex(line, pattern)) >= 0){
            printf("[i=%d]%s", i, line);
            found++;
        }
    }
    return found;
}

int ggetline(char s[], int lim){
    int c, i;

    i=0;
    while(lim>2 && (c = getchar()) != EOF && c != '\n'){
        s[i++] = c;
        lim--;
    }

    if(c == '\n'){
        s[i++] = c;
    }

    s[i] = '\0';
    return i;
}

int strrindex(char s[], char t[]){
    int i,j,k;
    for (i = strlen(s)-1; i>=0; i--){
        for(k= strlen(t)-1, j=i; k>=0 && j>=0 && t[k] == s[j]; k--, j--);
        if(k == -1){
            return i;
        }
    }
    return -1;
}
