#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN 1000
#define MAXLINES 5000
char *lineptr[MAXLINES];
int readlines(char *lines[], int max);
int numcmp(char *s1, char *s2);
void my_qsort(void *v[], int left, int right, int numeric, int reverse);
void writelines(char *lineptr[], int nlines);

int main(int argc, char *argv[])
{
    int nlines;
    char *arg;
    char opt;
    int numeric = 0;
    int reverse = 0;

    for(int i=1; i<argc; i++){
        arg = argv[i];
        if(*arg == '-'){
            while(opt = *++arg){
                switch(opt){
                    case 'n':
                        numeric = 1;
                        break;
                    case 'r':
                        reverse = 1;
                        break;
                }
            }
        }
    }

    printf("reverse:%d, numeric:%d\n", reverse, numeric);
    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        my_qsort((void **) lineptr, 0, nlines -1, numeric, reverse);
        printf("Printing elements in order...\n");
        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("input too big to sort\n");
        return 1;
    }
}

int compare_data(char * a, char *b, int numeric, int reverse)
{

    if (numeric){
        if(reverse){
            return -numcmp(a, b); 
        }else{
            return numcmp(a, b); 
        }
    }else{
        if(reverse){
            return -strcmp(a,b);
        }else{
            return strcmp(a,b);
        }
    }
}

void swap(void *v[], int i, int j);
void my_qsort(void *v[], int left, int right, int numeric, int reverse)
{
    int i, last, condition;
    if(left >= right)
        return;

    swap(v, left, (left+right)/2);
    last = left;
    for( i = left+1; i<= right; i++){
        if(compare_data(v[i], v[left], numeric, reverse) < 0){
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    my_qsort(v, left, last-1, numeric, reverse);
    my_qsort(v, last+1, right, numeric, reverse);

}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if(v1<v2){
        return -1;
    }else if (v1 > v2){
        return 1;
    }else{
        return 0;
    }
}

void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int ggetline(char line[], int len);
int readlines(char *lines[], int max)
{
    int i;
    char line[LINE_LEN];

    i=0;
    while(ggetline(line, LINE_LEN) > 0){
        lines[i] = strdup(line);
        i++;
    }

    return i;
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

void writelines(char *lineptr[], int nlines)
{
    for(int i=0; i<nlines; i++){
        printf("%s",lineptr[i]);
    }
}
