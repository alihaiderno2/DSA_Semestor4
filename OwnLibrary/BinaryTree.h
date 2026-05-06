# pragma once
# include "TreeNode.h"
class BinaryTree{
    private:
        TreeNode* root;
    public:
        BinaryTree();
        bool insertLeft(int val);
        bool insertRight(int val);
        void displayInOrder(TreeNode* curr);
        void displayPreOrder(TreeNode* curr);
        void displayPostOrder(TreeNode* curr);
        void displayInOrder();
        void displayPreOrder();
        void displayPostOrder();
        void levelOrderTraversal();
        void levelOrderTraversal(TreeNode* curr);
        BinaryTree(const BinaryTree& other) ;
        BinaryTree* createCopy() ;
        TreeNode* createCopy(TreeNode* curr) ;
        void destroyTree(TreeNode* curr) ;
        ~BinaryTree();
};