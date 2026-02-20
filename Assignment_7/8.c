
#include <stdio.h>
#include <string.h>


struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student s1;
    struct Student *ptr;

    
    s1.roll = 101;
    strcpy(s1.name, "Alice");
    s1.marks = 95.5;

    
    ptr = &s1;

    printf("Using pointer to access structure members:\n");
    printf("Roll No: %d\n", ptr->roll);
    printf("Name    : %s\n", ptr->name);
    printf("Marks   : %.2f\n", ptr->marks);

    return 0;
}