
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, time;
    float Simple_Interest, Compound_Interest;

    
    printf("Enter Principal amount: ");
    scanf("%f", &principal);

    printf("Enter Rate of Interest (in %%): ");
    scanf("%f", &rate);

    printf("Enter Time (in years): ");
    scanf("%f", &time);

    
    Simple_Interest = (principal * rate * time) / 100;

    Compound_Interest=principal * pow((1 + rate / 100), time) - principal;

    printf("Simple Interest= %.2f\n",Simple_Interest);
    printf("Compound Interest= %.2f", Compound_Interest);

    return 0;

}