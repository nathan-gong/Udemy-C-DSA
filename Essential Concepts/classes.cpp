#include <iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int width;

public:
    Rectangle()
    {
        this->length = 1;
        this->width = 1;
    }

    Rectangle(int l, int w)
    {
        this->length = l;
        this->width = w;
    }

    int area()
    {
        return this->length * this->width;
    }

    int perimeter()
    {
        return 2 * (this->length + this->width);
    }

    int getLength()
    {
        return this->length;
    }

    int getWidth();

    void setLength(int l)
    {
        this->length = l;
    }

    void setWidth(int w)
    {
        this->width = w;
    }

    ~Rectangle() {} // destructor
};

// defining function outside of class
int Rectangle::getWidth()
{
    return this->width;
}

// template class

template <class T>
class Arith
{
private:
    T a;
    T b;

public:
    Arith(T a, T b);
    T add();
};

template <class T>
Arith<T>::Arith(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arith<T>::add()
{
    return this->a + this->b;
}

int main()
{
    Rectangle r(10, 5);
    cout << r.area() << endl;
    r.setLength(15);
    cout << r.getLength() << endl;

    Arith<float> ar(10.0, 6.0);
    cout << ar.add() << endl;

    return 0;
}