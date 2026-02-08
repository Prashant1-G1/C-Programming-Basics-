#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() 
{
    FILE *fp;
    struct Student s;
    int i, rollToSearch, found = 0;

    // Open file for writing
    fp = fopen("student.txt","w");
    if(fp == NULL)
    {
        printf("File didn't open.\n");
        return 1;
    }

    printf("Enter Student Details\n");
    for (i=0; i<5; i++)
    {
        printf("Enter Roll, Name, and Marks For student %d: ", i+1);
        scanf("%d %s %f", &s.roll, s.name, &s.marks);
        fprintf(fp, "%d %s %.2f\n", s.roll, s.name, s.marks);
    }
    fclose(fp);

    // Open file for reading
    fp = fopen("student.txt", "r");
    if(fp == NULL)
    {
        printf("File didn't open for reading.\n");
        return 1;
    }

    printf("Enter the Roll Number to Search: ");
    scanf("%d", &rollToSearch);

    while (fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) == 3)
    {
        if (s.roll == rollToSearch)
        {
            printf("Roll Number Found successfully.\n");
            printf("Roll: %d\nName: %s\nMarks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("Roll number is not in the list\n");
    }

    fclose(fp);
    return 0;
}
