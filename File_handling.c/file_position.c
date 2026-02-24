#include <stdio.h>

int main()
{
    FILE *fp;
    FILE *rb;
    char ch;
    long position;

    

    rb=fopen("demo.txt","w");

    fprintf(rb,"HELLO WORLD");

    fclose(rb);

    fp=fopen("demo.txt","r");

    

    if(!fp)
    {
        printf("File Not Opened");
        return 0;
    }
    


    //ftell() returns Number of Bytes, not number of words.
    position=ftell(fp);
    printf("Initial position: %ld\n",position);

    //Read one character
    ch=fgetc(fp);
    printf("Read Character: %c\n",ch);

    position=ftell(fp);
    printf("Position After Reading One Character: %ld\n",position);

    //Move pointer to 6th posiotn from beginning
    fseek(fp,6,SEEK_SET);
    position=ftell(fp);
    printf("Position after fseek to 6: %ld\n",position);

    position=ftell(fp);
    printf("Postion After fseek with Seek_End: %ld\n",position);

    //Reads the data from Beginning
    rewind(fp);

    position=ftell(fp);
    printf("Initial Positon: %ld\n",position);

    return 0;

}