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
void BST::levelOrderTraversal(){
    levelOrderTraversal(root);
}
void BST::levelOrderTraversal(BSTNode* curr){
    if(curr == nullptr){
        return;
    }
    LinkedQueueForBSTNode q;
    q.enqueue(curr);
    while(!q.isEmpty()){
        BSTNode* temp;
        q.dequeue(temp);
        cout<<temp->data<<" ";
        if(temp->left != nullptr){
            q.enqueue(temp->left);
        }
        if(temp->right != nullptr){
            q.enqueue(temp->right);
        }
    }

    cout << endl;
}
BST::~BST(){
    deleteTree(root);
    root = nullptr;
}
void BST::deleteTree(BSTNode* curr){
    if(curr == nullptr){
        return;
    }
    deleteTree(curr->left);
    deleteTree(curr->right);
    delete curr;
    curr = nullptr;
}
BST::BST(const BST& other){
    root = copyTree(other.root);
}
BST& BST::operator=(const BST& other){
    if(this == &other){
        return *this;
    }
    deleteTree(root);
    root = copyTree(other.root);
    return *this;
}
BSTNode* BST::copyTree(BSTNode* curr){
    if(curr == nullptr){
        return nullptr;
    }
    BSTNode* newNOde = new BSTNode(curr->data);
    newNOde->left = copyTree(curr->left);
    newNOde->right = copyTree(curr->right);
    return newNOde;
}
bool BST::findMin(int& val){
    return findMin(root, val);
}
bool BST::findMin(BSTNode* curr, int& val){
    if(curr == nullptr){
        return false;
    }
    while(curr->left != nullptr){
        curr = curr->left;
    }
    val = curr->data;
    return true;
}
bool BST::findMax(int& val){
    return findMax(root, val);
}
bool BST::findMax(BSTNode* curr, int& val){
    if(curr == nullptr){
        return false;
    }
    while(curr->right != nullptr){
        curr = curr->right;
    }
    val = curr->data;
    return true;
}
int BST::getHeight(){
    return getHeight(root);
}
int BST::getHeight(BSTNode* curr){
    if(curr == nullptr){
        return 0;
    }
    int leftHeight = getHeight(curr->left);
    int rightHeight = getHeight(curr->right);
    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }
    else{
        return rightHeight + 1;
    }
}
int BST::countNodes(){
    return countNodes(root);
}
int BST::countNodes(BSTNode* curr){
    if(curr == nullptr){
        return 0;
    }
    int leftCount = countNodes(curr->left);
    int rightCount = countNodes(curr->right);
    return leftCount + rightCount + 1;
}
int BST::getSuccessor(int val){
    return getSuccessor(root, val);
}
int BST::getSuccessor(BSTNode* curr,int val){
    if(curr == nullptr){
        return -1;
    }
    BSTNode* successor = nullptr;
    while(curr != nullptr && curr->data != val){
        if(val < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    if(curr == nullptr){
        return -1;
    }
    if(curr->right == nullptr){
        return -1;
    }
    successor = curr->right;
    while(successor->left != nullptr){
        successor = successor->left;
    }
    return successor->data;
}
int BST::getPredecessor(int val){
    return getPredecessor(root, val);
}
int BST::getPredecessor(BSTNode* curr,int val){
    if(curr == nullptr){
        return -1;
    }
    BSTNode* predecessor = nullptr;
    while(curr != nullptr && curr->data != val){
        if(val < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    if(curr == nullptr){
        return -1;
    }
    if(curr->left == nullptr){
        return -1;
    }
    predecessor = curr->left;
    while(predecessor->right != nullptr){
        predecessor = predecessor->right;
    }
    return predecessor->data;
}
void BST::menu(){
    cout << "1. Insert" << endl;
    cout << "2. Remove" << endl;
    cout << "3. Search" << endl;
    cout << "4. Display InOrder" << endl;
    cout << "5. Display PreOrder" << endl;
    cout << "6. Display PostOrder" << endl;
    cout << "7. Level Order Traversal" << endl;
    cout << "8. Find Minimum" << endl;
    cout << "9. Find Maximum" << endl;
    cout << "10. Get Height" << endl;
    cout << "11. Count Nodes" << endl;
    cout << "12. Get Successor" << endl;
    cout << "13. Get Predecessor" << endl;
    cout << "14. Exit" << endl;
    int choice;
    int val;
    
}