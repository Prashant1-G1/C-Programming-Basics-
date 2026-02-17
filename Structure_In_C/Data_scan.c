#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    int Roll;
    char Name[20];
}Strudents;

int main()
{
    Strudents s[3];

    for(int i=0; i<3; i++)
    {
        printf("Roll: ");
        scanf("%d",&s[i].Roll);
        while(getchar()!='\n');
        printf("Name: ");
        fgets(s[i].Name,sizeof(s[i].Name),stdin);
        system("cls");
        
    }
    for(int i=0; i<3; i++)
    {
        printf("Information of Student %d\n",i+1);
        printf("Name: %s",s[i].Name);
        printf("Roll: %d\n",s[i].Roll);
        printf("\n");
    }

    return 0;
}

