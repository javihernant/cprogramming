#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 20 

struct tnode{
    char * word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *w, int maxword);
struct tnode *addtree(struct tnode *tree, char *w);
struct tnode *addtree2(struct tnode *p, char *w, int count);
void build2tree(struct tnode **to, struct tnode *from);
void printt(struct tnode *t);

int main()
{
    char word[MAXWORD];
    char c;
    struct tnode *t = NULL;
    struct tnode *to = NULL;
    
    while((c = getword(word, MAXWORD)) != EOF){
        t = addtree(t, word);
        //printf("%s (line:%d)\n",word, line);
    }

    build2tree(&to, t);
    printt(to);
    return 0;
}

void build2tree(struct tnode **to, struct tnode *from)
{
    if(from != NULL){
        build2tree(to, from->left);
        *to = addtree2(*to, from->word, from->count);
        build2tree(to, from->right);
    }
}

void printt(struct tnode *t)
{
    if(t != NULL){
        printt(t->right);
        printf("%s (%d)\n",t->word, t->count);
        printt(t->left);
    }
}

int getch(void);
void ungetch(int);

int getword(char *word, int lim)
{
    char c, prev;
    char *w = word;

    while((isspace(*w = getch()) || (!isalpha(*w) && *w!='#' && *w!='_')) && *w != EOF);

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
    t->count = 0;
    t->left = t->right = NULL;
    return t;
}


struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL){
        //printf("New word\n");
        p = talloc();
        p->word = strdup(w);
        p->count++;
    }else if ((cond = strcmp(w, p->word)) == 0){
        //printf("Word already stored\n");
        p->count++;
    }else if (cond < 0){
        p->left = addtree(p->left, w);
    }else{
        p->right = addtree(p->right, w);
    }
    return p;
}

struct tnode *addtree2(struct tnode *p, char *w, int count)
{
    int cond;

    if (p == NULL){
        p = talloc();
        p->word = strdup(w);
        p->count = count;
    }else if (count < p->count){
        p->left = addtree2(p->left, w, count);
    }else{
        p->right = addtree2(p->right, w, count);
    }
    return p;
}
