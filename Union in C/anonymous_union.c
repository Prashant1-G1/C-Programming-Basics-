#include <stdio.h>

struct data
{
    int type;
    union 
    {
        int x;
        float y;
    }; //No name here
    
};

int main()
{
    struct data d;

    d.x=23;
    d.y=24;

    return 0;
}
