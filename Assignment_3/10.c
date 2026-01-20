#include <stdio.h>
int main()
{
    int Marks;
    
    printf("Enter the Marks Obtained: ");
    scanf("%d", &Marks);

    if (Marks<50)
    {
        printf("Grade=F");
    }
    else if (50<=Marks<60)
    {
        printf("Grade=D");
    }
    else if (60<=Marks<70)
    {
        printf("Grade=C");
    }
    else if (70<=Marks<80)
    {
        printf("Grade=B");
    }
    else if (80<=Marks<90)
    {
        printf("Grade=A");
    }

    return 0;

}