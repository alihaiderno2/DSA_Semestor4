/*Ali Haider
Bitf24m004
Morning*/
#include <iostream>
using namespace std;
void printVertical(int);
int main()
{
    // Sample input 1
    printVertical(357);
    // Sample input 2
    printVertical(-223);
    // Sample input 3
    printVertical(2);
}
void printVertical(int val)
{
    if (val == 0)
    {
        return;
    }
    else if (val < 0)
    {
        printVertical(-val);
    }
    else
    {
        printVertical(val / 10);
        cout << val % 10 << endl;
    }
}