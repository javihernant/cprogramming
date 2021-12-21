#include <stdio.h>

#define OUT 0
#define IN 1

void charout(int c){
    if(c == '\t'){
        putchar('\\');
        putchar('t');
    }else if(c == ' '){
        printf("SPACE");

    }else if(c == '\n'){
        putchar('\\');
        putchar('n');
    }else{
        putchar(c);
    }
}

int main()
{
    int state = OUT;
    char c;
    int count;
    int chars[128];

    for(int i=0; i<128; i++){
        chars[i] = 0;
    }

    while((c=getchar()) != EOF){
        if(c>=0 && c<128){
            chars[c]++;
        }
    }

    for(int i=0; i<128; i++){
        count = chars[i];
        if(count > 0){
            charout(i);
            putchar('\t');
            for(int j=0; j<count; j++){
                putchar('=');
            }
            putchar('\n');
        }
    }
    return 0;
}
