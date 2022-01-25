#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 20 

#define TK_WRD 0
#define TK_CHR 1
#define TK_STR 2 
#define TK_CM1 3 
#define TK_CM2 4 


int getword(char *w, int maxword);


int main(){
    char word[MAXWORD];
    while(getword(word, MAXWORD) != EOF){
        printf("%s\n", word);
    }
    return 0;
}

int getch(void);
void ungetch(int);

void gettoken(char c, int *tk)
{
    switch(c){
        case '\'':
            *tk = TK_CHR;
            break;
        case '"':
            *tk = TK_STR;
            break;
        case '/':
            if ((c=getch()) == '/'){
                *tk = TK_CM1;
            }else if (c == '*'){
                *tk = TK_CM2;
            }else{
                *tk = TK_WRD;
                ungetch(c);
            }
            break;            
        default:
            *tk = TK_WRD;
            break;
    }
}

int getword(char *word, int lim)
{
    char c, prev;
    char *w = word;
    int token;

    while(isspace(c = getch()));

    gettoken(c, &token);
    switch(token){
        case TK_WRD:
            if(c != EOF){
                *w++ = c;
            }

            if(!isalpha(c) && c!='#' && c!='_'){
                *w = '\0';
                return c;
            }

            for( ; --lim>0; w++){
                if(!isalnum(*w = getch()) && *w!='_') {
                    ungetch(*w);
                    break;
                }
            }
            *w = '\0';
            break;
        case TK_CHR:
            prev = '\0';
            while((c=getch()) != '\'' || (prev=='\\' && c=='\'')){
                if(c == '\\' && prev == '\\'){
                    prev = '\0';
                }else{
                    prev = c;
                }
            }
            strcpy(w,"char");
            break;
        case TK_STR:
            prev = '\0';
            while((c=getch()) != '"' || (prev=='\\' && c=='"')){
                if(c == '\\' && prev == '\\'){
                    prev = '\0';
                }else{
                    prev = c;
                }
            }
            strcpy(w,"string");
            break;
        case TK_CM1:
            while((c=getch()) != '\n');
            strcpy(w,"comment");
            break;
        case TK_CM2:
            prev = '\0';
            while((c=getch()) != '/' && prev != '*'){
                prev = c;
            }
            strcpy(w,"comment");
            break;
        return word[0];
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
