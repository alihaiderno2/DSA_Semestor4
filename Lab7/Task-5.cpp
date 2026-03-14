/*Ali Haider
Bitf24m004
Morning*/
#include <iostream>
using namespace std;
int findLargestIndex(int *arr, int start, int end);
int main()
{
    // Sample input 1
    int arr[4] = {1, 2, 1, 3};
    cout << "The largest index is " << findLargestIndex(arr, 0, 3) << endl;
    int arr2[3] = {50, 10, 20};
    cout << "The largest index is " << findLargestIndex(arr2, 0, 2) << endl;
    int arr3[3] = {5, 100, 2};
    cout << "The largest index is " << findLargestIndex(arr3, 0, 2) << endl;
}
int findLargestIndex(int *arr, int start, int end)
{
    if (start == end)
    {
        return end;
    }
    int largest = findLargestIndex(arr, start + 1, end);
    if (arr[start] > arr[largest])
    {
        return start;
    }
    else
    {
        return largest;
    }
}