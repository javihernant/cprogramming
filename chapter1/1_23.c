#include <stdio.h>

int main(){
    char c;
    char prev = '\0'; 
    /*once a comment type is selected, it cannot be changed until that comment ends */
    int in_comment; // 0 not in comment; 1 comment of type /* */ ; 2 comment of type 
    int in_string; //0 not in string, 1 in string
    int pending_in_string;
    in_comment = 0;
    in_string = 0;
    pending_in_string = 0;

    while((c=getchar()) != EOF){
        
        if(pending_in_string){
            if(c == '\''){
                in_string = !in_string;
            }
            pending_in_string = 0;
        }

        /* if a comment appears inside a string, let it print (because it's not a comment.
         * Check that the " quotation mark is the beginning of a string and not something else.
         * in_string mode is not activated whenever a quote (") is encountered as a escaping char (\") or a
         * char ('"') */
         
        if(in_comment == 0 && c == '"' && prev != '\\'){
            if (prev == '\''){
                pending_in_string = 1;
            }else{
                in_string = !in_string;
            }
        }

        
        /* check if entered a comment */
        if(in_comment == 0){
            if (!in_string){
                if(c == '*' && prev == '/'){
                    in_comment = 1;
                }else if(c == '/' && prev == '/'){
                    in_comment = 2;
                }
            }
        }
       
       /* only print when out of a comment */
        if(in_comment == 0){
            if(c != '/'){
                if(prev == '/'){
                    putchar(prev);
                }
                putchar(c);
            }

           
        }

        /* check if exited a comment */
        if(in_comment != 0){
            if(in_comment == 1){
               if(c == '/' && prev == '*'){
                   in_comment = 0;
                   c = '\0';
               }
            }else{
               if(c == '\n'){
                   putchar(c);
                   in_comment = 0;
                   c = '\0';
               }
            }

        }

        prev = c;
    }
    return 0;
}
