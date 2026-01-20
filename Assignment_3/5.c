#include <stdio.h>

int main()
{
    int first=0, second=1, next, Num_term;

    printf("Enter the Number of Terms: ");
    scanf("%d",&Num_term);

    printf("       Fibonacci Sries     \n");

    for (int i=1 ; i<=Num_term; i++)
    {
        if (i==1)
        {
            printf("f(%d)= %d\n",i,first);
            continue;
        }
        else if(i==2)
        {
            printf("f(%d)= %d\n",i,second);
        }
        else
        {
            next=first+second;
            printf("f(%d)= %d\n", i, next);
            first=second;
            second=next;
        }
    }

    return 0;

}