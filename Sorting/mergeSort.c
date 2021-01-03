#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];
    for (i = l; i <= h; i++)
        A[i] = B[i];
}

// iterative
void IMergeSort(int A[], int n)
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
        if (n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, n - 1);
        }
    }
    if (p / 2 < n)
    {
        merge(A, 0, p / 2 - 1, n - 1);
    }
}

// recursive
void RMergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        RMergeSort(A, l, mid);
        RMergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

int main()
{
    int A[] = {11, 5, 14, 2, 6, 3, 1};
    int B[] = {11, 5, 14, 2, 6, 3, 1};
    int n = 7;

    IMergeSort(A, n);
    RMergeSort(B, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", B[i]);
    printf("\n");

    return 0;
}