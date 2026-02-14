#include <stdio.h>

int main()
{
    int n;
    printf("Number of Elements in the Array: ");
    scanf("%d",&n);

    int arr_1[n];
    int *ptr=arr_1;

    int arr_2[n];
    int *q = arr_2;

    for(int i=0; i<n; i++)
    {
        printf("Enter Number %d: ",i+1);
        scanf("%d",&arr_1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        *(q+i)=*(ptr+i);
    }

    printf("Coppied Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr_2[i]);
    }

    return 0;
}