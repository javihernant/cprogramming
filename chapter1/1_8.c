#include<stdio.h>

int main()
{
    int bc, nlc, tc;
    bc = nlc = tc = 0;
    char c;
    while((c = getchar()) != EOF) {
        if(c==' '){
            bc++;
        }else if(c == '\n') {
            nlc++;
        }else if(c == '\t') {
            tc++;
        }
    }

    printf("Blank count:%d\nNew lines:%d\nTabs:%d\n",bc, nlc, tc);
         
    return 0;
}
