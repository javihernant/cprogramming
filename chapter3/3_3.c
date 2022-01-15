#include <stdio.h>
#define LEN 100

void gline(char s[], int n){
    char c;
    int i=0;
    while(i<n-1 && (c=getchar()) != '\n' && c != EOF){
        s[i] = c; 
        i++;
    }
    s[i] = '\0';
}

void expand(char s1[], char s2[]){
    char a, b;
    int i, j, k;
    int dif;
    for(i = 0, j=0; s2[i] != '\0'; i++){
        if(s2[i] == '-' && i>0 && s2[i+1] != '\0'){
            a=s2[i-1];
            b=s2[i+1];
            if((((a >= 'A' && a <= 'Z') && (b >= 'A' && b <= 'Z')) || ((a >= 'a' && a <= 'z') && (b >= 'a' && b <= 'z'))
                || ((a >= '0' && a <= '9') && (b >= '0' && b <= '9'))) && a<b){

                dif = b-a;
                for(k=1; k<dif; k++){
                    s1[j++] = a + k;
                }
            }else{
                s1[j++] = s2[i];
            }
            
        }else{
            s1[j++] = s2[i];
        }
        
    }
    s1[j] = '\0';
}

int main(){
    char s1[LEN];
    char s2[LEN]; 
    for(;;){
        gline(s2, LEN); 
        expand(s1, s2);
        printf("%s\n", s1);
    }
    return 0;
}
