#include<stdio.h>

int main()
{
    float fahr;
    int lower, upper, step, celsius;

    lower = -20;
    upper = 150;
    step = 10;
    celsius = lower;
    printf("Celsius\tFahrenheit\n");
    while(celsius <= upper) {
        fahr = (9.0 * celsius)/5.0 + 32.0;
        printf("%d\t%.1f\n", celsius, fahr);
        celsius += step;
    }
        
    return 0;
}
