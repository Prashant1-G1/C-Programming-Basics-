#include <stdio.h>

//stucture Creation 
struct Students
{
    char Name[20];
    int Roll;
    int Age;
    int Marks;
};

int main()
{
    //Structure Declaration and initialization  
    struct Students Students_1={"Prashant Bhattarai",1,19,100};

    printf("Name: %s\n",Students_1.Name);
    printf("Roll Number: %d\n",Students_1.Roll);
    printf("Age: %d\n",Students_1.Age);
    printf("Marks: %d\n",Students_1.Marks);

    return 0;

}



