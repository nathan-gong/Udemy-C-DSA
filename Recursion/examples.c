#include <stdio.h>

// Sum of n natural numbers

// Using formula: O(1)
int sum1(int n)
{
    return n * (n + 1) / 2;
}

// Using loop: O(n)
int sum2(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

// Using recursion: O(n)
int sum3(int n)
{
    return n == 0 ? 0 : sum3(n - 1) + n;
}

// Factorial

// Using loop: O(n)
int fact1(int n)
{
    int product = 1;
    for (int i = 1; i <= n; i++)
    {
        product *= i;
    }
    return product;
}

// Using recursion: O(n)
int fact2(int n)
{
    return n == 1 ? 1 : fact2(n - 1) * n;
}

// Power

// Using loop:
int power1(int m, int n)
{
    int product = 1;
    while (n > 0)
    {
        product *= m;
        n--;
    }
    return product;
}

// Using recursion:
int power2(int m, int n)
{
    return n == 0 ? 1 : power2(m, n - 1) * m;
}

// Using faster recursion:
int power3(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n % 2 == 0 ? 2 : m * power3(m * m, (n - 1) / 2);
}

// Combinatorics nCr

int comb1(int n, int r)
{
    return fact1(n) / (fact1(r) * fact1(n - 2));
}

int comb2(int n, int r)
{
    return n == r || r == 0 ? 1 : comb2(n - 1, r - 1) + comb2(n - 1, r);
}

int main()
{
    printf("%d, %d, %d\n", sum1(5), sum2(5), sum3(5));                // 15
    printf("%d, %d\n", fact1(5), fact2(5));                           // 120
    printf("%d, %d, %d\n", power1(2, 3), power2(2, 3), power3(2, 3)); // 8
    printf("%d, %d\n", comb1(6, 2), comb2(6, 2));                     // 15

    return 0;
}