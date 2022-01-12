#include <stdio.h>
#include <stdlib.h>

#define CODE 0
#define STRING 1
#define QUOTES 2
#define COMMENT_A 3
#define COMMENT_B 4

typedef struct pile{
    int size;
    int tail;
    char *arr;
}pile_t;

pile_t init_pile(){
    struct pile p;
    p.size = 100;
    p.tail = 0;
    p.arr = malloc(p.size);
    if (p.arr == NULL){
        fprintf(stderr, "Malloc: Error\n");
    }
    return p;
}

int get_status(int curr_st, char c, char prev){
    int status = curr_st;
    switch(curr_st){
        case CODE:
            if(c == '"'){
                status = STRING;
            }

            if(c == '\''){
                status = QUOTES;
            }

            if(prev == '/' && c == '*'){
                status = COMMENT_A;
            }

            if(prev == '/' && c == '/'){
                status = COMMENT_B;
            }
            break;
        case STRING:
            if(c == '"' && prev != '\\'){
                status = CODE;
            }
            break;
        case QUOTES:
            if(c == '\'' && prev != '\\'){
                status = CODE;
            }
            break;
        case COMMENT_A:
            if(prev == '*' && c == '/'){
                status = CODE;
            }
            break;
        case COMMENT_B:
            if(c == '\n'){
                status = CODE;
            }
            break;
    }
    return status;
}

void push(pile_t *p, char c){
    if(p->tail >= p->size){
        p->size = p->size * 2;
        p->arr = realloc(p->arr, p->size);
        if(p->arr == NULL){
            fprintf(stderr, "Error reallocation failed\n");
            exit(1);
        }
    }

    p->arr[p->tail] = c; 
    p->tail++;
}

/*c is the closing char */
int is_match(char c, char pen){
    int rc=0;
    switch(c){
        case ')':
            if(pen == '('){
                rc = 1;
            }
            break;
        case ']':
            if(pen == '['){
                rc = 1;
            }
            break;
        case '}':
            if(pen == '{'){
                rc = 1;
            }
            break;
    }

    return rc;
}

int is_closing(char c){
    return c == '}' || c == ']' || c == ')';
}

void validate(pile_t *p){
   int last_idx = p->tail - 1;
   int pen_idx = last_idx - 1;
   char c = p->arr[last_idx];
   char pen;
   if(is_closing(c)){
       if(pen_idx < 0){
           pen = '\0';
       }else{
           pen = p->arr[pen_idx];
       }

       if(is_match(c,pen)){
           p->tail -= 2;  
       }else{
           printf("char %c doesn't match with %c\n", c, pen);
           exit(0);
       }

   }
    
}

int main(){
    char c;
    char prev = '\0'; 
    pile_t pile = init_pile();
    int status = CODE;
    int new_status;
    
    while((c=getchar()) != EOF){
        new_status = get_status(status, c, prev);
        if (new_status != status){
             status = new_status;
             continue;
        }

        if(status == CODE){
            if(c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']'){
                push(&pile, c);
                validate(&pile);
            }
        }
        if(prev == '\\'){
            prev = '\0';
        }else{
            prev = c;
        }
    }
    
    if(status != CODE){
        printf("You forgot to end your comment/quote/string\n"); 
        printf("STATUS:%d",status);
    }else{
        if(pile.tail > 0){
            printf("You forgot to close %d char(s) ('(' or '[' or '{')\n", pile.tail); 
        }
    }

    return 0;
}
