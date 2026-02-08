#include <stdio.h>
int main()
{
    int n;
    int i,position;
    printf("Number of Elements in Array: ");
    scanf("%d",&n);

    int Number[n];

    for(i=0; i<n; i++)
    {
        printf("Enter Element %d : ",i+1);
        scanf("%d",&Number[i]);
    }


    printf("\nEnter the Position for Deletion: ");
    scanf("%d",&position);

    if(position<1 || position>n)
    {
        printf("\nInvalid Position!\n");
        printf("Try Again.\n");
    }
    else
    {
        for(i=position-1; i<n-1; i++)
        {
            Number[i]=Number[i+1];
        }
    }
    n--;

    printf("\nArray After Deletion\n");
    for(i=0; i<n; i++)
    {
        printf("%d ",Number[i]);
    }

}