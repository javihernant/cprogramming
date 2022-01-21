/* For debugging purposes: '.' represents a space and '-' a tab
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

int main(int argc, char *argv[]){
    int n;
    int blanks; /* number of white spaces (' ') counted so far */
    int col; /* column of the current char; goes from 0 to (n-1), resets to 0 when new tab stop is encountered */ 
    char c;
    char num[LEN];
    int nstops;
    int stop;
    int stops[LEN];
    blanks = 0;
    col = 0; 
    
    if(argc - 1 > LEN){
        argc = LEN + 1;
    }

    if(argc<2){
        stops[0] = 5;
        nstops = 1;
    }else{
        for (nstops=0; nstops+1<argc; nstops++){
            stops[nstops] = atoi(argv[nstops+1]);
        }
    }

    n = stops[0];

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
            if(stop + 1 < nstops){
                stop++;
                n = stops[stop];
            }

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

