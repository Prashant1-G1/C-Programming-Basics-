#include <stdio.h>
int main()
{
    int num, digit, Reverse=0, Original;

    printf("Enter the Number: ");
    scanf("%d",&num);

    Original=num;

    while (num!=0)
    {
        digit=num%10;
        Reverse=digit+Reverse*10;
        num=num/10;
    }

    if (Reverse==Original)
    {
        printf("%d is a Palindrome Number.\n",Original);
    }
    else
    {
        printf("%d is Not a Palindrome Number.\n", Original);
    }

    return 0; 
}