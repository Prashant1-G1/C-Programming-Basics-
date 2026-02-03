#include <stdio.h>

int main()
{
    int arr[10]={1,23,45,67,12,2,4,7,8,10};
    int n,found=0;

    printf("Enter the Number you Want to Search in the Array: ");
    scanf("%d",&n);

    for (int i=0; i<10; i++)
    {
        if (arr[i]==n)
        {
            printf("Element Found!\n");
            printf("%d is At %d Position\n",n,i+1);
            found=1;
            break;
        }
    }
    if (!found)
    {
        printf("Element Not Found!\n");
        printf("%d is not in the Array.\n",n);
    }
    
    return 0;
}