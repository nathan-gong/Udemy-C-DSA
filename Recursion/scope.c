#include <stdio.h>

int func(int n)
{
    if (n > 0)
    {
        return func(n - 1) + n;
    }
    return 0;
}

// Static variables in recursion
int func1(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return func1(n - 1) + x;
    }
    return 0;
}

// Global variables in recursion
int y = 0;

int func2(int n)
{
    if (n > 0)
    {
        y++;
        return func2(n - 1) + y;
    }
    return 0;
}

int main()
{
    int r;

    r = func(5);
    printf("%d\n", r); // 15

    r = func1(5);
    printf("%d\n", r); // 25

    r = func2(5);
    printf("%d\n", r); // 25

    return 0;
}