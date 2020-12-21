#include <stdio.h>

// Find the nth term in the Fibonacci sequence

// Iterative
int fib1(int n)
{
    int t0 = 0;
    int t1 = 1;
    int s = 0;

    if (n <= 1)
    {
        return n;
    }

    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

// Recursive
int fib2(int n)
{
    return n <= 1 ? n : fib2(n - 2) + fib2(n - 1);
}

// Memorization
int F[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int fib3(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = fib3(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = fib3(n - 1);
        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    printf("%d\n", fib1(10)); // 55
    printf("%d\n", fib2(10)); // 55
    printf("%d\n", fib3(10)); // 55
}