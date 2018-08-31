#include <stdio.h>

void rotateMatrix(int matrix[4][4])
{
    int n = 4;
    if(n==0) return;
    for(int layer=0; layer<n/2; layer++)
    {
        int last = n-1-layer;
        for(int i=layer; i<last;i++)
        {
            int offset = i-layer;
            int top = matrix[layer][i];
            matrix[layer][i] = matrix[last-offset][layer];
            matrix[last-offset][layer] = matrix[last][last-offset];
            matrix[last][last-offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
}


void main()
{
    int a[4][4] = { {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}  };
     printArray(a);
     printf("-------\n");
     rotateMatrix(a);
     printArray(a);
}

void printArray(int a[4][4])
{
    for(int i=0; i<4; i++)
     {
         for(int j=0; j<4; j++)
         {
             printf("%d, ", a[i][j]);
         }
         printf("\n");
     }
}