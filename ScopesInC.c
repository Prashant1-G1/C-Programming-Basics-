#include <stdio.h>
int age=19;//Gloabal scope 

void ol()
{
    printf("My age is %d.\n",age);
}
int main()
{
    int year=2006; //Local scope 

    ol();

    printf("I am %d years old. I was born in %d.",age,year);

    return 0;
}