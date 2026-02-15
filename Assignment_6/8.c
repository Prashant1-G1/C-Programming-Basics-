#include <stdio.h>
#include <string.h>

int main()
{
    char str[20];
    int Consonents=0, Vovels=0;
    

    printf("Enter a string: ");
    scanf("%s",&str);

    strupr(str);
    char *ptr;
    ptr=str;


    while(*ptr!='\0')
    {
        if (*ptr == 'A' || *ptr == 'E' || *ptr == 'I' || 
            *ptr == 'O' || *ptr == 'U')
            {
                Vovels++;
            }
        else
        {
            Consonents++;
        }

        ptr++;
    }

    printf("Consonents= %d\n",Consonents);
    printf("Vovels= %d",Vovels);

    return 0;
    

}