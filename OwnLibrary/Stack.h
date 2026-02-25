# pragma once
class Stack
{
    private:
        int* st;
        int maxSize;
        int currSize;
        int top;
    public:
        Stack(int s);
        ~Stack();
        bool push(int val);
        bool pop(int &val);
        bool topVal(int &val) const;
        bool isEmpty() const;
        bool isFull() const;
        void displayHelper() const;
};