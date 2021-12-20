#include<stdio.h>

/* test with:
 * echo -e "Hola\testo\b es\una prueba; y esto, \\, una backslash " | ./1_10
 */
int main()
{
    int bc, nlc, tc;
    bc = nlc = tc = 0;
    char c;
    int in_blank = 0;
    while((c = getchar()) != EOF) {
        if(c == '\t'){
            putchar('\\');
            putchar('t');
        }else if(c == '\b'){
            putchar('\\');
            putchar('b');
        }else if(c == '\\'){
            putchar('\\');
            putchar('\\');
        }else{
            putchar(c);
        }
    }

    return 0;
}
