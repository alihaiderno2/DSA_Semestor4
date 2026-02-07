#include "sortedList.h"
#include <iostream>
using namespace std;
sortedList::sortedList(int s)
{
    if (s <= 0)
    {
        arr = nullptr;
        maxSize = 0;
    }
    else
    {
        arr = new int[s];
        maxSize = s;
    }
    currSize = 0;
}
sortedList::~sortedList()
{
    if (arr != nullptr)
    {
        delete[] arr;
    }
}
bool sortedList::insert(int val)
{
    if (currSize == maxSize)
    {
        return false;
    }
    else
    {
        int i = currSize - 1;
        while (i >= 0 && arr[i] > val)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = val;
        currSize++;
        return true;
    }
}
bool sortedList::isEmpty() const
{
    if (currSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool sortedList::isFull() const
{
    if (currSize == maxSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void sortedList::display() const
{
    if (currSize == 0)
    {
        return;
    }
    for (int i = 0; i < currSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool sortedList::remove2(int index, int &val)
{
    if (index < 0 || index >= currSize)
    {
        return false;
    }
    else
    {
        val = arr[index];
        for (int i = index; i < currSize - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        currSize--;
        return true;
    }
}
bool sortedList::operator==(const sortedList &rhs)
{
    if (currSize != rhs.currSize)
    {
        return false;
    }
    for (int i = 0; i < currSize; i++)
    {
        if (arr[i] != rhs.arr[i])
        {
            return false;
        }
    }
    return true;
}
int sortedList::removeAll2(int val)
{
    int total = 0;
    for (int i = 0; i < currSize; i++)
    {
        if (arr[i] == val)
        {
            total++;
            for (int j = i; j < currSize - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            currSize--;
            i--;
        }
    }
    return total;
}
int sortedList::removeAll3(int val)
{
    int total = 0;
    int *newArr = new int[maxSize];
    for (int i = 0; i < currSize; i++)
    {
        if (arr[i] == val)
        {
            total++;
        }
        else
        {
            newArr[i - total] = arr[i];
        }
    }
    currSize = currSize - total;
    delete[] arr;
    arr = newArr;
    return total;
}
bool sortedList::search(int key)
{
    int i = 0;
    while (i < currSize)
    {
        if (arr[i] == key)
        {
            return true;
        }
        i++;
    }
    return false;
}
bool sortedList::binarySearch(int key)
{
    int count = 0;
    int start = 0, end = currSize - 1; // 1
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            cout << ++count << endl;
            return true;
        }
        else if (arr[mid] < key)
        {
            cout << ++count << endl;
            start = mid + 1;
        }
        else
        {
            cout << ++count << endl;
            end = mid - 1;
        }
    }
    return false;
}
void sortedList::merge(const sortedList &list2)
{
    int newSize = maxSize + list2.maxSize;
    int *newArr = new int[newSize];
    int start1 = 0, start2 = 0, total = 0;
    while (start1 < currSize && start2 < list2.currSize)
    {
        if (arr[start1] < list2.arr[start2])
        {
            newArr[total] = arr[start1];
            start1++;
        }
        else
        {
            newArr[total] = arr[start2];
            start2++;
        }
        total++;
    }
    while (start1 < currSize)
    {
        newArr[total] = arr[start1];
        start1++;
        total++;
    }
    while (start2 < list2.currSize)
    {
        newArr[total] = list2.arr[start2];
        total++;
        start2++;
    }
    currSize = currSize + list2.currSize;
    delete[] arr;
    arr = newArr;
}
// Task1
bool sortedList::replace(int index, int newVal)
{
    if (index < 0 || index >= currSize)
    {
        return false;
    }
    arr[index] = newVal;
    int currIndex = index;
    // Basic approach
    // if (((currIndex == currSize - 1) && arr[currIndex] < arr[currIndex - 1]))
    // {
    //     while ((currIndex > 0) && arr[currIndex] < arr[currIndex - 1])
    //     {
    //         swap(arr[currIndex], arr[currIndex - 1]);
    //         currIndex--;
    //     }
    //     return true;
    // }
    // if (((currIndex == 0) && arr[currIndex] > arr[currIndex + 1]))
    // {
    //     while ((currIndex < currSize) && arr[currIndex] < arr[currIndex - 1])
    //     {
    //         swap(arr[currIndex], arr[currIndex + 1]);
    //         currIndex++;
    //     }
    //     return true;
    // }
    // while ((currIndex > 0) && (arr[currIndex] < arr[currIndex - 1] && arr[currIndex] < arr[currIndex + 1]))
    // {
    //     swap(arr[currIndex], arr[currIndex - 1]);
    //     currIndex--;
    // }
    // while ((currIndex < currSize) && (arr[currIndex] > arr[currIndex + 1] && arr[currIndex] > arr[currIndex - 1]))
    // {
    //     swap(arr[currIndex], arr[currIndex + 1]);
    //     currIndex++;
    // }
    // return true;

    //  A better approach
    while (currIndex > 0 && arr[currIndex] < arr[currIndex - 1])
    {
        swap(arr[currIndex], arr[currIndex - 1]);
        currIndex--;
    }
    while (currIndex < currSize && arr[currIndex] > arr[currIndex + 1])
    {
        swap(arr[currIndex], arr[currIndex + 1]);
        currIndex++;
    }
    return true;
}
// Task 3
int sortedList::removeAll(int val)
{
    int count = 0;
    int i = 0, j = 0;
    while (i < currSize)
    {
        if (arr[i] != val)
        {
            arr[j] = arr[i];
            i++;
            j++;
        }
        else
        {
            count++;
            i++;
        }
    }
    currSize -= count;
    return count;
}
sortedList::sortedList(const sortedList &rhs)
{
    maxSize = rhs.maxSize;
    arr = new int[maxSize];
    currSize = 0;
    for (int i = 0; i < rhs.currSize; i++)
    {
        arr[i] = rhs.arr[i];
        currSize++;
    }
}
sortedList &sortedList::operator=(const sortedList &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    if (arr != nullptr)
    {
        delete[] arr;
    }
    maxSize = rhs.maxSize;
    arr = new int[maxSize];
    currSize = 0;
    for (int i = 0; i < rhs.currSize; i++)
    {
        arr[i] = rhs.arr[i];
        currSize++;
    }
    return *this;
}
