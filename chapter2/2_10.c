#include <stdio.h>

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


/* -1 in a 2-complement machine is represented with all bits set to 1. x-1 is x+(-1), so right most 1-bit is turned to a
 * 0 (1+1 = 10), while 1 is carried out until overflow */
/* counts 1-bits */
int lower(char c){
    return (c >= 'A' && c<='Z') ? c + 'a' - 'A' : c;
}

int main(){
    char s[100];
    ggetline(s, 100);
    for(int i=0; s[i] != '\0'; i++){
        s[i] = lower(s[i]);
    }
    printf("%s\n", s);

    return 0;
}
    
