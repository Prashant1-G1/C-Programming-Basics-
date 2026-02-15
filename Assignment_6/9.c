#include <stdio.h>
int main()
{
    int a=10;

    printf("Original Value: %d\n",a);

    int *const p=&a;

    *p=20;

    printf("Changed Value: %d",a);
    
    return 0;
}