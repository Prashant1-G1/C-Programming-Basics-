#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    int age;
    char Name[20];
    int number; 
}Students;

void display_Pointer(Students *s)
{
    printf("\nStudent Details\n");
    printf("Age: %d\n",(*s).age);
    printf("Name: %s",(*s).Name);
    //OR
    printf("Number: %d",s->number);
}


int main()
{
    Students s1;

    printf("Enter Age: ");
    scanf("%d",&s1.age);
    printf("Name: ");
    while (getchar()!='\n');
    fgets(s1.Name,sizeof(s1.Name),stdin);
    printf("Number: ");
    scanf("%d",&s1.number);

    display_Pointer(&s1);
    
    return 0;
}