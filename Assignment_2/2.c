#include <stdio.h>

int main()
{
    float num1;
    float num2; 
    float Divide,Add, Subtract, Multiplication;
    printf("Enter First Number: ");
    scanf("%f",&num1);
    printf("Enter Second Number: ");
    scanf("%f",&num2);

    Add=num1+num2;
    Subtract=num1-num2;
    Divide=num1 / num2;
    Multiplication=num1*num2;

    printf("Addition Result= %.2f\n",Add);
    printf("Subtraction Result= %.2f\n",Subtract);
    printf("Division Result= %.2f \n",Divide);
    printf("Multiplication Result= %.2f\n",Multiplication);

    return 0;
}
