# pragma once
# include "Node.h"
class LinkedStack{
    private:
        Node* head;
    public:
        LinkedStack();
        bool push(int val);
        bool pop(int& val);
        ~LinkedStack();
};