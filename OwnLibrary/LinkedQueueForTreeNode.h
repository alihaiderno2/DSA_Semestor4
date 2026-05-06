# pragma once
# include "LinkedQueueNode.h"
class LinkedQueueForTreeNode
{
    private:
        LinkedQueueNode* front;
        LinkedQueueNode* back;
    public:
        LinkedQueueForTreeNode();
        bool enqueue(TreeNode* tn);
        bool dequeue(TreeNode*& tn);
        bool isEmpty();
        
};