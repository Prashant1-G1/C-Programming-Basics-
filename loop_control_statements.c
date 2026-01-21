#include <stdio.h>
int main()
{
    int i, x;

    for (i=0; i<=5; i++)
    {
        if (i==3)
        {
            break;
        }
        printf("%d\n",i);
    }
printf(" \n");

    for (x=0; x<=5; x++)
    {
        if (x==3)
        {
            continue;
        }
        printf("%d\n",x);
    }



printf(" \n");

for (int i=0; i<=5; i++)
{
    if (i==3)
    {
        goto phase1;
    }
    printf("%d\n",i);
}
phase1:
    printf("\n Jumped to the 'Phase 1' lebel%s",
    "When i equals 3.\n");
}