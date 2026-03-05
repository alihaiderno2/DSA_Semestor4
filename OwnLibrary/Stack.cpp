#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack(int s)
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
Stack::~Stack()
{
    if (st != nullptr)
    {
        delete[] st;
        st = nullptr;
    }
}
Stack::Stack(const Stack& temp){
    maxSize = temp.maxSize;
    if(maxSize == 0){
        st = nullptr;
    }
    else{
        st = new int[maxSize];
        for(int i = 0; i < maxSize; i++){
            st[i] = temp.st[i];
        }
    }
    currSize = temp.currSize;
    top = temp.top;
}
Stack& Stack::operator=(const Stack& temp){
    if(this == &temp){
        return *this;
    }
    else{
        if(maxSize > 0){
            delete[] st;
        }
        maxSize = temp.maxSize;
        if(maxSize == 0){
            st = nullptr;
        }
        else{
            st = new int[maxSize];
            for(int i = 0; i < maxSize; i++){
                st[i] = temp.st[i];
            }
        }
        currSize = temp.currSize;
        top = temp.top;
        return *this;
    }
}
bool Stack::push(int val)
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
bool Stack::pop(int &val)
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
bool Stack::topVal(int &val) const
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
bool Stack::isEmpty() const
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
bool Stack::isFull() const
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
void Stack::displayHelper() const
{
    for (int i = top; i >= 0; i--)
    {
        cout << st[i] << endl;
    }
}