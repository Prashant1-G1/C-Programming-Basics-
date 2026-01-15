#include <stdio.h>
int main()
{
    int num1, num2, num3 , largest;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    largest= (num1>num2)? num1: num2;

    largest= (largest>num3)? largest:num3;

    printf("Largest Among Three Numbers= %d\n",largest);

    return 0;
}