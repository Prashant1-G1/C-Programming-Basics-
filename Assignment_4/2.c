#include <stdio.h>

// Swap using Call by Value
void Swapvalue(int a, int b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;

    printf("     Swapped Value (Call by Value)    \n");
    printf("1st Number = %d\n", a);
    printf("2nd Number = %d\n", b);
}

// Swap using Call by Reference
void swapvalue2(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int num1, num2;

    printf("   Using Call by Value   \n");
    printf("Enter the value of 1st Number = ");
    scanf("%d", &num1);
    printf("Enter the value of 2nd Number = ");
    scanf("%d", &num2);

    printf("     Initial Value    \n");
    printf("1st Number = %d\n", num1);
    printf("2nd Number = %d\n", num2);

    Swapvalue(num1, num2);

    printf("\nAfter Call by Value (in main):\n");
    printf("1st Number = %d\n", num1);
    printf("2nd Number = %d\n", num2);

    int num3, num4;

    printf("\n   Using Call by Reference   \n");
    printf("Enter the value of 1st Number = ");
    scanf("%d", &num3);
    printf("Enter the value of 2nd Number = ");
    scanf("%d", &num4);

    printf("     Initial Value    \n");
    printf("1st Number = %d\n", num3);
    printf("2nd Number = %d\n", num4);

    swapvalue2(&num3, &num4);

    printf("     Swapped Value (Call by Reference)   \n");
    printf("1st Number = %d\n", num3);
    printf("2nd Number = %d\n", num4);

    return 0;
}
