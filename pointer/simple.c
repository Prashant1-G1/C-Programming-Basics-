#include <stdio.h>
int main()
{
    int n=10;

    int *p=&n;

    printf("Address of N is: %d  \n",p);

    printf("Accessing value of N using Pointer: %d\n",*p);

    *p=30;

    printf("Value Changed for N: %d",n);
    
    return 0;
}