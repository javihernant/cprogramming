#include<stdio.h>

void my_strcat(char *s, char *t);

int main(){
    char s[100] = "This is a";
    char *t = " split string";
    my_strcat(s,t);
    printf("%s\n",s);
    return 0;
}

void my_strcat(char *s, char *t)
{
    while(*s != '\0'){
        s++;
    }
   
    while(*t != '\0'){
        *s = *t;
        s++;
        t++;
    }
    *s = *t;
}



