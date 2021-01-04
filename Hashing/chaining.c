#include <stdio.h>
#include "chain.h"

int hash(int key)
{
    return key % 10;
}

void insert(struct Node *H[], int key)
{
    int index = hash(key);
    sortedInsert(&H[index], key);
}

int main()
{
    struct Node *HT[10];
    struct Node *temp;

    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }

    insert(HT, 12);
    insert(HT, 22);
    insert(HT, 42);

    int key = 22;

    temp = search(HT[hash(key)], key);

    printf("%d ", temp->data);

    return 0;
}