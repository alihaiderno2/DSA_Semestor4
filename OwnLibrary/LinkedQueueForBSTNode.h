# pragma once
# include "BSTNode.h"
class LinkedQueueNode
{
    friend class LinkedQueueForBSTNode;
    private:
        BSTNode* data;
        LinkedQueueNode* next;
    public:
        LinkedQueueNode(){
            data = nullptr;
            next = nullptr;
        }
};
class LinkedQueueForBSTNode
{
    private:
        LinkedQueueNode* front;
        LinkedQueueNode* back;
    public:
        LinkedQueueForBSTNode();
        bool enqueue(BSTNode* tn);
        bool dequeue(BSTNode*& tn);
        bool isEmpty();
        
};