#include <stdio.h>

int main( int argc, char *argv[])
{
    printf("Number of arguments (argc): %d\n\n", argc);

    printf("Arguments received:\n");

    for (int i=0; i<argc; i++)
    {
        printf("argv[%d]=%s\n",i,argv[i]);
    }
    return 0;
}


// Run in terminal 
// gcc Commandline_arguments.c -o newfilename
// ./newfilename