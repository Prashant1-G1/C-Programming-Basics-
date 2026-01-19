#include <stdio.h>
int main()
{
    int a=5;

    printf("initial a=%d\n", a);

    //postfix increment

    printf("after postfix increment a= %d\n", a++);

    printf("a=%d\n",a);

    int b=5;

    // prefix increment

    printf("Inital b=%d\n",b);

    printf("after prefix increment=%d\n",++b);
}