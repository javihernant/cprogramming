#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100 /*max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* max size of the stack */
#define BUFSIZE 100 /* max size for the getch/ungetch buffer */

int getop(char []);
void push(double);
double pop(void);
double top(void);
void clear(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0){
                    push(pop() / op2);
                }else{
                    printf("Error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                push(fmod(pop(), op2));
                break;
                
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: Unknown command %s\n", s);
                break;
        }

    }
    return 0;
}

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL){
        val[sp++] = f;
    }else{
        printf("error: stack full, can't push %g\n",f);
    }
}

double pop(void)
{
    if (sp > 0){
        return val[--sp];
    }else{
        printf("error: stack is empty\n");
        return 0.0;
    }
}

double top(void)
{
    if (sp > 0){
        return val[sp-1];
    }else{
        printf("error: stack is empty\n");
        return 0.0;
    }
}

void dup_top(void){
    push(top());
}

void swap_top(void){
    double temp1, temp2;
    if(sp > 1){
        temp1 = pop();
        temp2 = pop();
        push(temp1);
        push(temp2);
    }else{
        printf("error: stack contains <2 elements, can't swap\n");
    }
}

void clear(void)
{
    sp = 0;
}

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.'){
        return c;
    }
    i = 0;
    if(isdigit(c)){
        while(isdigit(s[++i] = c = getch()));
    }
    
    if(c == '.'){
        while(isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if(c != EOF){
        ungetch(c);
    }
    return NUMBER;
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

