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

void squeeze(char s1[], char s2[]){
    int i, j;
    i = j = 0;
    int match;
    for(;s1[i] != '\0'; i++){
        match = 0; 
        for(int k =0; s2[k] != '\0'; k++){
            if(s2[k] == s1[i]){
                match = 1;
            }
        }
        if(!match){
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}


int main(){
    char s1[SIZE];
    char s2[SIZE];
    while(1){
        printf("Enter string to modify\n");
        ggetline(s1, SIZE);
        printf("Enter string used to modify\n");
        ggetline(s2, SIZE);
        squeeze(s1,s2);
        printf("%s\n",s1);
    }

    return 0;
}
    
