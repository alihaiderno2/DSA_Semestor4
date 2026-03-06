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
    front = 0;
    back = -1;
}
Queue::~Queue()
{
    if (q != nullptr)
    {
        delete[] q;
        q = nullptr;
    }
}
Queue::Queue(const Queue &other)
{
    maxSize = other.maxSize;
    currSize = other.currSize;
    front = other.front;
    back = other.back;
    if (other.q != nullptr)
    {
        q = new int[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            q[i] = other.q[i];
        }
    }
    else
    {
        q = nullptr;
    }
}
Queue& Queue::operator=(const Queue &other)
{
    if(this == &other){
        return *this;
    }
    maxSize = other.maxSize;
    currSize = other.currSize;
    front = other.front;
    back = other.back;
    if (q != nullptr)
    {
        delete[] q;
        q = nullptr;
    }
    if (other.q != nullptr)
    {
        q = new int[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            q[i] = other.q[i];
        }
    }
    else
    {
        q = nullptr;
    }
    return *this;
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
        back++;
        back = back % maxSize;
        q[back] = val;
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
        val = q[front];
        front++;
        front = front % maxSize;
        currSize--;
        if (currSize == 0)
        {
            front = 0;
            back = -1;
        }
        return true;
    }
}