
#include<stdio.h>

int main()
{
    float celsius;
    int lower, upper, step, fahr;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = upper;
    printf("Fahrenheit\tCelsius\n");
    while(fahr >= lower) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%d\t\t%.1f\n", fahr, celsius);
        fahr -= step;
    }
        
    return 0;
}
