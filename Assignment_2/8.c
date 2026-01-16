#include <stdio.h>

int main() {
    int a = 6, b = 12;

    printf("a = %d, b = %d\n\n", a, b);

    // Bitwise AND
    printf("Bitwise AND (a & b) = %d\n", a & b);

    // Bitwise OR
    printf("Bitwise OR (a | b) = %d\n", a | b);

    // Bitwise XOR
    printf("Bitwise XOR (a ^ b) = %d\n", a ^ b);

    // Bitwise NOT
    printf("Bitwise NOT (~a) = %d\n", ~a);

    // Left shift
    printf("Left Shift (a << 1) = %d\n", a << 1);

    // Right shift
    printf("Right Shift (a >> 1) = %d\n", a >> 1);

    return 0;
}
