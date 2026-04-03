# include "LinkedQueue.h"
# include "Node.h"
#include <iostream>
using namespace std;
LinkedQueue::LinkedQueue()
{
    front = nullptr;
    back = nullptr;
}
LinkedQueue::~LinkedQueue()
{
    Node* temp = front;
    while (temp != nullptr)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}
bool LinkedQueue::enqueue(int val){
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    if(back == nullptr){
        front = newNode;
        back = newNode;
    }
    else{
        back->next = newNode;
        back = newNode;
    }
    return true;
}
bool LinkedQueue::dequeue(int& val){
    if(front == nullptr){
        return false;
    }
    else{
        val = front->data;
        Node* temp = front;
        front = front->next;
        if(front == nullptr){// When there is only one item in the linkedQueue
            back = nullptr;
        }
        delete temp;
        temp = nullptr;
        return true;
    }
}
bool LinkedQueue::isEmpty(){
    if(front == nullptr){
        return true;
    }
    return false;
}
void LinkedQueue::display(){
    Node* temp = front;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
LinkedQueue::LinkedQueue(LinkedQueue& orig){
    if(orig.front == nullptr){
        front = nullptr;
        back = nullptr;
    }
    else{
        front = new Node;
        front->data = orig.front->data;

        Node* p1 = orig.front->next;
        Node* p2 = front;
        while(p1!= nullptr){
            p2->next = new Node;
            p2 = p2->next;
            p2->data = p1->data;
            p1 = p1->next;
        }
        p2->next = nullptr;
        back = p2;
    }
}
LinkedQueue& LinkedQueue::operator=(LinkedQueue& orig){
    if(this == &orig){
        return *this;
    }
    Node* temp = front;
    while (temp != nullptr)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    front = nullptr;
    back = nullptr;

    if(orig.front == nullptr){
        return *this;
    }
    else{
        front = new Node;
        front->data = orig.front->data;

        Node* p1 = orig.front->next;
        Node* p2 = front;
        while(p1!= nullptr){
            p2->next = new Node;
            p2 = p2->next;
            p2->data = p1->data;
            p1 = p1->next;
        }
        p2->next = nullptr;
        back = p2;
    }
    return *this;
}
