#include <stdio.h>

int* func_Array()
{
    static int array[5]={1,2,3,4,5};
    return array;
}

int main()
{
    int i;
    int *Array;

    Array=func_Array();

    for (i=0; i<5; i++)
    {
        printf("%d ",Array[i]);
    }
} 