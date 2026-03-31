# include "LinkedStack.h"
LinkedStack::LinkedStack()
{
    head = nullptr;
}
bool LinkedStack::push(int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return true;
}
bool LinkedStack::pop(int& val){
    if(head == nullptr){
        return false;
    }
    val = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
}
LinkedStack::~LinkedStack(){
    Node* temp = head;
    while(temp != nullptr){
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}