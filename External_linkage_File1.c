#include <stdio.h>
int myvar;

void myfunc()
{
    printf("Value is %d",myvar);
}


// we have to Execuate both files at the same time so 

// gcc External_linkage_File1.c External_linkage_File2.c -o newfile_name
// ./newfile_name