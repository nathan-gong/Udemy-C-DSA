#include <stdio.h>

// Tree recursion
void tree(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        tree(n - 1);
        tree(n - 1);
    }
}

// Indirect recursion
void indirectHelp(int n); // need to declare before call

void indirect(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        indirectHelp(n - 1);
    }
}

void indirectHelp(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        indirect(n / 2);
    }
}

// Nested recursion
int nested(int n)
{
    return n > 100 ? n - 10 : nested(nested(n + 11));
}

int main()
{
    tree(3); // 3 2 1 1 2 1 1
    printf("\n");
    indirect(20); // 20 19 9 8 4 3 1
    printf("\n");
    printf("%d\n", nested(95)); // 91

    return 0;
}