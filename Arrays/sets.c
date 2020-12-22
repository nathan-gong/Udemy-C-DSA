#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
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

// set union
struct Array *setUnion(struct Array *arr1, struct Array *arr2)
{
    int i = 0, j = 0, k = 0;
    int size = arr1->length + arr2->length;

    struct Array *arr3 = (struct Array *)malloc(size * sizeof(struct
                                                              Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = size;

    return arr3;
}

// set intersection
struct Array *setIntersection(struct Array *arr1, struct Array
                                                      *arr2)
{
    int i = 0, j = 0, k = 0;
    int size = arr1->length + arr2->length;

    struct Array *arr3 = (struct Array *)malloc(size * sizeof(struct
                                                              Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else if (arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = size;

    return arr3;
}

struct Array *setDifference(struct Array *arr1, struct Array
                                                    *arr2)
{
    int i = 0, j = 0, k = 0;
    int size = arr1->length + arr2->length;

    struct Array *arr3 = (struct Array *)malloc(size * sizeof(struct
                                                              Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = size;

    return arr3;
}

int main()
{
    /* DEMONSTRATION OF SET OPERATIONS
    struct Array arr1 = {{2, 9, 21, 28, 35}, 10, 5};
    struct Array arr2 = {{2, 3, 9, 18, 28}, 10, 5};
    printf("Array 1: ");
    display(arr1);
    printf("Array 2: ");
    display(arr2);

    struct Array *arr3;
    arr3 = setUnion(&arr1, &arr2);
    printf("Union: ");
    display(*arr3);

    struct Array *arr4;
    arr4 = setIntersection(&arr1, &arr2);
    printf("Intersection: ");
    display(*arr4);

    struct Array *arr5;
    arr5 = setDifference(&arr1, &arr2);
    printf("Difference: ");
    display(*arr5);

    return 0

    */

    struct Array arr1;
    int ch;
    int x, index;

    printf("Enter Size of Array");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;

    do
    {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6.Exit\n");

        printf("Enter Selection:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter an element and index");
            scanf("%d%d", &x, &index);
            insert(&arr1, index, x);
            break;
        case 2:
            printf("Enter index ");
            scanf("%d", &index);
            x = delete (&arr1, index);
            printf("Deleted Element is %d\n", x);
            break;
        case 3:
            printf("Enter element to search ");
            scanf("%d", &x);
            index = linSearch(&arr1, x);
            printf("Element index %d", index);
            break;
        case 4:
            printf("Sum is %d\n", Sum(arr1));
            break;
        case 5:
            display(arr1);
            break;
        }
    } while (ch < 6);

    return 0;
}