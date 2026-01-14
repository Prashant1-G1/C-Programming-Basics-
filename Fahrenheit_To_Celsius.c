// Fahrenheit To Celsius Converter Program
#include <stdio.h>

int main() 
{
    int Fahrenheit;
    float Celsius;
    
    printf("Enter Fahrenheit temperature: ");
    scanf("%d", &Fahrenheit);

    
    Celsius = 5.0 / 9.0 * (Fahrenheit - 32);

    printf("%10s%10s\n", "Fahrenheit", "Celsius");
    printf("%10d F %+10.3f C \n", Fahrenheit, Celsius);

    return 0;
}

