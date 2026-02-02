#include <stdio.h>

int main()
{
    int odd=0, even=0 , n;

    printf("Enter the Number of array: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter %d Numbers\n",n);
    for (int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("%d Numbers in Array\n", n);
    for (int j=0; j<n; j++)
    {
        printf("%d ", arr[j]);
        if (arr[j]%2==0)
        {
            even++;
        }
        else{
            odd++;
        }
       
        
    }
     printf(" \n");
    printf("Number of Even Number: %d\n", even);
    printf("Number of Odd Number: %d\n", odd);







}