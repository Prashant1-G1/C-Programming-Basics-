#include <stdio.h>

int main() {
    int n, Smallest, largest;

    printf("Number of elements in the array: ");
    scanf("%d", &n);

    int numbers[n];

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    largest = numbers[0];
    Smallest = numbers[0];

    for (int i = 1; i < n; i++) 
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
        }
            
        if (numbers[i] < Smallest)
            
        {
            Smallest = numbers[i];
        }
    }

    printf("Largest element in the array = %d\n", largest);
    printf("Smallest element in the array = %d\n", Smallest);

    return 0;
}
