#include <stdio.h>
// functions with no arg and return value
void greet()
{
    printf("Hello Teacher\n");
}

// fucntion with with arguments and no return value
void sum(int a , int b)
{
    printf("sum=%d\n",a+b);
}

int square(int n)
{
    return n*n;
}


int main()
{
    sum(10,20);
    printf(" \n");
    greet();
    printf(" \n");
    int result= square(17);
    printf("Square=%d\n",result);

    return 0;
}