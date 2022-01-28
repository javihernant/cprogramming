#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define HASHSIZE 101
#define WORDSIZE 100 
#define BUFSIZE 50

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

struct nlist *hashtab[HASHSIZE];

unsigned int hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);
int getstr(char *word, int lim);

int main()
{
    char c;
    char word[WORDSIZE];
    char word2[WORDSIZE];
    struct nlist *np; 

    /*
    while((c = getstr(word, WORDSIZE)) != EOF){
        printf("%s\n", word);
    }
    */
    
    while((c = getstr(word, WORDSIZE)) != EOF){
        if (c == '#'){
            if(strcmp(word, "#define") == 0){
                printf("%s", word);
                getstr(word, WORDSIZE);
                printf("%s", word);
                getstr(word2, WORDSIZE);
                printf("%s", word2);
                install(word, word2);

            }else{
                printf("%s", word);
            }

        }else{
            if(((np = lookup(word)) != NULL)){
                printf("%s", np->defn);
            }else{
                printf("%s", word);
            }
        }
    }
    return 0;
}

int getch(void);
void ungetch(int);

int getstr(char *word, int lim)
{
    char c, prev;
    char *w = word;
    int token;

    while((isspace(*w = getch()) || (!isalnum(*w) && *w != '#')) && *w != EOF){
        putchar(*w);
    }

    if(*w == EOF){
        return *w;
    }else{
        w++;
        for( ; --lim>0; w++){
            if(!isalnum(*w = getch()) || *w == EOF) {
                ungetch(*w);
                break;
            }
        }
        *w = '\0';
    }
    return word[0];
}

unsigned int hash(char *s)
{
    unsigned int hashval;
    for(hashval = 0; *s != '\0'; s++){
        hashval = hashval * 31 + *s;
    }
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for(np = hashtab[hash(s)]; np != NULL; np = np->next){
        if(strcmp(s, np->name) == 0){
            return np;
        }
    }
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL) {
        np = malloc(sizeof(*np));
        if (np == NULL) {
            return NULL;
        }
        np->name = strdup(name);
        if(np->name == NULL){
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }else{
        free(np->defn);
    }
    if((np->defn = strdup(defn)) == NULL){
        return NULL;
    }
    return np;
}

void undef(char *name)
{
    struct nlist *np;
    struct nlist *tmp;
    int hashval;
    if((np = lookup(name)) != NULL) {
        free(np->defn);
        free(np->name);
        hashval = hash(name);
        tmp = hashtab[hashval];
        hashtab[hashval] = tmp->next;
        free(tmp);
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
        printf("ungetch: too many characters\n");
    }else{
        buf[bufp++] = c;
    }
}
