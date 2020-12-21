#include <stdio.h>
#include <stdlib.h>

// Increase size of array: create new array and shift pointer

int main()
{
    int *p; // old
    int *q; // new

    p = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        p[i] = 9;
    }

    q = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        q[i] = p[i];
    }

    free(p);
    p = q;
    q = NULL;

    for (int i = 5; i < 10; i++)
    {
        p[i] = 13;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", p[i]);
    }
}