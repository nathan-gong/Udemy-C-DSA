#include <stdio.h>

// Taylor Series e^x

double e1(int x, int n)
{

    static double p = 1, f = 1;
    double r;

    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = e1(x, n - 1);
        p *= x;
        f *= n;
        return r + p / f;
    }
}

// Using Horner's Rule
double e2(int x, int n)
{
    static double s;
    if (n == 0)
    {
        return s;
    }
    else
    {
        s = 1 + x * s / n;
        return e2(x, n - 1);
    }
}

// Iterative
double e3(int x, int n)
{
    double s = 1;
    int i;
    double num = 1;
    double den = 1;

    for (i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main()
{
    printf("%lf\n", e1(4, 15));
    printf("%lf\n", e2(4, 15));
    printf("%lf\n", e3(4, 15));


    return 0;
}