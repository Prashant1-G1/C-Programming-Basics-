#include <stdio.h>

int main()
{
    int i, j, spaces, row = 6;

    for (i = 1; i <= row; i++)
    {
        
        for (spaces = 1; spaces < i; spaces++)
        {
            printf(" ");
        }

        
        for (j = 1; j <= 2 * (row - i) + 1; j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}
