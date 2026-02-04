#include <stdio.h>

typedef struct
{
    char car_name[50];
    int car_model;
    int price;
}Car;

int main()
{
    Car cars[]={{"Honda",2025,190000},{"Lamboghini",2025,10000000},{"Mcleren",2024,1500000}};

    int numbers=sizeof(cars) / sizeof(cars[0]);

    for (int i=0; i<numbers; i++)
    {
        printf("%s %d $%d\n",cars[i].car_name, cars[i].car_model, cars[i].price);
    }

    return 0;
}