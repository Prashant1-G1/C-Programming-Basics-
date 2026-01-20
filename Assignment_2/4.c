#include <stdio.h>

int main() {
    int num1, num2, temp;

    printf("Enter the First Variable: ");
    scanf("%d", &num1);
    printf("Enter the Second Variable: ");
    scanf("%d", &num2);
    printf(" ");

    // Using Third Variable
    temp = num1;
    num1 = num2;
    num2 = temp;

    printf("        Swap Using Third Variable    \n");
    printf("Swapped First Variable: %d\n", num1);
    printf("Swapped Second Variable: %d\n\n", num2);

    // Without Using Third Variable
    int num3, num4;

    printf("Enter the First Variable: ");
    scanf("%d", &num3);
    printf("Enter the Second Variable: ");
    scanf("%d", &num4);

    num3 = num3 + num4;
    num4 = num3 - num4;
    num3 = num3 - num4;

    printf("        Swap Without Using Third Variable     \n");
    printf("Swapped First Variable: %d\n", num3);
    printf("Swapped Second Variable: %d\n", num4);

    return 0;
}
