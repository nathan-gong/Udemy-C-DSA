#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = 10;

    bubble(A, n);

    for (int i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}