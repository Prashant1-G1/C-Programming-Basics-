#include <stdio.h>
int main()
{
    int variable=10;

    int *pointer_variable;

    pointer_variable=&variable;

    printf("Value of num: %d\n", variable);
    printf("Address of num: %p\n", &variable);
    printf("Value stored in ptr (address of num): %p\n",pointer_variable);
    printf("Value pointed to by ptr: %d\n", *pointer_variable);
}