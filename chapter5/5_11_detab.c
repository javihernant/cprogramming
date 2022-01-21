/* example. n=5
*  ^oooo^oooo^oooo^
*  where ^ represents the tab stop
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 100 /* maximum number of arguments */

int main(int argc, char *argv[]){
    int n;
    int n_cpy;
    int nstops;
    int stop;
    char c;
    int stops[LEN];
    
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
   
    stop = 0;
    n_cpy = stops[stop];
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
            /* load next tab setting; if already at last one, keep it until end of execution */
            if(stop+1 < nstops){
                stop++;
            }
            n_cpy = stops[stop];
        }
    }
	return 0;
}
