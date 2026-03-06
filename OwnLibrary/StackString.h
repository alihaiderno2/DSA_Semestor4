# pragma once
# include <string>
using namespace std;
class StackString
{
    private:
        string* st;
        int maxSize;
        int currSize;
        int top;
    public:
        StackString(int s);
        ~StackString();
        bool push(string val);
        bool pop(string &val);
        bool topVal(string &val) const;
        bool isEmpty() const;
        bool isFull() const;
        void displayHelper() const;
};