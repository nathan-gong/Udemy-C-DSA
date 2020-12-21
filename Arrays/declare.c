#include <stdio.h>
#include <stdlib.h>

// subsequent dimensions must be given when passing 2D array as parameter in C
#define ROW 3
#define COL 4

void printArray(int arr[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void fillArray(int arr[][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = col * i + j;
        }
    }
}

int main()
{
    // 2D Array Declaration Methods:

    // Stack
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};
    printArray(A, 3, 4);
    printf("\n");
    fillArray(A, 3, 4);
    printArray(A, 3, 4);
    printf("\n");

    // Stack/Heap
    int *B[3];
    B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));

    // Heap
    int **C;
    C = (int **)malloc(3 * sizeof(int *));
    C[0] = (int *)malloc(4 * sizeof(int));
    C[1] = (int *)malloc(4 * sizeof(int));
    C[2] = (int *)malloc(4 * sizeof(int));
}