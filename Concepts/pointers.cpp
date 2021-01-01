#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    // Access int in stack
    int a = 10;
    int *p;
    p = &a;

    cout << a << endl;
    printf("%d", *p); // dereference

    cout << &a << endl;
    printf("Pointer address: %d", p);

    // Access array in stack
    int B[5] = {0, 2, 4, 6, 8};
    int *q;
    q = B; // q = &B[0]

    // Access array in heap
    int *r;
    r = (int *)malloc(5 * sizeof(int)); // cpp: new int[5]
    r[0] = 5;
    r[1] = 10;
    r[2] = 15;
    r[3] = 20;
    r[4] = 25;

    for (int i = 0; i < 5; i++)
    {
        cout << r[i] << endl;
    }

    // release memory once finished using
    free(r); // cpp: delete[] r
}