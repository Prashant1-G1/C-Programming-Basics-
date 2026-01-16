#include <stdio.h>

int main() {
    int a;

    // Prefix Increment
    a = 10;
    printf("Prefix Increment\n");
    printf("Initial value of a = %d\n", a);
    printf("Result of ++a = %d\n\n", ++a);

    // Postfix Increment
    a = 10;
    printf("Postfix Increment\n");
    printf("Initial value of a = %d\n", a);
    printf("Result of a++ = %d\n", a++);
    printf("Value of a after a++ = %d\n\n", a);

    // Prefix Decrement
    a = 10;
    printf("Prefix Decrement\n");
    printf("Initial value of a = %d\n", a);
    printf("Result of --a = %d\n\n", --a);

    // Postfix Decrement
    a = 10;
    printf("Postfix Decrement\n");
    printf("Initial value of a = %d\n", a);
    printf("Result of a-- = %d\n", a--);
    printf("Value of a after a-- = %d\n", a);

    return 0;
}
