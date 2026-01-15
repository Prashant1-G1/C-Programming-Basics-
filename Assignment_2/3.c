#include <stdio.h>

int main()
{
    float Radius, Area, Circumference;
    printf("Enter the Radius= ");
    scanf("%f",&Radius);

    Area=3.14*Radius*Radius;
    Circumference=2*3.14*Radius;

    printf("Area= %.2f square units\n", Area);
    printf("Circumference= %.2f units\n", Circumference);

    return 0;
    
}