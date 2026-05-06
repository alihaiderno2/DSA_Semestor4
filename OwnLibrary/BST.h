# pragma once
# include "BSTNode.h"
class BST{
    private:
        BSTNode* root;
    public:
        BST();
        bool Search(int val);
        void displayInOrder(BSTNode* curr);
        void displayPreOrder(BSTNode* curr);
        void displayPostOrder(BSTNode* curr);
        void displayInOrder();
        void displayPreOrder();
        void displayPostOrder();
        bool insert(int val);
        bool remove(int val);
};