#include <stdio.h>
#include <string.h>

int main()
{
    //multiple values at a time
    int numbers[11]={0,1,2,3,4,5,6,7,8,9};

    //one by one for remaining space
    numbers[10]=10;

    for (int i=0; i<11; i++)
    {
        printf("%d\n",numbers[i]);
    }
    return 0;
}