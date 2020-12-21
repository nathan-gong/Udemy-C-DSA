#include <iostream>

using namespace std;

class Array
{

private:
    int *A;
    int size;
    int length;

public:
    Array(int size)
    {
        this->size = size;
        this->A = new int[size];
    }

    void create()
    {
        cout << "Enter number of elements: " << flush;
        cin >> length;
        cout << "Enter the array elements: " << endl;

        for (int i = 0; i < length; i++)
        {
            cout << "Array element: " << i << " = " << flush;
            cin >> this->A[i];
        }
    }

    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << this->A[i] << " ";
        }
        printf("\n");
    }

    void append(int x)
    {
        if (this->length < this->size)
        {
            this->A[this->length++] = x;
        }
    }

    void insert(int x, int index)
    {
        if (index >= 0 && index <= this->length)
        {
            for (int i = this->length; i > index; i--)
            {
                this->A[i] = this->A[i - 1];
            }
            this->A[index] = x;
            this->length++;
        }
    }

    void deleteIndex(int index)
    {
        int x = 0;

        if (index >= 0 && index < this->length)
        {
            x = this->A[index];
            for (int i = index; i < this->length - 1; i++)
                this->A[i] = this->A[i + 1];
            this->length--;
        }
    }

    ~Array()
    {
        delete[] this->A;
        cout << "Array destroyed" << endl;
    }
};

int main()
{

    Array arr(10);
    arr.create();
    arr.append(9);
    arr.insert(9, 5);
    arr.deleteIndex(4);

    arr.display();
    return 0;
}