#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Enter the First Variable: ");
    scanf("%d",&num1);
    printf("Enter the Second Variable: ");
    scanf("%d",&num2);

    num1=num1+num2;
    num2=num1-num2;
    num1=num1-num2;

    printf("Swaped First Variable: %d\n", num1);
    printf("Swaped Second Variable: %d\n", num2);

    return 0;

}