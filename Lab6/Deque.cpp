#include "Deque.h"
# include <iostream>
using namespace std;
Deque::Deque(int s)
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
Deque::~Deque()
{
    if (q != nullptr)
    {
        delete[] q;
        q = nullptr;
    }
}
Deque::Deque(const Deque &other)
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
Deque& Deque::operator=(const Deque &other)
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
bool Deque::isEmpty() const
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
bool Deque::isFull() const
{
    if (currSize == maxSize)
    {
        return true;
    }
    return false;
}
bool Deque::insertAtBack(int val)
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
bool Deque::insertAtFront(int val){
    if(isFull()){
        return false;
    }
    else{
        front--;
        if(front<0){
            front = maxSize-1;
        }
        q[front] = val;
        if(currSize == 0){
            back = front;
        }
        currSize++;
        return true;
    }
}
bool Deque::removeFromFront(int &val)
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
bool Deque::removeFromBack(int& val){
    if(isEmpty()){
        return false;
    }
    else{
        val = q[back];
        back--;
        if(back<0){
            back = maxSize-1;
        }
        currSize--;
        if (currSize == 0)
        {
            front = 0;
            back = -1;
        }
        return true;
    }
}
void Deque::makeEmpty(){
    front = 0;
    back = -1;
    currSize = 0;
}
bool Deque::display()const{
    if(isEmpty()){
        cout<<"Deque empty"<<endl;
        return false;
    }
    int val= 0;
    int total =0;
    int index = front;
    while(total < currSize){
        val = q[index];
        index = (index+1)% maxSize;
        cout<<val<<" ";
        total++;
    }
    cout<<endl;
    return true;
}