#include <stdio.h>
#include <string.h>

#define MAXVAL 100 /* max size of the stack */
#define BUFSIZE 100 /* max size for the getch/ungetch buffer */

void ungets(char s[]);
int getch(void);
void ungetch(int);
char id_op(char s[], int len);

/* testing ungets */
int main()
{
    char c;
    char s[] = "This is a line\n";
    ungets(s);
    while((c = getch()) != '\n'){
        putchar(c);
    }

}


void ungets(char s[]){
    char c;
    for (int i=strlen(s)-1; i>=0; i--){
        ungetch(s[i]);
    }
}

char buf[BUFSIZE]; 
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE){
        printf("ungetch: too many characters");
    }else{
        buf[bufp++] = c;
    }
}

