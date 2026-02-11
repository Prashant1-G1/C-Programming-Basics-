#include <stdio.h>

void change(int *x)
{
    *x=50;
    printf("Inside function, x= %d\n",*x);


}

int main()
{
    int a=10;

    change(&a);

    printf("Outside fucntion, a= %d\n",a);

    return 0;

     
}