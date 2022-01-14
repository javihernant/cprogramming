#include <stdio.h>
#define LEN 100

void getinput(char s[], int n){
    char c;
    int i=0;
    while(i<n-1 && (c=getchar()) != EOF){
        s[i] = c; 
        i++;
    }
    s[i] = '\0';
}

void unescape(char s[], char t[], int t_size){
    int i, j;
    char c;
    i = j = 0;
    while((c=t[j]) != '\0'){
        if(c=='\\'){
            switch(c=t[++j]){
                case 'n':
                    s[i] = '\n';
                    break;
                case 't':
                    s[i] = '\t';
                    break;
                default:
                    s[i] = c;
                    break;
            }
        }else{
            s[i] = c;
        }
        j++;
        i++;
    }
    s[i] = '\0';
}

void escape(char s[], int s_len, char t[]){
    char c;
    int i=0;
    int j=0;
    for(; i<s_len-1 && (c = t[j])!='\0'; j++){
        switch(c){
            case '\n':
                if(i < s_len-2){
                    s[i] = '\\';
                    s[i+1] = 'n';
                    i+=2;
                }else{
                    s[i] = '\0';
                    i++;
                }
                break;
            case '\t':
                if(i < s_len-2){
                    s[i] = '\\';
                    s[i+1] = 't';
                    i+=2;
                }else{
                    s[i] = '\0';
                    i+=1;
                }
                break;
            default:
                s[i] = c;
                i++;
                break;
        }
    }
    if(i<s_len)
        s[i] = '\0';
}

int main(){
    char s[LEN];
    char t[LEN];
    getinput(t, LEN); 
    escape(s, LEN, t);
    printf("%s\n", s);
    printf("=====================\n");
    unescape(t, s, LEN);
    printf("%s\n", t);
    
    return 0;
}
