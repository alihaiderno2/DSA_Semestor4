# pragma once
class StackDouble
{
    private:
        double* st;
        int maxSize;
        int currSize;
        int top;
    public:
        StackDouble(int s);
        StackDouble(const StackDouble&);
        ~StackDouble();
        bool push(double val);
        bool pop(double &val);
        bool topVal(double &val) const;
        bool isEmpty() const;
        bool isFull() const;
        void displayHelper() const;
        StackDouble& operator=(const StackDouble&);
};