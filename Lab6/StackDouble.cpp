#include "StackDouble.h"
#include <iostream>
using namespace std;
StackDouble::StackDouble(int s)
{
    maxSize = s;
    if (maxSize <= 0)
    {
        maxSize = 0;
        st = nullptr;
    }
    else
    {
        st = new double[maxSize];
    }
    currSize = 0;
    top = -1;
}
StackDouble::~StackDouble()
{
    if (st != nullptr)
    {
        delete[] st;
        st = nullptr;
    }
}
StackDouble::StackDouble(const StackDouble& temp){
    maxSize = temp.maxSize;
    if(maxSize == 0){
        st = nullptr;
    }
    else{
        st = new double[maxSize];
        for(int i = 0; i < maxSize; i++){
            st[i] = temp.st[i];
        }
    }
    currSize = temp.currSize;
    top = temp.top;
}
StackDouble& StackDouble::operator=(const StackDouble& temp){
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
            st = new double[maxSize];
            for(int i = 0; i < maxSize; i++){
                st[i] = temp.st[i];
            }
        }
        currSize = temp.currSize;
        top = temp.top;
        return *this;
    }
}
bool StackDouble::push(double val)
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
bool StackDouble::pop(double &val)
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
bool StackDouble::topVal(double &val) const
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
bool StackDouble::isEmpty() const
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
bool StackDouble::isFull() const
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
void StackDouble::displayHelper() const
{
    for (int i = top; i >= 0; i--)
    {
        cout << st[i] << endl;
    }
}