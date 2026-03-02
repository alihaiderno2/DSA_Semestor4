#include "Queue.h"
Queue::Queue(int s)
{
    maxSize = s;
    if (s > 0)
    {
        q = new int[s];
    }
    else
    {
        q = nullptr;
    }
    currSize = 0;
    first = -1;
    last = -1;
    queued = -1;
}
Queue::~Queue()
{
    if (q != nullptr)
    {
        delete[] q;
        q = nullptr;
    }
}
bool Queue::isEmpty() const
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
bool Queue::isFull() const
{
    if (currSize == maxSize)
    {
        return true;
    }
    return false;
}
bool Queue::enqueue(int val)
{
    if (!isFull())
    {
        if(first == -1){
            first++;
            last++;
        }
        else{
            last++;
        }
        if (last == maxSize)
        {
            last = 0;
        }
        q[last] = val;
        currSize++;
        return true;
    }
    else
    {
        return false;
    }
}
bool Queue::dequeue(int &val)
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        val = q[first];
        first++;
        if(first == maxSize){
            first = 0;
        }
        currSize--;
        if (currSize == 0)
        {
            first = -1;
            last = -1;
        }
        return true;
    }
}