#include <stdio.h>

int main()
{
    int arr[3]={1,2,3};
    int *p=arr;

    printf("Value at P: %d\n",*p);

    // It does not add 1 to address.
    // int is 4 bytes
    // p+1 =1000+4=1004


    printf("Value at P+1: %d\n",*(p+1));

    printf("Value at P+2: %d\n",*(p+1));

    return 0;
}

int main()
{
    int arr[3]={10,20,30};

    int *p=arr;

    printf("Before p++: %d\n",*p);
    p++;
    printf("After P++: %d\n",*p );

    return 0;
}