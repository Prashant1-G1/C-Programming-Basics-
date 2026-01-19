#include <stdio.h>
extern int myvar;

void myfunc();

int main(void)
{
    myvar=2;
    myfunc();
    return 0;
}