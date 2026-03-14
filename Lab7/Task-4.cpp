/*Ali Haider
Bitf24m004
Morning*/
#include <iostream>
using namespace std;
void printChar(char ch, int n);
void printPattern1(char ch, int n);
void printPattern2(char ch, int n);
int main()
{
    // Sample input 1
    cout << "Sample input 1" << endl;
    printPattern1('Z', 5);
    // Sample input 2
    cout << "Sample input 2" << endl;
    printPattern2('#', 6);
    // Sample input 3
    cout << "Sample input 3" << endl;
    printPattern2('@', 5);
}
void printChar(char ch, int n)
{
    if (n == 0)
    {
        return;
    }
    cout << ch;
    printChar(ch, n - 1);
}
void printPattern1(char ch, int n)
{
    if (n == 0)
    {
        return;
    }
    printChar(ch, n);
    cout << endl;
    printPattern1(ch, n - 1);
}
void printPattern2(char ch, int n)
{
    if (n == 0)
    {
        return;
    }
    printPattern2(ch, n - 1);
    printChar(ch, n);
    cout << endl;
}