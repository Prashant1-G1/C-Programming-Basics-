#include <stdio.h>
#include <stdlib.h>

struct Students
{
    int Roll;
    char Name[20];
    int Age;
    int Marks;
};

int main()
{
    int n;
    

    printf("Total Number of Students: ");
    scanf("%d",&n);
    struct Students s[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter Information For Student %d\n",i+1);
        printf("Roll Number: ");
        scanf("%d",&s[i].Roll);
        while(getchar() != '\n');
        printf("Name: ");
        fgets(s[i].Name,sizeof(s[i].Name),stdin);
        printf("Age: ");
        scanf("%d",&s[i].Age);
        printf("Marks: ");
        scanf("%d",&s[i].Marks);
        system("cls");
    }

    

    for(int i=0; i<n; i++)
    {
        printf("\nInformation of Student %d\n",i+1);
        printf("Roll Nubmer: %d\n",s[i].Roll);
        printf("Name: %s",s[i].Name);
        printf("Age: %d\n",s[i].Age);
        printf("Marks: %d\n",s[i].Marks);
    }

    return 0;

}
