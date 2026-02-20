#include <stdio.h>


struct Student {
    char name[50];
    int age;
    float marks;
};


void display(struct Student s) {
    printf("\nStudent Details:\n");
    printf("Name  : %s\n", s.name);
    printf("Age   : %d\n", s.age);
    printf("Marks : %.2f\n", s.marks);
}

int main() {
    struct Student s1;

    printf("Enter name: ");
    scanf("%s", s1.name);

    printf("Enter age: ");
    scanf("%d", &s1.age);

    printf("Enter marks: ");
    scanf("%f", &s1.marks);

    
    display(s1);

    return 0;
}