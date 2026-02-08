#include <stdio.h>
int main()
{
    FILE *fp=NULL;

    fp=fopen("Test.txt","a");

    fprintf(fp, "\nIts me prashant");

    if(fp=NULL)
    {
        printf("Error While opening while.");
    }
    else
    {
        printf("File opened Sucessfully");
        fclose(fp);
    }

    return 0;
}