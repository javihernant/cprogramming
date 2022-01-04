
/* For debugging purposes '.' represents a space and '-' a tab
input;
".foo:...bar;......#comment"
output;
".foo:-bar;-..#comment"

input;
".......-foo:.....bar;......#comment"
output;
"-foo:-.bar;-...#comment"
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 3 /*n limited to only 2 digits (plus '0')*/

int ggetline(char line[], int len);

int main(){
    int n;
    int blanks; /* number of white spaces (' ') counted so far */
    int col; /* column of the current char; goes from 0 to (n-1), resets to 0 when new tab stop is encountered */ 
    char c;
    char num[LEN];
    printf("Input number of columns until tab stop. If number inputted longer than 2 digits, only the first 2 will be taken\n");
    ggetline(num, LEN);
    n = atoi(num);
    blanks = 0;
    col = 0; 
    printf("Number of columns: %d\n",n);

    while((c=getchar()) != EOF){
        if(c == '.'){
            blanks++;
        }else if(c == '-'){
            blanks = 0;
            putchar('-');
        }else{
            for(; blanks>0; blanks--){
                putchar('.');
            }
            putchar(c);
        }

        col = (col + 1) % n;
        if(c=='\n' || c == '-'){
            col=0;
        }
        
        /* when tab stop is reached, if there still are blank spaces in "blanks" print a tab insted. */
        if(col == 0){
            if(blanks>0){
                putchar('-');
                blanks = 0;
            }
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

