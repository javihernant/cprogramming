#include <stdio.h>
int main(){
    char c;
    char s[5];
    int lim = 5;
    int i=0;
    while(i<lim-1){
        if((c=getchar()) != '\n'){
            if(c != EOF){
                s[i] = c;
                i++;
            }else{
                break;
            }
        }else{
            break;
        }
    }
    s[i] = '\0';
    printf("%s\n",s);
}
