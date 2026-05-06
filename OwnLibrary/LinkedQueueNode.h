# pragma once
# include "TreeNode.h"
class LinkedQueueNode
{
    friend class LinkedQueueForTreeNode;
    private:
        TreeNode* data;
        LinkedQueueNode* next;
    public:
        LinkedQueueNode();
};