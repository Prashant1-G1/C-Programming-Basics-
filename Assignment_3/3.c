#include <stdio.h>

int main()
{
    int num;
    int Armstrong = 0;
    int digit;

    printf("Enter the Number: ");
    scanf("%d", &num);

    int original = num; 

    while (num != 0)
    {
        digit = num % 10;
        Armstrong = Armstrong + digit * digit * digit; 
        num = num / 10;
    }

    if (Armstrong == original)
    {
      printf("%d is an Armstrong number\n", original);  
    } 
    else
    {
        printf("%d is NOT an Armstrong number\n", original);
    }
    return 0;
}
