#include <stdio.h>

long long int factorial( int n)
{
    if (n==0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }      
}

int main()
{
     int num;
    printf("Enter the Number: ");
    scanf("%d",&num);
    if (num<0)
    {
        printf("There is no Factorial of Negative Numbers.\n");
    }
    else
    {
        printf("Factorial of %d = %lld\n",num, factorial(num));
    }
    return 0;
}