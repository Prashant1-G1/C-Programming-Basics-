#include <stdio.h>

union Students
{
    int rollNO;
    union Academic
    {
        int marks;
    }performance;
    
};

int main()
{
    union Students st1;

    st1.rollNO=21;
    printf("%d\n",st1.rollNO);
    st1.performance.marks=91;
    printf("%d\n",st1.performance.marks);
}