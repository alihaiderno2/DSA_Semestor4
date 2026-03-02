# pragma once
class Queue{
    private:
        int* q;
        int currSize;
        int maxSize;
        int first;
        int last;
        int queued;
    public:
        Queue(int );
        ~Queue();
        bool isEmpty()const;
        bool isFull()const;
        bool enqueue(int );
        bool dequeue(int& );
};