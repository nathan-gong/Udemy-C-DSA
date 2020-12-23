#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Linked List

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL;

// create
// display
// length
// sum
// maximum
// search
// insert
// insertSorted
// removeInd
// isSorted
// removeDuplicate (must be sorted)
// reverse
// concat
// merge
// hasLoop

void create(int A[], int n)
{
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    struct Node *last = first;

    for (int i = 1; i < n; i++)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void display2(struct Node *p)
{
    if (p != NULL)
    {
        display2(p->next);
        printf("%d ", p->data);
    }
    printf("\n");
}

int length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

int length2(struct Node *p)
{
    return p == NULL ? length2(p->next) + 1 : 0;
}

int sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sum2(struct Node *p)
{
    return p == NULL ? 0 : sum2(p->next) + p->data;
}

int maximum(struct Node *p)
{
    int max = INT_MIN;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int maximum2(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return INT_MIN;
    x = maximum2(p->next);
    return x > p->data ? x : p->data;
}

struct Node *search(struct Node *p, int key)
{
    struct Node *q;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node *search2(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return search2(p->next, key);
}

void insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > length(p))
        return;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void insertSorted(struct Node *p, int x)
{
    struct Node *q = NULL;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int removeInd(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;

    if (index < 1 || index > length(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

bool isSorted(struct Node *p)
{
    int x = INT_MIN;
    while (p != NULL)
    {
        if (p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

void removeDuplicate(struct Node *p)
{
    struct Node *q = p->next;

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverse(struct Node *p)
{
    int i = 0;
    struct Node *q = p;
    int *A = (int *)malloc(sizeof(int) * length(p));

    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

void concat(struct Node *p, struct Node *q)
{
    second = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        second = last = p; // chained assignments go r->l
        p = p->next;
        second->next = NULL;
    }
    else
    {
        second = last = q;
        q = q->next;
        second->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

bool hasLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);

    return p == q;
}

int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);

    display(first);
    printf("Length %d\n", length(first));
    printf("Sum: %d\n", sum(first));
    printf("Max: %d\n", maximum(first));

    return 0;
}