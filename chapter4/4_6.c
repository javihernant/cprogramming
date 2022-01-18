#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100 /*max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define VAR '_'
#define SIN 's'
#define EXP 'e'
#define POW 'p'
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
    double var = 0;

    while ((type = getop(s)) != EOF) {
        switch (type){
            case NUMBER:
                push(atof(s));
                break;
            case VAR:
                push(var);
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
            case SIN:
                push(sin(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(powf(pop(), op2));
                break;
            case '\n':
                var = pop();
                printf("\t%.8g\n", var);
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
char id_op(char s[], int len);

char id_op(char s[], int len)
{
    if (len==3){

        if(s[0] == 's' && s[1] == 'i' && s[2] == 'n'){
            return SIN;
        }else if(s[0] == 'p' && s[1] == 'o' && s[2] == 'w'){
            return POW;
        }else if(s[0] == 'e' && s[1] == 'x' && s[2] == 'p'){
            return EXP;
        }
    }else if (len <= 1){
        if(len == 1 && s[0] == '_'){
            return VAR;
        }
        return s[0];
    }else{
        return '\0';
    }

}
    


int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    i = 0;
    if(!isdigit(c) && c != '.' && c!='\n'){
        while(!isdigit(s[++i] = c = getch()) && c != '.' && !isblank(c) && c!='\n' && c!=EOF);
        ungetch(c);
        s[i] = '\0';
    }


    if(i>0 | c=='\n'){
        return id_op(s, i);
    }

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

