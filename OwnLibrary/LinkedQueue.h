# pragma once
# include "Node.h"
class LinkedQueue
{
    private:
        Node* front;
        Node* back;
    public:
        LinkedQueue();
        bool enqueue(int);
        bool dequeue(int&);
        bool isEmpty();
        void display();
        ~LinkedQueue();
        LinkedQueue(LinkedQueue&);
        LinkedQueue& operator=(LinkedQueue& orig);
};