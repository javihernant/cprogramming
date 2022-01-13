#define SIZE 100 /*Max size lines read will admit */
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

int any(char s1[], char s2[]){
    for(int i=0; s1[i] != '\0'; i++){
        for(int j=0; s2[j] != '\0'; j++){
            if(s2[j] == s1[i]){
                return i;
            }
        }
    }

    return -1;
}


int main(){
    char s1[SIZE];
    char s2[SIZE];
    int rc;
    while(1){
        printf("Enter first string\n");
        ggetline(s1, SIZE);
        printf("Enter second string\n");
        ggetline(s2, SIZE);
        if((rc = any(s1,s2)) != -1){
            printf("S1 at index %d is the first char contained in S2\n", rc);
        }else{
            printf("S1 does not contain any char from s2");
        }

    }

    return 0;
}
    
