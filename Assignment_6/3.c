#include <stdio.h>

int main()
{
    int n,sum;

    printf("Number of Elements in the Array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter Number %d:  ",i+1);
        scanf("%d",&arr[i]);
    }

    int *p=arr;

    for(int i=0; i<n; i++){
        sum+=*(p+i);
    }

    printf("\nSum= %d",sum);

    return 0;

}