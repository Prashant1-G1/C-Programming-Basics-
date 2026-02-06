#include <stdio.h>
int main()
{
    int row, column;
    int i, j;

    printf("Enter the Row and column for Matrix: ");
    scanf("%d %d",&row, &column);

    int matrix_A[row][column];
    int matrix_B[row][column];
    int matrix_C[row][column];

    printf("\nEnter the Value's for Matrix A\n");
    
    for (i=0; i<row; i++)
    {
        printf("Enter the value's for %d Row: ",i+1);
        for ( j = 0; j< column; j++)
        {
           scanf("%d",&matrix_A[i][j]); 
        }
    }

    printf("\nEnter the Value's for Matrix B\n");
    for (i=0; i<row; i++)
    {
        printf("Enter the value's for %d Row: ",i+1);
        for (j = 0; j< column; j++)
        {
           scanf("%d",&matrix_B[i][j]); 
        }
    }

    printf("\nResultant Matrix\n");
    for (i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            matrix_C[i][j]=matrix_A[i][j]+matrix_B[i][j];
        }
    }

    for ( i = 0; i < row; i++)
    {
        for(j=0; j<column; j++)
        {
            printf("%d ",matrix_C[i][j]);
        }
        printf("\n");
    }
    
    return 0;

}