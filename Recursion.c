#include <stdio.h>

void rec(int n)
{
    //Base case - where recurison stops
    if (n==6)
    {
        return;
    }
    else
    {
        printf("Recuriosn Level %d\n",n);
        rec(n+1);
    }
}

int main()
{
    rec(1);
    return 0;
}