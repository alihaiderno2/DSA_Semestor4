# pragma once
class TreeNode{
    friend class BinaryTree;
    private:
        int data;
        TreeNode* left;
        TreeNode* right;
    public:
        TreeNode();
        TreeNode(int val);
};