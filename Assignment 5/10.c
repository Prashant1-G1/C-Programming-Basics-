#include <stdio.h>

int main()
{
    int Number[10]={1,2,3,4,5,6,7,8,9,10};

    int i, j, temp;

    //code for Ascending order
    for (i=0; i<10; i++)
    {
        for(j=i+1; j<10; j++)
        {
            if (Number[i]>Number[j])
            {
                temp=Number[i];
                Number[i]=Number[j];
                Number[j]=temp;
            }
        }
    }  

    printf("\nAscending Order of Array\n");
    for(i=0; i<10; i++)
    {
        printf("%d ",Number[i]);
    }


    //code for Descending order 
    for(i=0; i<10; i++)
    {
        for (j=i+1; j<10; j++)
        {
            if (Number[i]<Number[j])
            {
                temp=Number[i];
                Number[i]=Number[j];
                Number[j]=temp;
            }
        }
    }

    printf("\nDescending Order of Array\n");
    for(i=0; i<10; i++)
    {
        printf("%d ",Number[i]);
    }

    return 0;
}