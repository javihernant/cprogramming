#include <stdio.h>
#include <string.h>
#define LEN 100

void r_reverse(char str[], int i, int j);
void reverse(char str[]);

int main()
{
    char s[LEN] = "Al reves";
    reverse(s);
    printf("%s\n",s);
    return 0;
}

void reverse(char s[]){
    r_reverse(s, 0, strlen(s)-1);
}

void r_reverse(char s[], int i, int j){
    int temp;
    if (i >= j){
        return;
    }

    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    r_reverse(s, i+1, j-1);
}
