/*
Using MinGW compiler, VSCode, Windows:
Add .\bin to PATH environment var
Run Build Task -> C/C++: gcc.exe build active file
*/

#include <stdio.h>

// Head recursion
void head(int n)
{
    if (n > 0)
    {
        head(n - 1);
        printf("%d ", n);
    }
}

// Tail recursion
void tail(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        tail(n - 1);
    }
}

int main() {
    int x = 3;

    printf("Head:\n");
    head(x); // 1 2 3
    printf("\nTail:\n");
    tail(x); // 3 2 1

    return 0;
}