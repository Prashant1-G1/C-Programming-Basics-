#include <stdio.h>

int main()
{
    int row, column;

    int i, j,k;

    printf("Enter the Row and Column of Matrix(3x3): ");
    scanf("%d %d",&row, &column);

    while (row!=3 || column !=3)
    {
        printf("This code is only for 3x3 matrix multiplication!\n");
        printf("Enter the Row and Column of Matrix(3x3): ");
        scanf("%d %d",&row, &column);
    }

    int matrix_A[row][column];
    int matrix_B[row][column];
    int matrix_C[row][column];

    printf("Enter the Values for Matrix A:\n");
    for (i=0; i<row; i++)
    {
        printf("Value for %d Row: ",i+1);
        for (j=0; j<column; j++)
        {
            scanf("%d",&matrix_A[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the Values for Matrix B:\n");
    for (i=0; i<row; i++)
    {
        printf("Value for %d Row: ",i+1);
        for (j=0; j<column; j++)
        {
            scanf("%d",&matrix_B[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<row; i++)
    {
        

        for (j=0; j<column; j++)
        {
            int result=0;
            int sum=0;
            for (k=0; k<column; k++)
            {
                result=matrix_A[i][k]*matrix_B[k][j];
                sum+=result;
            }
            matrix_C[i][j]=sum;
        }
        
    }
    printf("\n Multiplied Matrix\n");
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            printf("%d ",matrix_C[i][j]);
        }
        printf("\n");

    }

    return 0;

}