#include <stdio.h>

int addition(int num1, int num2)
{
    return num1+num2;
}

int subtraction(int num1, int num2)
{
    return num1-num2;
}

int Multiplication(int num1 , int num2)
{
    return num1*num2;
}

float Division(int num1, int num2)
{
    if (num2==0)
    {
        printf("Can't Divide By 0");
    }
    else
    {
        return (float)num1/num2;
    }
}

int main()
{
    int num1 , num2;

    printf("Enter the 1st Number=");
    scanf("%d",&num1);
    printf("Enter the 2nd Number=");
    scanf("%d",&num2);

    printf("Addition=%d\n",addition(num1, num2));
    printf("Subtraction=%d\n",subtraction(num1,num2));
    printf("Multiphication=%d\n",Multiplication(num1,num2));
    printf("Division=%.2f\n",Division(num1,num2));

}