#include <stdio.h>

int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10}, b[10]={11,12,13,14,15,16,17,18,19,20}, c[20];
    int i, j; 

    for ( i=0; i<10; i++)
    {
        c[i]=a[i];
    }

    for ( j=0; j<10; j++)
    {
        c[i+j]=b[j];
    }

    for (i=0; i<sizeof(c)/sizeof(a[0]); i++ )
        printf("%d ", c[i]);

    return 0;
}

