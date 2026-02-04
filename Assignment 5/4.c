#include <stdio.h>
int main()
{
    int n;

    printf("Number of Elements in The Array: ");
    scanf("%d",&n);

    int k=n-1;
    int j=0;

    int numbers[n];

    for (int i=0; i<n; i++)
    {
        printf("Enter Number %d: ", i+1);
        scanf("%d",&numbers[i]);
    }

    printf("Normal Array\n");
    for (int i=0; i<n; i++)
    {
        printf("%d ",numbers[i]);
    }
    

    while (j < k)
    {
        int temp=numbers[j];
        numbers[j]=numbers[k];
        numbers[k]=temp;
        j++;
        k--;
    }

    printf("\nReversed Array\n");
    for (int i=0; i<n; i++)
    {
        printf("%d ",numbers[i]);
    }
    
    return 0;
}