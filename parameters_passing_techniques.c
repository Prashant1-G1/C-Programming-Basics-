
#include <stdio.h>

// call by value 
void change(int x)
{
 x=20; //change happens only inside function
 printf("Inside function value of x=%d\n",x);
}

// call by reference
void change2(int *x)
{
    *x=20; // chnages original variable 
}

int main()
{
    int a=10;
    change(a);
    printf("value of a=%d\n",a);

    int b=10;
    change2(&b);
    printf("Value of b= %d",b);


    return 0;
}
