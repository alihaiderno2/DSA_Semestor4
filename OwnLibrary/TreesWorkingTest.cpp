#include <iostream>
#include "BinaryTree.h"
#include "LinkedQueueForTreeNode.h"
#include "BST.h"
#include "BSTNode.h"
#include "LinkedQueueNode.h"
#include "TreeNode.h"
#include "LinkedQueueForTreeNode.cpp"
#include "LinkedQueueNode.cpp"
#include "BinaryTree.cpp"
#include "BST.cpp"
#include "TreeNode.cpp"
#include "BSTNode.cpp"
using namespace std;

int main() {
    cout << "--- Initializing Binary Tree ---" << endl;
    BinaryTree tree;

    // Because of how insertLeft and insertRight are written, 
    // this will create a "V" shaped tree.
    // Root will be 10.
    // 5 and 2 will go down the extreme left.
    // 15 and 20 will go down the extreme right.
    
    tree.insertLeft(10); // Becomes root
    tree.insertLeft(5);  // Left child of 10
    tree.insertLeft(2);  // Left child of 5
    
    tree.insertRight(15); // Right child of 10
    tree.insertRight(20); // Right child of 15

    cout << "\nIn-Order Traversal (Expected: 2 5 10 15 20):" << endl;
    tree.displayInOrder();

    cout << "\nPre-Order Traversal (Expected: 10 5 2 15 20):" << endl;
    tree.displayPreOrder();

    cout << "\nPost-Order Traversal (Expected: 2 5 20 15 10):" << endl;
    tree.displayPostOrder();

    cout << "\nLevel-Order Traversal (Expected: 10 5 15 2 20):" << endl;
    tree.levelOrderTraversal();
    cout << endl;

    cout << "\n--- Testing Copy Constructor ---" << endl;
    BinaryTree treeCopy = tree; 
    
    cout << "In-Order Traversal of Copy:" << endl;
    treeCopy.displayInOrder();

    cout << "\n--- Testing createCopy() Method ---" << endl;
    BinaryTree* dynamicCopy = tree.createCopy();
    
    cout << "Level-Order Traversal of Dynamic Copy:" << endl;
    dynamicCopy->levelOrderTraversal();
    cout << endl;

    // Clean up dynamic pointer
    delete dynamicCopy;
    
    cout << "\nExiting program. Destructors will fire now to clean up memory." << endl;
    return 0;
}