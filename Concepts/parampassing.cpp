#include <iostream>
#include <stdio.h>

using namespace std;

struct Rect
{
    int length;
    int width;
};

// pass by value
void swap1(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

// pass by address
void swap2(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// pass by reference (cpp)
void swap3(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// arrays

int * func(int size)
{
    int *p;
    p = new int[size];

    for(int i = 0; i < size; i++) {
        p[i] = i + 1;
    }

    return p;
}

// structures

void dimension(struct Rect *r) {
    r->length = 20;
    cout << "Length: " << r->length << ", Width: " << r->width << endl;
}

struct Rect *dimension2() {
    struct Rect *r;
    r = (struct Rect *)malloc(sizeof(struct Rect));
    r->length = 9;
    r->width = 6;

    return r;
}

int main()
{
    int a = 10;
    int b = 5;

    swap1(a, b); // fail
    printf("x: %d, y: %d\n", a, b); // 10, 5

    swap2(&a, &b);
    printf("x: %d, y: %d\n", a, b); // 5, 10

    swap3(a, b);
    printf("x: %d, y: %d\n", a, b); // 10, 5

    int *q;
    int s = 5;
    q = func(s);
    
    for (int i = 0; i < s; i++) {
        cout << q[i] << endl;
    }

    struct Rect r = {10, 5};
    cout << "Length: " << r.length << ", Width: " << r.width << endl;
    dimension(&r);

    struct Rect *r1 = dimension2();
    cout << "Length: " << r1->length << ", Width: " << r1->width << endl;
}