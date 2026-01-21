#include <stdio.h>
// #include <conio.h>  // Optional, mostly for getch() in Turbo C/C++.
int main()  // We have to use int main() instead of void main() since we are returning a interger value.
{
    int i = 1;
    do
    {
        printf("%d \n", i);  
        i++;
    }
    while(i <= 10);  // added a missing semicolon here

    // getch();  // Optional, only needed in some old compilers, to show to result. Specially, in turbo c/c++.
    return 0;
}
