/* example. n=5
*  ^oooo^oooo^oooo^
*  where ^ represents the tab stop
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 3 /*n limited to only 2 digits (plus '0')*/

int ggetline(char line[], int len);

int main(){
    int n;
    int n_cpy;
    char c;
    char num[LEN];
    int digits;
    printf("Input number of columns until tab stop. If number inputted longer than 2 digits, only the first 2 will be taken\n");
    ggetline(num, LEN);
    n = atoi(num);
    n_cpy = n; /* number of chars to print before tab stop.*/
    printf("Number of columns: %d\n",n);

    while((c=getchar()) != EOF){

        if(c == '\t'){ 
            for(;n_cpy>0; n_cpy--){
                putchar(' ');
            }
        }else{
            putchar(c);
            n_cpy--;
        }

        if(c == '\n' || n_cpy <= 0){
            n_cpy=n;
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

    line[i] = '\0';

    return i;
}

