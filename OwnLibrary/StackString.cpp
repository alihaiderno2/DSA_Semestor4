#include "StackString.h"
#include <iostream>
using namespace std;
StackString::StackString(int s)
{
    maxSize = s;
    if (maxSize <= 0)
    {
        maxSize = 0;
        st = nullptr;
    }
    else
    {
        st = new string[maxSize];
    }
    currSize = 0;
    top = -1;
}
StackString::~StackString()
{
    if (st != nullptr)
    {
        delete[] st;
        st = nullptr;
    }
}
bool StackString::push(string val)
{
    if (isFull())
    {
        return false;
    }
    else
    {
        top++;
        st[top] = val;
        currSize++;
        return true;
    }
}
bool StackString::pop(string &val)
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        val = st[top];
        top--;
        currSize--;
        return true;
    }
}
bool StackString::topVal(string &val) const
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        val = st[top];
        return true;
    }
}
bool StackString::isEmpty() const
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
bool StackString::isFull() const
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
void StackString::displayHelper() const
{
    for (int i = top; i >= 0; i--)
    {
        cout << st[i] << endl;
    }
}