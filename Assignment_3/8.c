#include <stdio.h>

void break_statement(int num)
{
    for (int i=1; i<=num; i++)
    {
        if (i==5)
        {
            break;
        }
        else
        {
            printf("%d\n",i);
        }
    }
}

void Continue_statement(int num)
{
    for (int i=1; i<=num; i++)
    {
        if (i==5)
        {
            continue;
        }
        else
        {
            printf("%d\n",i);
        }
    }
}

int main()
{
    int num;

    printf("Enter a Number To See the Difference: ");
    scanf("%d",&num);

    printf("     When we Use Break Statement     \n");
    break_statement(num);

    printf("     When we Use Continue Statement   \n");
    Continue_statement(num);

    return 0;
}