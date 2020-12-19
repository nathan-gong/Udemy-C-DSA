#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int &r = a; // reference only in cpp
    int b = 15;
    a += 1; 
    cout << a << endl << r << endl;
    r = b;
    cout << a << endl << r << endl;
}