# pragma once
class StackChar
{
    private:
        char* st;
        int maxSize;
        int currSize;
        int top;
    public:
        StackChar(int s);
        ~StackChar();
        bool push(char val);
        bool pop(char &val);
        bool topVal(char &val) const;
        bool isEmpty() const;
        bool isFull() const;
        void displayHelper() const;
};