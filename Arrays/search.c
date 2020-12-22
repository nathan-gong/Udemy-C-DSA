#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Linear search
int linSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]); // transposition
            return i;
        }
    }
    return -1;
}

// Binary search - iterative
int binSearch(struct Array *arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr->length - 1;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr->A[mid])
            return mid;
        else if (key < arr->A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// Binary search - recursive
int rbinSearch(int a[], int l, int h, int key)
{
    int mid = (l + h) / 2;
    if (l <= h)
    {
        if (key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            return rbinSearch(a, l, mid - 1, key);
        }
    }
    else
    {
        return rbinSearch(a, mid + 1, h, key);
    }
    return -1;
}

int main()
{
    struct Array a1 = {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 10, 9};
    display(a1);
    int key = 6;
    printf("Linear Search:\n");
    printf("Index of %d: %d\n\n", key, linSearch(&a1, key));
    key = 4;
    display(a1);
    printf("Iterative Binary Search:\n");
    printf("Index of %d: %d\n\n", key, binSearch(&a1, key));
    key = 5;
    display(a1);
    printf("Recursive Binary Search:\n");
    printf("Index of %d: %d\n", key, rbinSearch(a1.A, 0, a1.length, key));

    return 0;
}