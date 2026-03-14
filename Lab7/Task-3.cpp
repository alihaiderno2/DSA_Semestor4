/*Ali Haider
Bitf24m004
Morning*/
#include <iostream>
using namespace std;
int linearSearchUpdated(int *arr, int start, int end, int key);
int main()
{
    // Sample input 1
    int arr[4] = {1, 2, 1, 3};
    cout << "THe count of 1's is " << linearSearchUpdated(arr, 0, 3, 1) << endl;
    // Sample input 2
    int arr2[6] = {1, 2, 1, 3, 1, 1};
    cout << "THe count of 1's is " << linearSearchUpdated(arr2, 0, 5, 1) << endl;
    // Sample input 3
    int arr3[4] = {7, 7, 7, 7};
    cout << "THe count of 7's is " << linearSearchUpdated(arr3, 0, 3, 7) << endl;
}
int linearSearchUpdated(int *arr, int start, int end, int key)
{
    if (start > end)
    {
        return 0;
    }
    else if (arr[start] == key)
    {
        return 1 + linearSearchUpdated(arr, start + 1, end, key);
    }
    else
    {
        return linearSearchUpdated(arr, start + 1, end, key);
    }
}