#include <stdio.h>
#include <math.h>

int main() {
    double a = 16.0;
    double b = 3.0;
    double c = -7.5;

    // 1. Square root
    printf("Square root of %.2lf = %.2lf\n", a, sqrt(a));

    // 2. Power
    printf("%.2lf raised to %.2lf = %.2lf\n", a, b, pow(a, b));

    // 3. Absolute value
    printf("Absolute value of %.2lf = %.2lf\n", c, fabs(c));

    // 4. Ceiling
    printf("Ceiling of %.2lf = %.2lf\n", c, ceil(c));

    // 5. Floor
    printf("Floor of %.2lf = %.2lf\n", c, floor(c));

    return 0;
}
