//enum is just a way to give names to numbers 

#include <stdio.h>

//Enum values;
// Always integers;
// starts from 0 by default
// increase by 1 automatically

//can be manually assigned
enum Result
{
    Fail,//=0
    Pass//=1
};

int main()
{
    enum Result res=Pass;
    printf("%d\n",res);

    if (res==1)
    {
        printf("Student passed\n");
    }
    else if(res==0)
    {
        printf("Student Failed");
    }
}