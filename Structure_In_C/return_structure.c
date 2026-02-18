#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int age;
    int marks;
}Students;


//return type

Students Value_assign()
{
    Students s;

    s.age=14;
    s.marks=100;
    return s;
}

int main()
{
    Students s1;

    s1=Value_assign();

    printf("Age: %d\n",s1.age);
    printf("Marks: %d",s1.marks);

    return 0;
}