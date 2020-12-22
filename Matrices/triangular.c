#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

// Lower triangular matrices
void lowerSet(struct Matrix *m, int i, int j, int x);
int lowerGet(struct Matrix m, int i, int j);
void lowerDisplay(struct Matrix m);

// Upper triangular matrices
void upperSet(struct Matrix *m, int i, int j, int x);
int upperGet(struct Matrix m, int i, int j);

// Symmetric matrices can be represented by either upper or lower matrices

void lowerSet(struct Matrix *m, int i, int j, int x)
{
    if (i >= j)
        m->A[m->n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j] = x;
}

int lowerGet(struct Matrix m, int i, int j)
{
    if (i >= j)
        return m.A[m.n * (j - 1) + (j - 2) * (j - 1) / 2 + i - j];
    else
        return 0;
}

void lowerDisplay(struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[m.n * (j - 1) +
                                  (j - 2) * (j - 1) / 2 + i - j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    printf("\n");
}

void upperSet(struct Matrix *m, int i, int j, int x)
{
    if (i <= j)
        m->A[m->n * (i - 1) + (i - 2) * (i - 1) / 2 + j - i] = x;
}

int upperGet(struct Matrix m, int i, int j)
{
    if (i <= j)
        return m.A[m.n * (i - 1) + (i - 2) * (i - 1) / 2 + j - i];
    else
        return 0;
}

void upperDisplay(struct Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i <= j)
                printf("%d ", m.A[m.n * (i - 1) +
                                  (i - 2) * (i - 1) / 2 + j - i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    struct Matrix m;
    char c = 'l';

    printf("Enter Dimension and L/U: ");
    scanf("%d %c", &m.n, &c);
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    if (c == 'L' || c == 'l')
    {
        printf("Enter all elements: ");
        for (int i = 1; i <= m.n; i++)
        {
            for (int j = 1; j <= m.n; j++)
            {
                int x;
                scanf("%d", &x);
                lowerSet(&m, i, j, x);
            }
        }
        printf("\n");
        lowerDisplay(m);
    }
    else if (c == 'U' || c == 'u')
    {
        printf("Enter all elements: ");
        for (int i = 1; i <= m.n; i++)
        {
            for (int j = 1; j <= m.n; j++)
            {
                int x;
                scanf("%d", &x);
                upperSet(&m, i, j, x);
            }
        }
        printf("\n");
        upperDisplay(m);
    }
    else
    {
        printf("Invalid input. That's rough buddy.");
    }

    return 0;
}