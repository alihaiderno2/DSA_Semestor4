# pragma once
class BSTNode
{
    friend class BST;
    private:
        int data;
        BSTNode* left;
        BSTNode* right;
    public:
        BSTNode();
};