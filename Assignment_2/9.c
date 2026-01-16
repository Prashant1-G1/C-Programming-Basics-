#include <stdio.h>

int main()
{
    float side,Lenght,Breadth;
    float Area_Square, Area_Rectangle;
    printf("Enter the side of the Square: ");
    scanf("%f",&side);

    Area_Square=side*side;

    printf("Area of Square: %.2f unit Square\n",Area_Square);

    printf("Enter the Lenght of the Rectangle: ");
    scanf("%f",&Lenght);
    printf("Enter the Breadth of the Rectangle: ");
    scanf("%f",&Breadth);

    Area_Rectangle=Lenght*Breadth;

    printf("Area of the Rectangle: %.2f unit Square\n",Area_Rectangle);
    return 0;
}