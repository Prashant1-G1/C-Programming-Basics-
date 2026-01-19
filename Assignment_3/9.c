#include <stdio.h>
int main()
{
    int num, i, factorial=1;

    printf("Enter the Number: ");
    scanf("%d", &num);

    if (num<0)
    {
        printf("Factorial is not defined for Negative Numbers!");
    }
    else
    {
        for (i=num; i>=1; i--)
        {
            factorial=factorial*i;
        }
        printf("The Factorial of %d = %d\n", num, factorial);
    }
    return 0;
}