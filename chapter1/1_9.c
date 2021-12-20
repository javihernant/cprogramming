#include<stdio.h>

int main()
{
    int bc, nlc, tc;
    bc = nlc = tc = 0;
    char c;
    int in_blank = 0;
    while((c = getchar()) != EOF) {
        if(in_blank && c == ' '){
            continue;
        }else if(in_blank && c != ' '){
            in_blank = 0;
        }
        
        if(c == ' ') {
            in_blank = 1;
        }

        putchar(c);
    
    }

    return 0;
}
