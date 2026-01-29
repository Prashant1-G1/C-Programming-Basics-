#include <stdio.h>


int sum(int a, int b) 
{
    return a + b;
}

float average(int a, int b) 
{
    
    int total = sum(a, b);
    return total / 2.0;
}

int main() {
    int num1, num2;
    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("Sum of %d and %d = %d\n", num1, num2, sum(num1, num2));
    printf("Average of %d and %d = %.2f\n", num1, num2, average(num1, num2));

    return 0;
}
