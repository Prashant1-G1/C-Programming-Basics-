#include <stdio.h>

void nestedifelse()
{
    int age=-9;

    if (age>=18)
    {
        if(age>=60)
        {
            printf("ELigible for vote (Senior Citizen)\n");
        }
        else
        {
            printf("Eligible for vote\n");
        }
    }
    else if (age<0)
    {
        printf("The Person hasn't been born yet\n");
    }
    else
    {
        printf("Not Eligible for to Vote (under 18)\n");
        if (age>=13)
        {
            printf("Teenager\n");
        }
        else
        {
            printf("Not a Teenager\n");
        }
    }
}
void switchstatement()
{
    int ages=18;

    switch (ages)
    {
        case 18:
            printf("Eligible for Vote\n");
            break;
        case 15:
            printf("Not Eligible for vote\n");
            break;
        default:
            printf("Default value execuated\n");
            break;
    }
}
int main()
{
    int age=20;

    if (age>=18)
    {
        printf("Eligible for Vote with age %d\n", age);
    }
    else
    {
     printf(
            "Not Eligible for Vote\n"
        );   
    }

    nestedifelse();

    switchstatement();
        
    return 0;
}