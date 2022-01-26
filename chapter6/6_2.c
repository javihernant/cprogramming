#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 20 

/* subtree node */
struct stnode{
    char *word;
    struct stnode *left; 
    struct stnode *right;
};

struct tnode{
    char *gname;
    struct stnode *subt;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *w, int maxword);
struct tnode *addtree(struct tnode *tree, char *w, int gnsize);
struct tnode *addsubtree(struct tnode *subtree, char *w);
void printgroups(struct tnode *t);

int main(int argc, char *argv[]){
    char word[MAXWORD];
    int len, n;
    struct tnode *t = NULL;
    if (argc != 2){
        printf("Usage: 6_2 [number]\n");
        return 0;
    }
    
    n = atoi(argv[1]);
    if (n <= 0){
        printf("Argument has to be greater than 0\n");
        return 0;
    }

    printf("%d\n", n);
    
    while((len = getword(word, MAXWORD)) > 0){
        if (len>=n){
            t = addtree(t, word, n);
            //printf("%s\n", word);
        }
    }

    printgroups(t);
    return 0;
}
void printsubt(struct stnode *t)
{
    if(t != NULL){
        printsubt(t->left);
        printf("%s\n",t->word);
        printsubt(t->right);
    }
}

void printgroups(struct tnode *t)
{
    if(t != NULL){
        printgroups(t->left);
        printf("========GROUP: %s ==========\n",t->gname);
        printsubt(t->subt);
        printgroups(t->right);
    }
}

int getch(void);
void ungetch(int);

int getword(char *word, int lim)
{
    char c, prev;
    char *w = word;
    int token;
    int count = 0;

    while(isspace(c = getch()));

    if(c != EOF){
        *w++ = c;
        count++;
    }

    if(!isalpha(c) && c!='#' && c!='_'){
        *w = '\0';
        return count;
    }

    for( ; --lim>0; w++){
        if(!isalnum(*w = getch()) && *w!='_') {
            ungetch(*w);
            break;
        }
        count++;
    }
    *w = '\0';
    return count;
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

struct tnode *talloc(int gnsize)
{
    struct tnode *t = malloc(sizeof(struct tnode));
    t->gname = malloc(gnsize+1);
    t->subt = NULL;
    t->left = t->right = NULL;
    return t;
}
struct stnode *stalloc()
{
    struct stnode *st = malloc(sizeof(struct stnode));
    st->word = NULL;
    st->left = st->right = NULL;
    return st;
}

struct stnode *addsubt(struct stnode *p, char *w)
{
    int cond;

    if (p == NULL){
        p = stalloc();
        p->word = strdup(w);
    }else if ((cond = strcmp(w, p->word)) == 0){
        printf("word already added\n");
    }else if (cond < 0){
        p->left = addsubt(p->left, w);
    }else{
        p->right = addsubt(p->right, w);
    }
    return p;
}

struct tnode *addtree(struct tnode *p, char *w, int gnsize)
{
    int cond;

    if (p == NULL){
        printf("New group created\n");
        p = talloc(gnsize);
        strncpy(p->gname, w, gnsize);
        p->gname[gnsize] = '\0';
        p->subt = addsubt(p->subt, w);
    }else if ((cond = strncmp(w, p->gname, gnsize)) == 0){
        //printf("word in group %s\n", p->gname);
        p->subt = addsubt(p->subt, w);
    }else if (cond < 0){
        p->left = addtree(p->left, w, gnsize);
    }else{
        p->right = addtree(p->right, w, gnsize);
    }
    return p;
}

