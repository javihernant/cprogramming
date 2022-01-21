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

int main(int argc, char *argv[]){
    int n, nn, m;
    int blanks; /* number of white spaces (' ') counted so far */
    int col; /* column of the current char; goes from 0 to (n-1), resets to 0 when new tab stop is encountered */ 
    int gcol;
    char c;
    char num[LEN];
    int nstops;
    int stop;
    int stops[LEN];
    blanks = 0;
    col = 0; 
    gcol = 0;

    
    if(argc > 2){
        if(argv[1][0] == '-' && argv[2][0] == '+'){
            m = atoi(++argv[1]);
            nn = atoi(++argv[2]);
            printf("n:%d,m:%d\n",nn, m);
            argv += 2;
            nstops = argc -3;
        }else{
            nstops = argc - 1;
        }
    }else{
        nstops = argc - 1;
    }

    if(nstops > LEN){
        nstops = LEN;
    }

    if(nstops == 0){
        stops[0] = 5;
        nstops = 1;
    }else{
        for (int i=0; i<nstops; i++){
            stops[i] = atoi(argv[i+1]);
        }
    }
    n = stops[0];
    printf("initial n:%d\n",n);

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

        gcol++;
        col = (col + 1) % n;
        if(c=='\n' || c == '-'){
            col=0;
        }
        
        /* when tab stop is reached, if there still are blank spaces in "blanks" print a tab insted. */
        if(col == 0){
            if(gcol >= m){
                n = nn;
            }else{
                if(stop + 1 < nstops){
                    stop++;
                    n = stops[stop];
                }
            }

            if(blanks>0){
                putchar('-');
                blanks = 0;
            }
        }

    }

    return 0;
}
