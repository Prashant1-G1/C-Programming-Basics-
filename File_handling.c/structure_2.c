#include <stdio.h>
struct Students
{
    int roll;
    char Name[20];
    int Age;
};

int main()
{
    int n;
    struct Students s;

    FILE *fp=fopen("Student.dat","ab+");

    printf("Number of Students: ");
    scanf("%d",&n);

   for(int i=0; i<n; i++)
   {
    printf("Enter the Roll, Name and Age for Student %d: ",i+1);
    scanf("%d %s %d",&s.roll,&s.Name, &s.Age);
    fwrite(&s, sizeof(s), 1, fp);
   }
   fclose(fp);


    fp=fopen("Student.dat","rb");

    while (fread(&s, sizeof(s), 1, fp)) 
    {
        printf("Roll: %d, Name: %s, Age: %d\n", 
               s.roll, s.Name, s.Age);
    }
    
    fclose(fp);

   return 0;


}