#include <stdio.h>

int z=1;

void storage_class()
{
    //Auto Storage Class
    auto int w=1;

    //Static Storage Class
    static int x=0;
    x++;

    //Register Storage Class
    register int y=1;

    //Extern Storage Class
    extern int z;


    printf("Auto_Variable=%d\n",w);
    printf("Static_Variable=%d\n",x);
    printf("Register_Variable=%d\n",y);
    printf("Extern_Variable=%d\n",z);

    // To see the effect of each Storage class
    w+=1;
    x+=1;
    y+=1;
    z+=1;
}

int main()
{
    printf("       First Call      \n");
    storage_class();

    printf("       Second Call       \n");
    storage_class();
    
    return 0;
}