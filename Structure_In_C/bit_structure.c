#include <stdio.h>

struct Students
{
    //unsigned mean only positive numbers
    unsigned int isPassed : 1;//1 bit
    unsigned int grade : 3; // 2bits
    unsigned int section : 2; // 2bits
};

int main()
{
    struct Students s;

    s.isPassed=1;
    s.grade=5;
    s.section=2;

    printf("Passed: %u\n",s.isPassed);
    printf("Grade: %u\n",s.grade);
    printf("Section: %u",s.section);

    return 0;
}