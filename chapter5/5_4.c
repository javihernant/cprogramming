#include<stdio.h>

int my_strend(char *s, char *t);

int main(){
    char s[100] = "this string contain this string";
    char *t = "this string";
    int rc;
    rc = my_strend(s,t);
    if (rc == 0){
        printf("Not found :(\n");
    }else{
        printf("Found!\n");
    }
    return 0;
}

int my_strend(char *s, char *t)
{
    char *s_cpy;
    char *t_cpy;
    while(*s != '\0'){
        while(*s != *t){
            s++;
        }

        s_cpy = s;
        t_cpy = t;
        while(*s_cpy == *t_cpy && *s_cpy != '\0' && *t_cpy != '\0'){
            s_cpy++;
            t_cpy++;
        }

        if(*s_cpy == '\0' && *t_cpy == '\0'){
            return 1;
        }else if(*s_cpy == '\0' && *t_cpy != '\0'){
            return 0;
        }else{
            s++;
        }
    }

    return 0;
}



