# include "BinaryTree.h"
# include "LinkedQueueForTreeNode.h"
# include <iostream>
using namespace std;
BinaryTree::BinaryTree(){
    root = nullptr;
}
bool BinaryTree::insertLeft(int val){
    TreeNode* newNode = new TreeNode(val);
    if(root == nullptr){
        root = newNode;
        return true;
    }
    else{
        TreeNode* temp = root;
        while(temp->left != nullptr){
            temp = temp->left;
        }
        temp->left = newNode;
        return true;
    }
}
bool BinaryTree::insertRight(int val){
    TreeNode* newNode = new TreeNode(val);
    if(root == nullptr){
        root = newNode;
        return true;
    }
    else{
        TreeNode* temp = root;
        while(temp->right != nullptr){
            temp = temp->right;
        }
        temp->right = newNode;
        return true;
    }
}
void BinaryTree::displayInOrder(TreeNode* tn){
    if(tn == nullptr){
        return;
    }
    displayInOrder(tn->left);
    cout << tn->data << " ";
    displayInOrder(tn->right);
}
void BinaryTree::displayPreOrder(TreeNode* tn){
    if(tn == nullptr){
        return;
    }
    cout << tn->data << " ";
    displayPreOrder(tn->left);
    displayPreOrder(tn->right);
}
void BinaryTree::displayPostOrder(TreeNode* tn){
    if(tn == nullptr){
        return;
    }
    displayPostOrder(tn->left);
    displayPostOrder(tn->right);
    cout << tn->data << " ";
}
void BinaryTree::displayInOrder(){
    displayInOrder(root);
    cout << endl;
}
void BinaryTree::displayPreOrder(){
    displayPreOrder(root);
    cout << endl;
}
void BinaryTree::displayPostOrder(){
    displayPostOrder(root);
    cout << endl;
}
void BinaryTree::levelOrderTraversal(){
    levelOrderTraversal(root);
}
void BinaryTree::levelOrderTraversal(TreeNode* curr){
    if(curr == nullptr){
        return;
    }
    LinkedQueueForTreeNode queue;
    queue.enqueue(curr);
    while(!queue.isEmpty()){
        TreeNode* temp;
        queue.dequeue(temp);
        cout << temp->data << " ";
        if(temp->left != nullptr){
            queue.enqueue(temp->left);
        }
        if(temp->right != nullptr){
            queue.enqueue(temp->right);
        }
    }
}
BinaryTree* BinaryTree::createCopy(){
    BinaryTree* copy = new BinaryTree();
    copy->root = createCopy(root);
    return copy;
}
TreeNode* BinaryTree::createCopy(TreeNode* tn){
    if(tn == nullptr){
        return nullptr;
    }
    TreeNode* newNode = new TreeNode();
    newNode->data = tn->data;
    newNode->left = createCopy(tn->left);
    newNode->right = createCopy(tn->right);
    return newNode;
}
void BinaryTree::destroyTree(TreeNode* tn){
    if(tn == nullptr){
        return;
    }
    destroyTree(tn->left);
    destroyTree(tn->right);
    delete tn;
}
BinaryTree::~BinaryTree(){
    destroyTree(root);
}
BinaryTree::BinaryTree(const BinaryTree& other){
    root = createCopy(other.root);
}