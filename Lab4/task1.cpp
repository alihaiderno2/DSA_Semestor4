#include <iostream>
using namespace std;
bool findKthLargest(const int *arr, int n, int k, int &val)
{
    if (k < 1 || k > n)
    {
        return false;
    }
    int largest = INT_MIN;
    int largest_value = INT_MAX;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        largest = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > largest && arr[j] < largest_value)
            {
                largest = arr[j];
            }
        }
        cout << largest << endl;
        largest_value = largest;
    }
    val = largest_value;
    return true;
}
int main()
{
    int arr[10] = {1, 2, 3, 5, 5, 6, 7, 8, 90, 10};
    int ans;
    findKthLargest(arr, 10, 4, ans);
    cout << ans;
}
