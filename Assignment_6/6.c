#include <stdio.h>

void Swap_value(int *a, int *b)
{
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;
}


int main()
{
    int num1, num2;

    printf("Enter 1st Number: ");
    scanf("%d",&num1);
    printf("Enter 2nd Number: ");
    scanf("%d",&num2);

    printf("Unswapped Values\n");
    printf("1st Number: %d\n",num1);
    printf("2nd Number: %d\n",num2);

    Swap_value(&num1,&num2);

    printf("Swapped Values\n");
    printf("1st Number: %d\n",num1);
    printf("2nd Number: %d",num2);

    return 0;
}