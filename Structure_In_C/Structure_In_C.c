#include <stdio.h>

struct Books
{
    char Title[50];
    char Author[50];
    int price;

};

int main()
{
   struct Books B1={"The Lord of the Mysteries", "Cattlefish", 560}; 
   struct Books B2={"Happy ENding","Nsme", 450};
   struct Books B3={"heelo","fellow",45};

   printf("        Books One      \n");
   printf("Title= %s\n", B1.Title);
   printf("Author= %s\n", B1.Author);
   printf("Price= %d\n", B1.price);

    printf("        Books Two      \n");
   printf("Title= %s\n", B2.Title);
   printf("Author= %s\n", B2.Author);
   printf("Price= %d\n", B3.price);

   printf("        Books There      \n");    
   printf("Title= %s\n", B3.Title);
   printf("Author= %s\n", B3.Author);
   printf("Price= %d\n", B3.price);


    return 0;

   
}

