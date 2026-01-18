#include <stdio.h>
#include <ctype.h>

int main()
{
    char choice;

    printf("Enter a Character: ");
    scanf("%c",&choice);

    choice=towlower(choice);
    
    switch (choice)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':

            printf("%c is Vowal",choice);
            break;

        default:
        printf("%c is Consonent",choice);
    }

    return 0;
}