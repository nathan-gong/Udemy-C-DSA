#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

int main()
{
    Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle)); // cpp: new Rectangle

    p->length = 15;
    p->width = 5;

    // confusing but for illustratory purposes only
    // can mix c and c++
    cout << p->length << endl;
    printf("%d", p->width);
}