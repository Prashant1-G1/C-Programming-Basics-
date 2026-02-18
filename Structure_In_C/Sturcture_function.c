#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char Name[20];
    int roll;
    float marks;
}Students;

// function wiht normal structure parameter

void display( Students s)
{
    printf("\nStudent Details\n");
    printf("Name: %s",s.Name);
    printf("Roll: %d\n",s.roll);
    printf("Marks: %.2f\n",s.marks);
}

void display_Pointer(Students *s)
{
    //TO access mumber of pointer structure we use -> instead of .
    printf("\nStudent Details\n");
    printf("Name: %s",(*s).Name);
    printf("Roll: %d\n",(*s).roll);
    //OR
    printf("Makrs: %.2f",s->marks);
}


int main()
{
    Students s;

    printf("Enter Roll Number: ");
    scanf("%d",&s.roll);
    printf("Enter Name: ");
    while(getchar()!='\n');
    fgets(s.Name,sizeof(s.Name),stdin);
    printf("Enter Marks: ");
    scanf("%f",&s.marks);
    system("cls");


    display(s);

    display_Pointer(&s);
    
}
