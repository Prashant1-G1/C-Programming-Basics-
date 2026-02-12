#include <stdio.h>

//case 1 - pointer can be chnaged but not value
int main()
{
    int a=10;
    int b=20;

    const int *p=&a;

    p=&b; //allowed (pointer chnaged)

    //*p=30; // not allowed (value change not allowed)
}

//Case 2 - Pointer can't be changed but value can be changed
int main()
{
    int a = 10;
    int b = 20;

    int *const p = &a;
    *p = 30; //allowed (value changed)
    // p = &b; // not allowed (pointer cannot be changed)
}

// Case 3- Pointer and  value can't be changed

int main()
{
    int a=10;


    const int const *p= &a;

}
