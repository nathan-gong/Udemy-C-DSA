#include <iostream>
#include <stdio.h>

using namespace std;

struct Rect
{
    int length;
    int width;
    char x;
} r1;

int main()
{
    r1 = {10, 5, 'x'};
    r1.length = 15;

    // memory padding: returns 12, not 9
    printf("%d", sizeof(r1));

    return 0;
}