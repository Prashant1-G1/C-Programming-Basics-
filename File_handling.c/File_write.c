#include <stdio.h>
int main()
{
    FILE *fp=NULL;

    fp=fopen("Test.txt","w");

    fprintf(fp, "hello world");

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