#include <stdio.h>

void Student_Details(int Class, int Roll, char Name[], int Age) 
{
    printf("\n+--------------------------------------------------------------+\n");
    printf("|                        STUDENT DETAILS                       |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("| Class      | Roll       | Name                 | Age         |\n");
    printf("+--------------------------------------------------------------+\n");
    printf("| %-10d | %-10d | %-20s | %-10d |\n", Class, Roll, Name, Age);
    printf("+--------------------------------------------------------------+\n");
}

int main()
{
    int Class, Roll, Age;
    char Name[50];

    printf("Enter the Student's Class: ");
    scanf("%d", &Class);

    printf("Enter the Student's Roll Number: ");
    scanf("%d", &Roll);

    printf("Enter the Student's Name: ");
    scanf("%s", Name);   

    printf("Enter the Student's Age: ");
    scanf("%d", &Age);

    Student_Details(Class, Roll, Name, Age);

    return 0;
}
