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
    
    c = getch();
    ungetch(c);
    c = getch();
    putchar(c);

}

char buf = '\0';

int getch(void)
{
    char temp;
    if (buf != '\0') {
        temp = buf;
        buf = '\0';
        return temp;
    }else{
        return getchar();
    }
}

void ungetch(int c)
{
    if(buf != '\0'){
        printf("ungetch: cant overwrite buffer, use getch first");
    }else{
        buf = c;
    }
}

