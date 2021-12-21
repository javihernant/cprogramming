
#include<stdio.h>

float to_celsius(float fahr){
    return (5.0/9.0) * (fahr - 32.0);
}

int main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    printf("Fahrenheit\tCelsius\n");
    while(fahr <= upper) {
        printf("%.1f\t\t%.1f\n", fahr, to_celsius(fahr));
        fahr += step;
    }
        
    return 0;
}
