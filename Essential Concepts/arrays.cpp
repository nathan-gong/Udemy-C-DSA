#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cout << ("Enter size:");
    cin >> n;
    // int A[n]; error: can't initialize variable-size array
    int A[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    for (int i : A)
    {
        printf("%d\n", A[i]);
    }
}