#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList()
{
    head = nullptr;
}
void LinkedList::display()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void LinkedList::insertAtStart(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}
void LinkedList::insertAtEnd(int val)
{
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    Node *curr = head, *prev = nullptr;
    while (curr != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev == nullptr)
    {
        head = newNode;
        return;
    }
    prev->next = newNode;
}
void LinkedList::sortedInsert(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->next = nullptr;
    Node *curr = head, *prev = nullptr;
    while (curr != nullptr && curr->data < val)
    {
        prev = curr;
        curr = curr->next;
    }
    temp->next = curr;
    if (prev == nullptr)
    {
        head = temp;
    }
    else
    {
        prev->next = temp;
    }
}
bool LinkedList::search(int key)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int LinkedList::findMax()
{
    if (head == nullptr)
    {
        return -999;
    }
    int max = head->data;
    Node *temp = head->next;
    while (temp != nullptr)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}
void LinkedList::displayReverse()
{
    if (head == nullptr)
    {
        return;
    }
    Node *first = nullptr;
    Node *second = head;
    Node *third = head->next;
    while (second != nullptr)
    {
        second->next = first;
        first = second;
        second = third;
        if (third != nullptr)
        {
            third = third->next;
        }
    }
    head = first;
    while (first != nullptr)
    {
        cout << first->data;
        first = first->next;
    }
    first = nullptr;
    second = head;
    third = head->next;
    while (second != nullptr)
    {
        second->next = first;
        first = second;
        second = third;
        if (third != nullptr)
        {
            third = third->next;
        }
    }
    head = first;
}
bool LinkedList::unsortedRemove(int val){
    Node* curr = head, *prev = nullptr;
    while(curr!= nullptr && curr->data != val){
        prev = curr;
        curr = curr->next;
    }
    if(curr == nullptr){// value not found
        return false;
    }
    else if(curr == head){//head is being removed
        head = curr->next;
    }
    else{
        prev->next = curr->next;
    }
    delete curr;
    curr = nullptr;
    return true;
}
bool LinkedList::sortedRemove(int val){
    Node* curr = head, *prev = nullptr;
    while(curr != nullptr && curr->data <val){
        prev = curr;
        curr = curr->next;
    }
    if(curr == nullptr || curr->data != val)
    {
        return false;
    }
    else if(curr == head){
        head = curr->next;
    }
    else{
        prev->next = curr->next;
    }
    delete curr;
    curr = nullptr;
    return true;
}
LinkedList::~LinkedList(){
    Node* temp = head;
    while(temp!= nullptr){
        Node* temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
    head = nullptr;
}
LinkedList::LinkedList(LinkedList& orig){
    if(orig.head == nullptr){
        head = nullptr;
    }
    else{
        head = new Node;
        head->data = orig.head->data;

        Node* p1 = orig.head->next;
        Node* p2 = head;
        while(p1!= nullptr){
            p2->next = new Node;
            p2 = p2->next;
            p2->data = p1->data;
            p1 = p1->next;
        }
        p2->next = nullptr;
    }
}
LinkedList& LinkedList::operator=(LinkedList& orig){
    if(this == &orig){
        return *this;
    }
    else{
        Node* temp = head;
        while(temp!= nullptr){
            Node* temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
        head = nullptr;
        if(orig.head == nullptr){
        head = nullptr;
        }
        else{
            head = new Node;
            head->data = orig.head->data;

            Node* p1 = orig.head->next;
            Node* p2 = head;
            while(p1!= nullptr){
                p2->next = new Node;
                p2 = p2->next;
                p2->data = p1->data;
                p1 = p1->next;
            }
            p2->next = nullptr;
        }
        return *this;
    }
}