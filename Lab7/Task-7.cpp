/*Ali Haider
Bitf24m004
Morning*/
#include <iostream>
using namespace std;
bool areArraysEqual(int *a, int aSize, int *b, int bSize);
int main()
{
    int a1[4] = {1, 2, 3, 4};
    int b1[4] = {1, 2, 3, 4};
    if (areArraysEqual(a1, 4, b1, 4))
    {
        cout << "Arrays are equal" << endl;
    }
    else
    {
        cout << "Arrays are not equal" << endl;
    }

    int a2[4] = {1, 2, 3, 4};
    int b2[4] = {1, 2, 3, 5};
    if (areArraysEqual(a2, 4, b2, 4))
    {
        cout << "Arrays are equal" << endl;
    }
    else
    {
        cout << "Arrays are not equal" << endl;
    }

    int a3[3] = {1, 2, 3};
    int b3[4] = {1, 2, 3, 4};
    if (areArraysEqual(a3, 3, b3, 4))
    {
        cout << "Arrays are equal" << endl;
    }
    else
    {
        cout << "Arrays are not equal" << endl;
    }
}
bool areArraysEqual(int *a, int aSize, int *b, int bSize)
{
    if (aSize != bSize)
    {
        return false;
    }
    else if (aSize == 0 && bSize == 0)
    {
        return true;
    }
    else if (a[aSize - 1] != b[bSize - 1])
    {
        return false;
    }
    else
    {
        return areArraysEqual(a, aSize - 1, b, bSize - 1);
    }
}