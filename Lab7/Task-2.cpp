/*Ali Haider
Bitf24m004
Morning*/
#include <iostream>
using namespace std;
void printZigZag(int *, int, int);
void printZigZagUpdated(int *pStart, int *pEnd);
int main()
{
    // Sample input 1
    int arr[5] = {3, 6, 2, 1, 4};
    printZigZag(arr, 0, 4);
    printZigZagUpdated(arr, arr + 4);
    cout<<endl;
    // Sample input 2
    int arr2[6] = {7, 1, 9, 3, 5, 2};
    printZigZag(arr2, 0, 5);
    printZigZagUpdated(arr2, arr2 + 5);
    cout<<endl;

    // Sample input 3
    int arr3[4] = {-1, 3, -2, 5};
    printZigZag(arr3, 0, 3);
    printZigZagUpdated(arr3, arr3 + 3);
    cout<<endl;
}
void printZigZag(int *arr, int start, int end)
{
    if (start == end)
    {
        cout << arr[start] << endl;
        return;
    }
    else if (start > end)
    {
        cout << endl;
        return;
    }
    else
    {
        cout << arr[start] << " " << arr[end] << " ";
        printZigZag(arr, start + 1, end - 1);
    }
}
void printZigZagUpdated(int *pStart, int *pEnd)
{
    if (pStart == pEnd)
    {
        cout << *pStart << endl;
    }
    else if (pStart > pEnd)
    {
        cout << endl;
    }
    else
    {
        cout << *pStart << " " << *pEnd << " ";
        printZigZagUpdated(pStart + 1, pEnd - 1);
    }
}