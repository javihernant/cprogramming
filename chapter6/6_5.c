#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define HASHSIZE 101

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

int main()
{
    struct nlist *np;
    install("hashsize", "101");
    np = lookup("hashsize");
    printf("%s\n",np->defn);
    undef("hashsize");
    np = lookup("hashsize");
    if(np == NULL){
        printf("No entry found by that name\n");
    }

    return 0;
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
