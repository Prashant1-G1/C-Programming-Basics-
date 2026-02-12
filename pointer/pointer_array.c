#include <stdio.h>
 
void modify(int arr[])
{
    printf("arr[0] = %d", *arr);
    arr[1]=200;
}

int main()
{
    int arr[3]={10,20,30};
    modify(arr);

    return 0;
}