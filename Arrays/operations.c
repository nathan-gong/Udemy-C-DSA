#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

// check if given index is valid for given array
bool valid(struct Array *arr, int index)
{
    return index >= 0 && index < arr->length;
}

// return element at given index
int get(struct Array *arr, int index)
{
    return valid(arr, index) ? arr->A[index] : -1;
}

// set value of element at given index
void set(struct Array *arr, int index, int val)
{
    if (valid(arr, index))
    {
        arr->A[index] = val;
    }
}

// return maximum element
int maximum(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}

// return minimum element
int minimum(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}

// return sum of all elements
int sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

// return average of all elements
double avg(struct Array arr)
{
    return 1.0 * sum(arr) / arr.length;
}

// reverse elements
void reverse(struct Array *arr)
{
    int *arr2 = (int *)malloc(arr->length * sizeof(int));
    // assign values to new array
    for (int i = arr->length - 1, j = 0; i >= 0; i--, j--)
    {
        arr2[j] = arr->A[i];
    }
    // shift pointer
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr2[i];
    }
}

void reverse2(struct Array *arr)
{
    // swap addresses
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

// check if list is sorted in increasing order
bool isSorted(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }
    return true;
}

// merge two arrays
struct Array *merge(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct
                                                       Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }

    for (; j < arr2->length; j++)
    {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct Array arr = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};
    display(arr);
}