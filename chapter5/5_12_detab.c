/* example. n=5
*  ^oooo^oooo^oooo^
*  where ^ represents the tab stop
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 100 /* maximum number of arguments */

int main(int argc, char *argv[]){
    int n, nn, m;
    int n_cpy;
    int nstops;
    int stop;
    char c;
    int stops[LEN];
    int gc;
    
    if(argc > 2){
            if(argv[1][0] == '-' && argv[2][0] == '+'){
                m = atoi(++argv[1]);
                nn = atoi(++argv[2]);
                printf("nn:%d,m:%d\n",nn, m);
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
   
    stop = 0;
    gc = 0; 
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
        gc++;

        if(c == '\n' || n_cpy <= 0){
            /* load next tab setting; if already at last one, keep it until end of execution */
            if(stop+1 < nstops){
                stop++;
            }

            if(gc>=m){
                n_cpy = nn;
            }else{
                n_cpy = stops[stop];
            }

        }
    }
	return 0;
}
