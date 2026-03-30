#include <Node.h>
#include <LinkedList.h>
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
    while (head != nullptr)
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
    while (head != nullptr)
    {
        if (temp->data == key)
        {
            return true;
        }
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
}