# pragma once
# include "BSTNode.h"
# include "LinkedQueueForBSTNode.h"
class BST{
    private:
        BSTNode* root;
        void levelOrderTraversal(BSTNode* curr);
        void displayInOrder(BSTNode* curr);
        void displayPreOrder(BSTNode* curr);
        void displayPostOrder(BSTNode* curr);
        void deleteTree(BSTNode* curr);
        BSTNode* copyTree(BSTNode* curr);
        bool findMin(BSTNode* curr, int& val);
        bool findMax(BSTNode* curr, int& val);
        int getHeight(BSTNode* curr);
        int countNodes(BSTNode* curr);
        int getSuccessor(BSTNode* curr, int val);
        int getPredecessor(BSTNode* curr, int val);
        bool recSearch(BSTNode* curr,int val);
        BSTNode* createBalancedTreeHelper (int* arr, int start, int end);
        int findMinRec(BSTNode* b);
        int findMaxRec(BSTNode* b);
    public:
        BST();
        bool Search(int val);
        void displayInOrder();
        void displayPreOrder();
        void displayPostOrder();
        bool insert(int val);
        bool remove(int val);
        void levelOrderTraversal();
        ~BST();
        BST(const BST& other);
        BST& operator=(const BST& other);
        bool findMin(int& val);
        bool findMax(int& val);
        int getHeight();
        int countNodes();
        int getSuccessor(int val);
        int getPredecessor(int val);
        void menu();
        bool recSearch(int val);
        void createBalancedTree (int* arr, int start, int end);
        int findMin();
        int findMax();
        int findMinRec();
        int findMaxRec();
};