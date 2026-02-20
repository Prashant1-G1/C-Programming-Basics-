#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct 
{
    int roll;
    char name[20];
    char Address[40];
    int age;
    int average_marks;
}Claas_12;


void Display(Claas_12 s1)
{
    printf("\nInformation of the Student:\n");
    printf("Roll: %d\n",s1.roll);
    printf("Name: %s",s1.name);
    printf("Address: %s",s1.Address);
    printf("Age: %d\n",s1.age);
    printf("Average Marks: %d",s1.average_marks);
}


int main()
{
    Claas_12 s;

    printf("Enter the Details\n");
    printf("Enter Roll Number: ");
    scanf("%d",&s.roll);
    printf("Enter Name: ");
    while (getchar()!='\n');
    fgets(s.name,sizeof(s.name),stdin);
    printf("Enter Address: ");
    fgets(s.Address, sizeof(s.Address), stdin);
    printf("Enter Age: ");
    scanf("%d",&s.age);
    printf("Enter Average Marks: ");
    scanf("%d",&s.average_marks);
    system('cls');

    Display(s);

    return 0;
}