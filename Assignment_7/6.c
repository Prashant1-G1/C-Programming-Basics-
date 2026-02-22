#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    float real;
    float imaginary;
}Complex;

int main()
{
    Complex c1, c2, sum, diff;

    printf("Enter Real and Imaginary Part of First Complex Number: ");
    scanf("%f %f",&c1.real,&c1.imaginary);

    printf("Enter Real and Imaginary Part of Second Complex Number: ");
    scanf("%f %f",&c2.real,&c2.imaginary);

    sum.real=c1.real+c2.real;
    sum.imaginary=c1.imaginary+c2.imaginary;

    diff.real=c1.real-c2.real;
    diff.imaginary=c1.imaginary-c2.imaginary;

    printf("\nSum: %.2f + %.2fi\n",sum.real,sum.imaginary);
    printf("\nDifference: %.2f + %.2fi\n",diff.real,diff.imaginary);
}
