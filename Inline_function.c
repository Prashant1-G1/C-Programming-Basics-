#include <stdio.h>

//Normal Function

int square(int a)
{
    return a*a;
}



int main()
{
    int b=square(5);  //program jumps to Square() and comes back
    printf("%d\n",b);
    return 0;
}


#include <stdio.h>

static inline int square(int a)
{
    return a*a;
}



int main()
{
    int b=square(5);  // Compiler replaces square(5) with 5*5
    printf("%d",b);   // NO jumping -> faster.
    return 0;                    
}
