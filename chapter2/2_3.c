#include <stdio.h>

char char_htoi(char c){
    int val;
    if(c >= '0' && c<= '9'){
        val = c - '0';
    }else{
        if(c >= 'A' && c<='F'){
            val = c - 'A'; 
        }else{
            val = c - 'a';
        }
        val += 10;
    }
    return val;
}

int main(){
    int is_hex = 0;
    char prev = '\0';
    char c;
    for(int i=0; (c=getchar()) != '\n' &&  c!=EOF; i=(i+1)%2){
        if(prev != '\0'){
            if(prev == '0' && (c == 'x' || c == 'X')){
                is_hex = 1;
                break;
            }
        }
        prev = c;
    }

    if(!is_hex | c == '\n'){
        printf("No hex found in this line :(\n");
    }else{
        int n=0;
        while((c = getchar()) != '\n' && c != EOF && (c>='0' && c<='9') || (c>='A' && c<='F') || (c>='a' && c<='f')){
            n = n*16 + char_htoi(c);
        }
        printf("Decimal value: %d\n",n);
        
    }

    return 0;
}
