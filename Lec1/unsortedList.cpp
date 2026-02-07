#include "unsortedList.h"
#include <iostream>
using namespace std;
unsortedList::unsortedList(int val)
{
    if (val <= 0)
    {
        arr = nullptr;
        maxSize = 0;
    }
    else
    {
        maxSize = val;
        arr = new int[maxSize];
    }

    currSize = 0;
}
unsortedList::~unsortedList()
{
    if (arr != nullptr)
    {
        delete[] arr;
    }
}
bool unsortedList::isEmpty() const
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

bool unsortedList::isFull() const
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
void unsortedList::display() const
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
bool unsortedList::insert(int val)
{
    if (currSize == maxSize)
    {
        return false;
    }
    else
    {
        arr[currSize] = val;
        currSize++;
        return true;
    }
}
bool unsortedList::remove1(int index, int &val)
{
    if (index < 0 || index >= currSize)
    {
        return false;
    }
    else
    {
        val = arr[index];
        arr[index] = arr[currSize - 1];
        currSize--;
        return true;
    }
}
bool unsortedList::remove2(int index, int &val)
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
unsortedList::unsortedList(unsortedList &rhs)
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
unsortedList &unsortedList::operator=(unsortedList &rhs)
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
bool unsortedList::operator==(unsortedList &rhs)const
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
int unsortedList::removeAll1(int val)
{
    int total = 0;
    for (int i = 0; i < currSize; i++)
    {
        if (arr[i] == val)
        {
            arr[i] = arr[currSize - 1];
            total++;
            currSize--;
            if (arr[i] == val)
            {
                i--;
            }
        }
    }
    return total;
}
int unsortedList::removeAll2(int val)
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
            if (arr[i] == val)
            {
                i--;
            }
        }
    }
    return total;
}
int unsortedList::removeAll3(int val)
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
int unsortedList::removeAll4(int val)
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
bool unsortedList::search(int value) {
    for (int i = 0; i < currSize; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}
bool unsortedList::removeMax(int& maxVal){
    if(currSize== 0){
        return false;
    }
    int max = INT_MIN;
    for(int i=0;i<currSize;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    bool removed = false;
    int i=0;
    while(!removed && i<currSize){
        if(arr[i] == max){
            remove2(i,maxVal);
            removed= true;
        }
        i++;
    }
    if(currSize == 0) return false;
    return true;
}
void unsortedList::reverse(){
    int start = 0,end = currSize - 1;
    while(start < end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void unsortedList::combineList(const unsortedList& list2){
    int size = maxSize + list2.maxSize;
    int* newArr = new int[size];
    int i=0;
    for(;i<currSize;i++){
        newArr[i] = arr[i];
    }
    int j=0;
    while(j<list2.currSize){
        newArr[i] = list2.arr[j];
        i++;
        j++;
    }
    delete [] arr;
    arr = newArr;
    currSize = currSize + list2.currSize;
}
// Task4
int unsortedList::replaceAll(int oldVal, int newVal){
    int count=0;
    for(int i=0;i<currSize;i++){
        if(arr[i] == oldVal){
            arr[i] = newVal;
            count++;
        }
    }
    return count;
}
bool unsortedList::removeLastOccurance(int val){
    if(currSize == 0){
        return false;
    }
    int i = currSize -1;
    bool removed = false;
    while(!removed && i>=0){
        if(arr[i]== val){
            remove1(i,val);
            removed = true;
        }
        i--;
    } 
    return removed;
}
int unsortedList::removeAll(int val)
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