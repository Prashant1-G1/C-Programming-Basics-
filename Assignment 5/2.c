#include <stdio.h>
int main()
{
    int n, sum=0, position=1;

    printf("Number of Elements in the Array: ");
    scanf("%d",&n);

    int arr[n];

    for (int i=0; i<n; i++)
    {
        printf("Enter Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    for (int j=0; j<n; j++)
    {
        sum+=arr[j];
    }

    printf("Sum of all Elements: %d",sum);


}