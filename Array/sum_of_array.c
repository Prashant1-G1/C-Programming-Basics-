#include <stdio.h>
#include <string.h>

int main()
{
    int numbers[10]={0,1,2,3,4,5,6,7,8,9}, sum=0;

    for (int i=0; i<10; i++)
    {
        sum=sum+numbers[i];

    }
    printf("Sum of Number in array= %d", sum);
    return 0;
}