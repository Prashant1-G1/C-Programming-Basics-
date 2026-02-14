#include <stdio.h>
int main()
{
    int a, b, c;

    int *ptr_1=&a;
    int *ptr_2=&b;
    int *ptr_3=&c;

    printf("Enter 1st Number: ");
    scanf("%d",&a);

    printf("Enter 2nd Number: ");
    scanf("%d",&b);

    printf("Enter 3rd Number: ");
    scanf("%d",&c);

    int biggest;
    int *ptr_4=&biggest;

    ptr_4=(*ptr_1>*ptr_2)?ptr_1:ptr_2;
    ptr_4=(*ptr_4>*ptr_3)?ptr_4:ptr_3;

    printf("Biggest Number Among Three Number is: %d",*ptr_4);

    return 0;
}