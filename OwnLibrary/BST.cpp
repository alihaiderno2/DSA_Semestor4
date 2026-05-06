# include "BST.h"
# include <iostream>
using namespace std;
BST::BST(){
    root = nullptr;
}
bool BST::Search(int val){
    BSTNode* temp = root;
    while(temp != nullptr){
        if(temp->data == val){
            return true;
        }
        else if(temp->data > val){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}
void BST::displayInOrder(BSTNode* curr){
    if(curr == nullptr){
        return;
    }
    displayInOrder(curr->left);
    cout << curr->data << " ";
    displayInOrder(curr->right);
}
void BST::displayPreOrder(BSTNode* curr){
    if(curr == nullptr){
        return;
    }
    cout << curr->data << " ";
    displayPreOrder(curr->left);
    displayPreOrder(curr->right);
}
void BST::displayPostOrder(BSTNode* curr){
    if(curr == nullptr){
        return;
    }
    displayPostOrder(curr->left);
    displayPostOrder(curr->right);
    cout << curr->data << " ";
}
void BST::displayInOrder(){
    displayInOrder(root);
    cout << endl;
}
void BST::displayPreOrder(){
    displayPreOrder(root);
    cout << endl;
}
void BST::displayPostOrder(){
     displayPostOrder(root);
        cout << endl;
}
bool BST::insert(int val){
    BSTNode* newNode = new BSTNode;
    newNode->data = val;
    BSTNode* curr = root;
    BSTNode* prnt = nullptr;

    while(curr != nullptr){
        prnt = curr;
        if(val == curr->data){
            delete newNode;
            return false;
        }
        else if(val < curr->data){
            curr= curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    // When tree is empty
    if(prnt == nullptr){
        root = newNode;
        return true;
    }
    if(val > prnt->data){
        prnt->right = newNode;
    }
    else{
        prnt->left = newNode;
    }
    return true;

}
bool BST::remove(int val){
    BSTNode* curr = root;
    BSTNode* prnt = nullptr;

    while(curr != nullptr && curr->data != val){
        prnt = curr;
        if(val < curr->data){
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    if(curr == nullptr){
        return false;
    }
    // Conversion of Degree 2 to Degree 1
    if(curr->left != nullptr && curr->right != nullptr ){
        BSTNode* successor = curr->right;
        BSTNode* prntSuc = curr;
        while(successor->left != nullptr){
            prntSuc = successor;
            successor = successor->left;
        }

        curr->data = successor->data;
        curr = successor;
        prnt = prntSuc;
    }
    // Deletion of Degree 1 or 0
    BSTNode* child ;
    if(curr->left != nullptr){
        child = curr->left;
    }
    else{
        child = curr->right;
    }
    if(prnt == nullptr){
        root = child;
    }else if(curr == prnt->left){
        prnt->left = child;
    }
    else{
        prnt->right = child;
    }

    delete curr;
    curr = nullptr;

    return true;
}