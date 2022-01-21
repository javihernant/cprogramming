#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100 /*max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* max size of the stack */

int getop(char []);
void push(double);
double pop(void);
double top(void);
void clear(void);

int main(int argc, char *argv[])
{
    double op2;
    double var = 0;

    for (int i=1; i<argc; i++) {
        switch (getop(argv[i])){
            case NUMBER:
                push(atof(argv[i]));
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
            default:
                printf("Error: Unknown command %s\n", argv[i]);
                break;
        }
    }

    var = pop();
    printf("\t%.8g\n", var);

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


int getop(char *s)
{
    char *s_cpy = s;
    if(isdigit(*s)){
        return NUMBER;
    }

    return *s;
}    
