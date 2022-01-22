#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINES 100 /* maximum number of lines the program can return */
#define LINE_LEN 1000 /* line can contain maximum LINE_LEN chars */

int readlines(char *lines[], int max);
int ggetline(char line[], int len);

int main(int argc, char *argv[]){
    int n = 10;
    int i;
    int max;
    int lines;
    static char *buffer[MAX_LINES];
    if (argc > 1 && *argv[1] == '-'){
        n = atoi(++argv[1]);
        printf("new value for n: %d\n", n);
    }

    if(n>MAX_LINES){
        n = MAX_LINES;
    }

    lines = readlines(buffer, MAX_LINES);
    printf("%d lines were read\n",lines);


    if(lines < 1){
        return 1;
    }else{
        i = (lines-1) % MAX_LINES;
    }

    i = i-(n-1);
    if(i<0){
        i = MAX_LINES - i; 
    }

    for (; lines-- > 0 && n-- > 0; i = (i+1) % MAX_LINES){
        printf("%s", buffer[i]);
    }

    return 0;
}

int readlines(char *lines[], int max)
{
    int i, count;
    char line[LINE_LEN];

    count = 0;
    i=0;
    while(ggetline(line, LINE_LEN) > 0){
        free(lines[i]);
        lines[i] = strdup(line);
        i = (i+1) % max;
        count++;
    }

    return count;
}

int ggetline(char line[], int len)
{
    int i;
    char c;

    for(i=0; i<len-1 && ((c=getchar())!=EOF) && c!='\n'; ++i){
        line[i] = c;
    }

    if(c=='\n'){
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}
