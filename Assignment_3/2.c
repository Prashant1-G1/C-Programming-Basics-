#include <stdio.h>
int Find_Largest(int a, int b , int c)
{
    int Largest= a;

    Largest=(b>Largest)? b : Largest;
    Largest=(c>Largest)? c : Largest;

    return Largest;
} 

int Find_Smallest(int a , int b , int c)
{
    int Smallest= a;

    Smallest=(b<Smallest)? b: Smallest;
    Smallest=(c<Smallest)? c: Smallest;

    return Smallest;
} 

void CheckOddEven(int num)
{
    if (num % 2 == 0)
        printf("%d is Even\n",num);
    else
        printf("%d is Odd\n",num);   
}

int main()
{
 int num1, num2, num3;
 int largest, smallest;

    printf("Enter the First Number: ");
    scanf("%d",&num1);

    printf("Enter the Second Number: ");
    scanf("%d",&num2);

    printf("Enter the Third Number: ");
    scanf("%d",&num3);

    largest=Find_Largest(num1,num2,num3);

    smallest=Find_Smallest(num1,num2,num3);

    printf("Largest Number= %d\n",largest);
    CheckOddEven(largest);

    printf("Smallest Number= %d\n",smallest);
    CheckOddEven(smallest);

    return 0;
}