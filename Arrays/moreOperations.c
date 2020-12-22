#include <stdio.h>
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

// find single missing element in unordered array starting at 1
int missing(struct Array arr)
{
    int sum = 0;
    int n = arr.length;
    for (int i = 0; i < n; i++)
    {
        sum += arr.A[i];
    }
    return (n * (n + 1) / 2) - sum;
}

// find single missing element in ordered array from l to h
int missing2(struct Array arr, int l, int h)
{
    int n = arr.length;
    for (int i = 0; i < n; i++)
    {
        if (arr.A[i] - i != l)
        {
            return i + l;
        }
    }
    return 0;
}

// find multiple missing elements in ordered array from l to h
void multMissing(struct Array arr, int l, int h)
{
    int n = arr.length;

    for (int i = 0; i < n; i++)
    {
        if (arr.A[i] - i != l)
        {
            while (l < arr.A[i] - i)
            {
                printf("%d ", i + l);
                l++;
            }
        }
    }
}

// find multiple missing elements in ordered array from l to h using hashing
void multMissing2(struct Array arr, int l, int h)
{
    int n = arr.length;
    // initialize hash table
    struct Array *ht = (struct Array *)malloc(h * sizeof(struct Array));
    for (int i = 0; i < h; i++)
    {
        ht->A[i] = 0;
    }
    // increment
    for (int i = 0; i < n; i++)
    {
        ht->A[arr.A[i]]++;
    }
    // print missing elements
    for (int i = l; i <= h; i++)
    {
        if (ht->A[i] == 0)
        {
            printf("%d ", i);
        }
    }
}

// find duplicate elements in ordered array
void duplicate(struct Array arr)
{
    int n = arr.length;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr.A[i] == arr.A[i + 1])
        {
            int j = i + 1;
            while (arr.A[j] == arr.A[i])
            {
                j++;
                printf("%d has %d duplicates\n", arr.A[i], j - i);
                i = j - 1;
            }
        }
    }
}

// find duplicate elements in ordered array from 0 to h using hashing
void duplicate2(struct Array arr, int h)
{
    int n = arr.length;
    // initialize hash table
    struct Array *ht = (struct Array *)malloc(h * sizeof(struct Array));
    for (int i = 0; i < h; i++)
    {
        ht->A[i] = 0;
    }
    // increment
    for (int i = 0; i < n; i++)
    {
        ht->A[arr.A[i]]++;
    }
    // print duplicate elements
    for (int i = 0; i < h; i++)
    {
        if (ht->A[i] > 1)
        {
            printf("%d ", ht->A[i]);
        }
    }
}

// find duplicate elements in unordered array
void duplicate3(struct Array arr)
{
    int n = arr.length;

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        if (arr.A[i] != -1)
        {
            for (int j = i + 1; i < n; j++)
            {
                if (arr.A[i] = arr.A[j])
                {
                    count++;
                    arr.A[j] = -1;
                }
            }
            if (count > 1)
            {
                printf("%d has %d duplicates\n", arr.A[i], count);
            }
        }
    }
}

// find pair of elements with given sum
void pairSum(struct Array arr, int sum)
{
    int n = arr.length;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr.A[i] + arr.A[j] == sum)
            {
                printf("%d and %d\n", arr.A[i], arr.A[j]);
            }
        }
    }
}

// find pair of elements from 0 to h with given sum using hashing
void pairSum2(struct Array arr, int h, int sum)
{
    int n = arr.length;
    int diff = sum - arr.A[0];
    // initialize hash table
    struct Array *ht = (struct Array *)malloc(h * sizeof(struct Array));
    for (int i = 0; i < h; i++)
    {
        ht->A[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (ht->A[diff - arr.A[i]] != 0)
        {
            printf("%d and %d\n", arr.A[i], diff - arr.A[i]);
        }
        ht->A[arr.A[i]]++;
    }
}

// find pair of elements with given sum in ordered array
void pairSum3(struct Array arr, int sum)
{
    int n = arr.length;

    for (int i = 0, j = n - 1; i < j;)
    {
        if (arr.A[i] + arr.A[j] == sum)
        {
            printf("%d and %d\n", arr.A[i], arr.A[j]);
            i++;
            j++;
        }
        else if (arr.A[i] + arr.A[j] < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

// find max and min elements
void maxMin(struct Array arr) {
    int n = arr.length;
    int max = arr.A[0];
    int min = arr.A[0];

    for(int i = 0; i < n; i++) {
        if(arr.A[i] < min) {
            min = arr.A[i];
        }
        else if(arr.A[i] > max) {
            max = arr.A[i];
        }
    }
    printf("Max: %d", max);
    printf("Min: %d", min);
}

int main()
{
    struct Array arr = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};
    display(arr);
    
    return 0;
}