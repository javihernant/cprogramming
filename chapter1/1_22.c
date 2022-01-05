/* For debugging purposes '.' represents a space and '-' a tab
input;
".foo:...bar;......#comment"
output;
".foo:-bar;-..#comment"

input;
".......-foo:.....bar;......#comment"
output;
"-foo:-.bar;-...#comment"
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 3 /*n limited to only 2 digits (plus '0')*/
#define STR_SIZE 100

int ggetline(char line[], int len);

int is_blank(char c){
    return c == '\0' || c == ' ' || c == '\t' || c == '\n'; 
}

int main(){
    int i;
    int last_blank;
    int j; /* index for next non-blank char. Used only after setting \0 */
    int blank_mode;
    int max; /* index for the folding barrier */
    char c;
    char num[LEN];
    char str[STR_SIZE];
    printf("Input number of columns until fold (choose it > 0)\n");
    ggetline(num, LEN);
    max = atoi(num) - 1;
    if(max < 0){
        fprintf(stderr, "input <= 0");
        exit(1);
    }
    printf("max: %d\n",max);
    blank_mode = 0;
    last_blank = -1;
    i = 0;
    while((c=getchar()) != EOF){
        if(i == 0 && is_blank(c)){
            continue;
        }
        printf("i:%d\n",i);
        if(i>=STR_SIZE){ 
            fprintf(stderr, "Line is too long, skipping to next one");  
            //TODO: Read until \n, reset all process
        }

        if(!blank_mode && is_blank(c)){
            blank_mode = 1;
            last_blank = i;
        }

        if(!is_blank(c)){
            blank_mode = 0;
            str[i] = c;
        }

        if(c == '\n'){
            i = max;
        }
        
        if(i >= max){ //TODO: or finds \n first, if so update max to be last char 
            if(last_blank != -1){ //if last_blank is currently set
                str[last_blank] = '\0';
                printf("%s\n", str);
                i=-1;
                j=last_blank;
                last_blank = -1;
                
                /* find next non-blank char after '\0'. Then, shift all chars read to the beginning of str[]. This is
                 * skipped whenever i>max because, in that case, no non-blank char is stored after '\0' */
                while(j <= max && is_blank(str[j])) {
                    j++;
                }
                
                while(j <= max){
                    str[i] = str[j];
                    i++;
                    j++;
                }
                    
            }
        }
        i++;
    }
    return 0;
}

int ggetline(char line[], int len)
{
    int i;
    char c;

    for(i=0; i<len-1 && ((c=getchar())!=EOF) && c!='\n'; ++i){
        line[i] = c;
    }

    line[i] = '\0';

    return i;
}

