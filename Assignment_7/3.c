#include <stdio.h>
#include <math.h>
#include <stdlib.h>


struct Distance {
    int feet;
    float inches;
};

int main() {
    struct Distance d1, d2, sum;

    
    printf("Enter first distance:\n");
    printf("Feet: ");
    scanf("%d", &d1.feet);
    printf("Inches: ");
    scanf("%f", &d1.inches);

    
    printf("Enter second distance:\n");
    printf("Feet: ");
    scanf("%d", &d2.feet);
    printf("Inches: ");
    scanf("%f", &d2.inches);

    system("cls");


    sum.feet = d1.feet + d2.feet;
    sum.inches = d1.inches + d2.inches;

    
    if (sum.inches >= 12.0) {
        sum.feet += (int)(sum.inches / 12);
        sum.inches = fmod(sum.inches, 12.0);
    }

    printf("Total distance = %d feet %.2f inches\n", sum.feet, sum.inches);

    return 0;
}
