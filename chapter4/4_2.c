#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXLINE 1000

double atof(char s[]){
    double val, power, pow2;
    int i, sig, sig2;
    pow2 = 0;
    sig2 = 0;

    for(i=0; isspace(s[i]); i++);

    sig = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++){
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    val = (sig * val / power);

    if (s[i] == 'e' || s[i] == 'E')
        i++;

    if (s[i] == '-'){
        sig2 = 1;
    }

    if (s[i] == '+' || s[i] == '-')
        i++;

    for(; isdigit(s[i]); i++){
        pow2 = 10.0 * pow2 + (s[i] - '0');
    }

    for (int j=0; j<pow2; j++){
        if(sig2){
            val /= 10;
        }else{
            val *= 10;
        }
    }

    return val;
}

int main(){
    char s[] = "123.28e-3";
    
    printf("%f\n", atof(s));
    return 0;
}
