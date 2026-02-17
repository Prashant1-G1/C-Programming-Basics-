#include <stdio.h>
#include <stdlib.h>

struct Marks
    {
        int English;
        int Math;
        int Nepali;
        int Computer;
    };  

struct  Students
{
    int Roll;
    char Name[20];
    int Age; 
    struct Marks m;
};


int main()
{
    struct Students s1;

    printf("Enter Roll Number: ");
    scanf("%d",&s1.Roll);
    printf("Enter Name: ");
    while(getchar()!='\n');
    fgets(s1.Name, sizeof(s1.Name),stdin);
    printf("Enter Age: ");
    scanf("%d",&s1.Age);
    printf("Marks:\n");
    printf("English: ");
    scanf("%d",&s1.m.English);
    printf("Math: ");
    scanf("%d",&s1.m.Math);
    printf("Nepali: ");
    scanf("%d",&s1.m.Nepali);
    printf("Computer: ");
    scanf("%d",&s1.m.Computer);
    system("cls");

    printf("Information of the Student\n");
    printf("Roll Number: %d\n",s1.Roll);
    printf("Name: %s",s1.Name);
    printf("Age: %d\n",s1.Age);
    printf("Marks Obtained:\n");
    printf("English: %d\n",s1.m.English);
    printf("Math: %d\n",s1.m.Math);
    printf("Nepali: %d\n",s1.m.Nepali);
    printf("Computer: %d\n",s1.m.Computer);

    return 0;
}
