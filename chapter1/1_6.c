
#include<stdio.h>


int main()
{
    /* to send eof to stdin, ctr-d*/
    while(1){
        printf("getchar() != EOF:%d\n",  getchar() != EOF);
    }
        
    return 0;
}
