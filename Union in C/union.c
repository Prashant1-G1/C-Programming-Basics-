#include <stdio.h>

union Number
{
    int i;
    float f;
};

int main()
{
    union Number n;

    n.i=25;
    //Memory stores integers 25;
    printf("Integer: %d\n",n.i);

    //Now the same memory is overwritten with float 7.5
    n.f=7.5;
    printf("FLoat: %f\n",n.f);
    
    //Now we try to read i again. But memory currently contain flaot value, not integer
    printf("Integer afeter assignning float: %d\n",n.i);//here 7.5 is stored in decimal format still after using %d it
                                                        //shoud have printed in integer but it doesn't.

    return 0;

}