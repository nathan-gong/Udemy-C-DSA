#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertion(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = 10;

    insertion(A, n);

    for (int i = 0; i < 10; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}