# pragma once
class Deque{
    private:
        int* q;
        int currSize;
        int maxSize;
        int front;
        int back;
    public:
        Deque(int );
        ~Deque();
        bool isEmpty()const;
        bool isFull()const;
        Deque(const Deque& );
        bool display()const;
        void makeEmpty();
        Deque& operator=(const Deque& );
        bool insertAtFront(int val);
        bool insertAtBack(int val);
        bool removeFromFront (int& val);
        bool removeFromBack (int& val);
};