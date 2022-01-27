#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 20 

/* subtree node */
struct stnode{
    int line;
    struct stnode *left; 
    struct stnode *right;
};

struct tnode{
    char * word;
    struct stnode *subt;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *w, int *line, int maxword);
struct tnode *addtree(struct tnode *tree, char *w, int line);
struct tnode *addsubtree(struct tnode *subtree, int line);
void printt(struct tnode *t);

int main()
{
    char word[MAXWORD];
    int line;
    char c;
    struct tnode *t = NULL;
    
    while((c = getword(word, &line, MAXWORD)) != EOF){
        t = addtree(t, word, line);
        //printf("%s (line:%d)\n",word, line);
    }

    printt(t);
    return 0;
}
void printsubt(struct stnode *t)
{
    if(t != NULL){
        printsubt(t->left);
        printf("%d ",t->line);
        printsubt(t->right);
    }
}

void printt(struct tnode *t)
{
    if(t != NULL){
        printt(t->left);
        printf("WORD %s appears at lines: ",t->word);
        printsubt(t->subt);
        printf("\n");
        printt(t->right);
    }
}

int getch(void);
void ungetch(int);

int getword(char *word, int *l, int lim)
{
    static int line = 1;
    char c, prev;
    char *w = word;
    int token;

    while((isspace(*w = getch()) || (!isalpha(*w) && *w!='#' && *w!='_')) && *w != EOF){
        if(*w == '\n'){
            line++;
        }
    }

    if(*w == EOF){
        return *w;
    }else{
        w++;
        for( ; --lim>0; w++){
            if(!isalnum(*w = getch()) && *w!='_') {
                ungetch(*w);
                break;
            }
        }
        *w = '\0';
    }
    *l = line;
    return word[0];

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
        printf("ungetch: too many characters\n");
    }else{
        buf[bufp++] = c;
    }
}

struct tnode *talloc()
{
    struct tnode *t = malloc(sizeof(struct tnode));
    t->word = NULL; 
    t->subt = NULL;
    t->left = t->right = NULL;
    return t;
}
struct stnode *stalloc()
{
    struct stnode *st = malloc(sizeof(struct stnode));
    st->left = st->right = NULL;
    return st;
}

struct stnode *addsubt(struct stnode *p, int line)
{
    int cond;

    if (p == NULL){
        //printf("Word appears in a new line (%d)!\n", line);
        p = stalloc();
        p->line = line;
    }else if (line == p->line){
        //printf("Word already at line %d\n",p->line);

    }else if (line < p->line){
        p->left = addsubt(p->left, line);

    }else{
        p->right = addsubt(p->right, line);
    }
    return p;
}

struct tnode *addtree(struct tnode *p, char *w, int line)
{
    int cond;

    if (p == NULL){
        //printf("New word\n");
        p = talloc();
        p->word = strdup(w);
        p->subt = addsubt(p->subt, line);
    }else if ((cond = strcmp(w, p->word)) == 0){
        //printf("Word already stored\n");
        p->subt = addsubt(p->subt, line);
    }else if (cond < 0){
        p->left = addtree(p->left, w, line);
    }else{
        p->right = addtree(p->right, w, line);
    }
    return p;
}

