#include <stdio.h>

int sum (int a , int b )
{
    return a+b;
}
int multi(int c, int d)
{
    return c*d;
}
int main()
{
    int result=sum(5,9) , result2=multi(5,5);
    printf("SUM: %d\n",result);
    printf("Multiply: %d\n",result2);
    return 0; 
}