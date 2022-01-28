#include <stdio.h>
#include <ctype.h>

int main(){
    char c;
    while((c=getchar()) != EOF){
        if(isgraph(c) || isspace(c)){
            putchar(c);
        }else{
            printf("%x",c);
        }
    }
    return 0;
}
