#include <stdio.h>
#include <math.h>

void Armstrong(int num)
{
    int original = num;
    int sum = 0;

    while (num > 0)
    {
        int digit = num % 10;
        sum += digit * digit * digit; 
        num = num / 10;
    }

    if (sum == original)
    {
        printf("%d is an Armstrong number.\n", original);
    }
    else
    {
        printf("%d is Not an Armstrong number.\n", original);
    }
}

void prime(int num)
{
    if (num <= 1)
    {
        printf("%d is Not a Prime Number\n", num);
        return;
    }

    int count = 0;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }

    if (count == 2)
    {
        printf("%d is a Prime Number\n", num);
    }
    else
    {
        printf("%d is Not a Prime Number\n", num);
    }
}

void Natural(int num)
{
    if (num > 0)
    {
        printf("%d is a Natural Number\n", num);
    }
    else
    {
        printf("%d is Not a Natural Number\n", num);
    }
}

int main()
{
    int x;
    printf("Enter the Number: ");
    scanf("%d", &x);

    Armstrong(x);
    prime(x);
    Natural(x);

    return 0;
}
