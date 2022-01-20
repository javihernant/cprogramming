#include<stdio.h>

#define MAXLINES 100
#define LINE_SIZE 1000
#define BUF_SIZE 20000

int ggetline(char *str, int n);
void my_strcpy(char *s, char *t);
int rreadlines(char **lineptr, int maxlines, char *lines, int buffer_size);
void writelines(char **lineptr, int nlines);

int main()
{
    int nlines;
    char *lineptr[MAXLINES];
    char lines[BUF_SIZE];
    if((nlines = rreadlines(lineptr, MAXLINES, lines, BUF_SIZE))>=0){
        writelines(lineptr, nlines);
    }else{
        printf("Error, can't read so many lines");
    }
    return 0;
}

int rreadlines(char **lineptr, int maxlines, char *lines, int buffer_size)
{
    char line[LINE_SIZE];
    int nlines = 0;
    int len;

    while((len = ggetline(line, LINE_SIZE)) > 0){
        if (len-1 > buffer_size){
            return -1;
        }else{
            line[len-1] = '\0';
            my_strcpy(lines, line);
            lineptr[nlines] = lines; 
            lines += len;
            buffer_size -= len;
            nlines++;
        }
    }
    
    return nlines;
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

void my_strcpy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0');
}

void writelines(char **lineptr, int nlines)
{
    for(int i=0; i<nlines; i++){
        printf("%s\n", lineptr[i]);
    }
}
