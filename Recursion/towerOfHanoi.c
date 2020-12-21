#include <stdio.h>

// Tower of Hanoi problem

// n disks, tower A, tower B, tower C
// produces the sequence of steps needed to move n disks from A to C
void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("%d to %d\n", A, C);
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    TOH(4, 1, 2, 3);
    return 0;
}