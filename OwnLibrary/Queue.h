# pragma once
class Queue{
    private:
        int* q;
        int currSize;
        int maxSize;
        int front;
        int back;
    public:
        Queue(int );
        ~Queue();
        bool isEmpty()const;
        bool isFull()const;
        bool enqueue(int );
        bool dequeue(int& );
};