#include <stdio.h>

int Nth_fibonacci(int x)
{
    if (x==0)
        return 0;
    else if (x==1)
        return 1;
    else
        return Nth_fibonacci(x-1)+Nth_fibonacci(x-2);
}

int main()
{
    int n, a;

    printf("Enter the Nth Term: ");
    scanf(" %d",&n);

    a=Nth_fibonacci(n);

    printf("Nth Fibonacci Number = %d\n",a);

    return 0;
    
}