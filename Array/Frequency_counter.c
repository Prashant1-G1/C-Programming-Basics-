#include <stdio.h>

int main()
{
    int arr[10]={1,2,3,1,2,3,3,4,5,1};
    int count, j;

    for (int i=0; i<10; i++)
    {
        if (arr[i]==-1)
            continue;

        count=1;

        for ( j=i+1; j<10; j++)
        {
          if (arr[i]==arr[j])
          {
            count++;
            arr[j]=-1;  
          }
        }
            

        printf("%d is repeated %d Times\n", arr[i], count);
    }
    

    return 0;
}
