#include <stdio.h>

void value_swap(int *a, int *b)
{
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;

}

int main()
{
    int x;
    int y;

    printf("Enter 1st Number: ");
    scanf("%d",&x);

    printf("Enter 2nd Number: ");
    scanf("%d",&y);

    printf("\n      Initial Value     \n");

    printf("Value of X: %d\n",x);

    printf("Value of Y: %d\n",y);

    value_swap(&x, &y);

    printf("    Swapped Value    \n");

    printf("Value of X: %d\n",x);

    printf("Value of Y: %d", y);


}