#include<stdio.h>

char *my_strncpy(char *s, char *t, size_t n);
char *my_strncat(char *s, char *t, size_t n);
int my_strncmp(char *s, char *t, size_t n);

int main(){
    //char s[100] = "this string is going to be overwritten";
    char *s = "this is a new string";
    char *t = "this is b new string";
    char *rs;
    int rc;
    //rs = my_strncpy(s, t, 100);
    //rs = my_strncat(s, t, 9);
    //printf("%s\n",rs);

    rc = my_strncmp(s, t, 100);
    if (rc == 0){
        printf("Equals!\n");
    }else if (rc > 0){
        printf("A is greater than B!\n");
    }else{
        printf("A is less than B!\n");
    }

    return 0;
}

char *my_strncpy(char *s, char *t, size_t n)
{
    char *sp = s;

    for (; n>0 && *t != '\0'; n--, s++, t++){
        *s = *t;
    }

    while(n > 0){
        *s = '\0';
        s++;
        n--;
    }

    return sp;
}

char *my_strncat(char *s, char *t, size_t n)
{
    char *sp = s;
    while(*s != '\0'){
        s++;
    }
   
    while(n > 0 && *t != '\0'){
        *s = *t;
        s++;
        t++;
        n--;
    }
    *s = '\0';
    return sp;
}

int my_strncmp(char *s, char *t, size_t n)
{
    int i;
    for (i=0; i<n-1 && s[i] != '\0' && t[i] != '\0' && s[i] == t[i]; i++);     
    
    return s[i] - t[i];
}
