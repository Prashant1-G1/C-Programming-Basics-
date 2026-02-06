#include <stdio.h>

int Sum_Array(int arr[], int size)
{
    int sum=0,i;
    for (i=0; i<size; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int main()
{
    int numbers[5]={1,2,3,4,5};
    
    int result=Sum_Array(numbers,5);

    printf("\nSum: %d",result);

    return 0;
}