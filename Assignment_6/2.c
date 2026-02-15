#include <stdio.h>

int compareStrings(char *str1, char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int main() {
    char str1[50], str2[50];

    printf("Enter first string: ");
    scanf("%50s", str1);

    printf("Enter second string: ");
    scanf("%50s", str2);

    int result = compareStrings(str1, str2);

    if (result == 0)
        printf("The strings are equal.\n");
    else if (result < 0)
        printf("The first string is less than the second string.\n");
    else
        printf("The first string is greater than the second string.\n");

    return 0;
}
