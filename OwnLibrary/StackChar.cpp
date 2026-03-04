#include "StackChar.h"
#include <iostream>
using namespace std;
StackChar::StackChar(int s)
{
    maxSize = s;
    if (maxSize <= 0)
    {
        maxSize = 0;
        st = nullptr;
    }
    else
    {
        st = new int[maxSize];
    }
    currSize = 0;
    top = -1;
}
StackChar::~StackChar()
{
    if (st != nullptr)
    {
        delete[] st;
        st = nullptr;
    }
}
bool StackChar::push(char val)
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
bool StackChar::pop(char &val)
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
bool StackChar::topVal(char &val) const
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
bool StackChar::isEmpty() const
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
bool StackChar::isFull() const
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
void StackChar::displayHelper() const
{
    for (int i = top; i >= 0; i--)
    {
        cout << st[i] << endl;
    }
}