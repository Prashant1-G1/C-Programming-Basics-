#include <stdio.h>
int main()
{
    int arr[5];

    int *p=arr;

    printf("Enter 5 Integers:\n");
    for(int i=0; i<5; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf(   "Value : Address\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d     : %p     \n",*p, p);
        p++;
    }

    return 0;
    

}