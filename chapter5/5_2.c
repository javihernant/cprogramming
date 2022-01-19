#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100 /* max size for the getch/ungetch buffer */

int getfloat(double *np);

int main(){
    double a = -1.0;
    getfloat(&a);
    printf("%f\n",a);
    return 0;
}

int getch(void);
void ungetch(int);

char buf[BUFSIZE]; 
int bufp = 0;

int getfloat(double *pn)
{
    int c, sign;
    double dec;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c !='.' && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c== '-' || c == '+'){
        c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
    }

    if (c == '.'){
        c = getch();
    }

    dec = 1;
    for (; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
        dec /= 10;
    }

    *pn *= dec;
    *pn *= sign;

    if(c != EOF){
        ungetch(c);
    }

    return c;
}

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

