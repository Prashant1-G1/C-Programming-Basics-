#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "hEllo";
    char t[] = "World";
    char r[] = "help";

    // strlen
    printf("String Length = %lu\n", strlen(s));

    // strupr
    printf("Upper Character = %s\n", strupr(s));

    // strlwr
    printf("Lower Character = %s\n", strlwr(s));

    // strcat
    strcat(s, t);
    printf("Appended String = %s\n", s);

    // strcmp
    int cmp = strcmp(r, t);
    if(cmp == 0)
        printf("Strings \"%s\" and \"%s\" are equal\n", r, t);
    else if(cmp < 0)
        printf("String \"%s\" is less than \"%s\"\n", r, t);
    else
        printf("String \"%s\" is greater than \"%s\"\n", r, t);

    return 0;
}
