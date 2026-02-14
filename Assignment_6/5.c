#include <stdio.h>

int main()
{
    int Matrix_1[2][2];
    int Matrix_2[2][2];
    int Matrix_3[2][2];

    int *ptr_1=&Matrix_1[0][0];
    int *ptr_2=&Matrix_2[0][0];
    int *ptr_3=&Matrix_3[0][0];

    int i,j;

    printf("Values For Matrix 1\n");

    for (i=0; i<2; i++)
    {
        printf("Values in Row %d: ",i + 1);
        for(j=0; j<2; j++)
        {
            scanf("%d",&Matrix_1[i][j]);
        }
    }

    printf("\nValues For Matrix 2\n");

    for (i=0; i<2; i++)
    {
        printf("Values in Row %d: ",i + 1);
        for(j=0; j<2; j++)
        {
            scanf("%d",&Matrix_2[i][j]);
        }
    }

    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            *(ptr_3+i*2+j)=*(ptr_1+i*2+j)+*(ptr_2+i*2+j);
        }
    }

    printf("Resultant Matrix\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("%d ",*(ptr_3+i*2+j));
        }
        printf("\n");
    }
    return 0;

}