#include "CDLLD.h"
#include <iostream>
using namespace std;
CDLLD::CDLLD()
{
    head.next = &head;
    head.prev = &head;
}
void CDLLD::display(DNode *curr)
{
    if (curr == &head)
    {
        cout << endl;
        return;
    }
    else
    {
        cout << curr->data << " ";
        display(curr->next);
    }
}
void CDLLD::display()
{
    display(head.next);
}
bool CDLLD::insertAtStart(int val)
{
    DNode *newNode = new DNode();
    newNode->data = val;

    newNode->next = head.next;

    head.next = newNode;

    newNode->prev = &head;
    newNode->next->prev = newNode;

    return true;
}
bool CDLLD::insertAtEnd(int val)
{
    DNode *newNode = new DNode();
    newNode->data = val;

    newNode->prev = head.prev;
    newNode->next = &head;

    newNode->prev->next = newNode;
    head.prev = newNode;

    return true;
}
CDLLD::CDLLD(CDLLD &orig)
{
    head.next = &head;
    head.prev = &head;

    DNode *temp = &head;
    DNode *curr = orig.head.next;
    while (curr != &orig.head)
    {
        DNode *newNode = new DNode();
        newNode->data = curr->data;
        // to point to the head of the new list by the newNode's next pointer
        newNode->next = temp->next;
        temp->next = newNode;

        // similarly to point to the head of the new list by the newNode's prev pointer
        newNode->prev = temp;
        newNode->next->prev = newNode;

        temp = temp->next;
        curr = curr->next;
    }
}
CDLLD::~CDLLD()
{
    DNode *temp = head.next;
    while (temp != &head)
    {
        DNode *temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
}
bool CDLLD::removeByVal(int val)
{
    DNode *curr = head.next;
    while (curr != &head)
    {
        if (curr->data == val)
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            curr = nullptr;
            return true;
        }
        curr = curr->next;
    }
    return false;
}
bool CDLLD::removeAtStart()
{
    if (head.next == &head)
    {
        return false;
    }
    DNode *temp = head.next;
    head.next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    temp = nullptr;
    return true;
}
bool CDLLD::removeAtEnd()
{
    if (head.next == &head)
    {
        return false;
    }
    DNode *curr = head.prev;
    head.prev = curr->prev;
    curr->prev->next = &head;

    delete curr;
    curr = nullptr;
    return true;
}
bool CDLLD::sortedInsert(int val)
{
    DNode *newNode = new DNode();
    newNode->data = val;
    DNode *curr = head.next;
    while (curr != &head && curr->data < val)
    {
        curr = curr->next;
    }
    newNode->prev = curr->prev;
    newNode->next = curr;

    newNode->prev->next = newNode;
    curr->prev = newNode;

    return true;
}
bool CDLLD::sortedRemove(int val)
{
    DNode *curr = head.next;
    while (curr != &head && curr->data < val)
    {
        curr = curr->next;
    }
    if (curr != &head && curr->data == val)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        delete curr;
        curr = nullptr;
        return true;
    }
    else
    {
        return false;
    }
}
void CDLLD::combine(CDLLD &list1, CDLLD &list2)
{

    if (list1.head.next == &list1.head && list2.head.next == &list2.head)
    {
        return;
    }
    else if (list1.head.next == &list1.head)
    {
        head.next = list2.head.next;
        head.prev = list2.head.prev;
        list2.head.prev->next = &head;
        list2.head.next->prev = &head;

        list2.head.next = &list2.head;
        list2.head.prev = &list2.head;
    }
    else if (list2.head.next == &list2.head)
    {
        head.next = list1.head.next;
        head.prev = list1.head.prev;
        list1.head.prev->next = &head;
        list1.head.next->prev = &head;

        list1.head.next = &list1.head;
        list1.head.prev = &list1.head;
    }
    else
    {
        // Pointing the head to the list1's first element
        head.next = list1.head.next;
        list1.head.next->prev = &head;
        // Pointing the list1's last element to the list2's first element
        list1.head.prev->next = list2.head.next;
        list2.head.next->prev = list1.head.prev;
        // Pointing the very last node of list2 to the head
        list2.head.prev->next = &head;
        head.prev = list2.head.prev;

        // pointing the heads back to the head
        list1.head.next = &list1.head;
        list1.head.prev = &list1.head;
        list2.head.next = &list2.head;
        list2.head.prev = &list2.head;
    }
}
CDLLD &CDLLD::operator=(CDLLD &orig)
{
    if (this == &orig)
    {
        return *this;
    }
    DNode *temp = head.next;
    while (temp != &head)
    {
        DNode *temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
    head.next = &head;
    head.prev = &head;

    temp = &head;
    DNode *curr = orig.head.next;
    while (curr != &orig.head)
    {
        DNode *newNode = new DNode();
        newNode->data = curr->data;

        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
        curr = curr->next;
    }
    temp->next = &head;
    head.prev = temp;
    return *this;
}
void CDLLD::reverse()
{
    if (head.next == &head)
    {
        return;
    }

    DNode *curr = &head;
    do
    {
        DNode *tempForStore = curr->next;

        curr->next = curr->prev;
        curr->prev = tempForStore;

        curr = tempForStore;
    } while (curr != &head);
}
// Task#1.1
void CDLLD::shuffleMerge(CDLLD &list1, CDLLD &list2)
{
    if (list1.head.next == &list1.head && list2.head.next == &list2.head)
    {
        return;
    }
    else if (list1.head.next == &list1.head)
    {
        head.next = list2.head.next;
        head.prev = list2.head.prev;
        list2.head.prev->next = &head;
        list2.head.next->prev = &head;

        list2.head.next = &list2.head;
        list2.head.prev = &list2.head;
    }
    else if (list2.head.next == &list2.head)
    {
        head.next = list1.head.next;
        head.prev = list1.head.prev;
        list1.head.prev->next = &head;
        list1.head.next->prev = &head;

        list1.head.next = &list1.head;
        list1.head.prev = &list1.head;
    }
    else
    {
        DNode *p1 = list1.head.next;
        DNode *p2 = list2.head.next;

        DNode *temp = &head;
        while (p1 != &list1.head)
        {

            DNode *temp1 = p1->next;
            DNode *temp2 = p2->next;

            temp->next = p1;
            p1->prev = temp;

            p1->next = p2;
            p2->prev = p1;

            p2->next = &head;
            head.prev = p2;

            p1 = temp1;
            p2 = temp2;
            temp = temp->next->next;
        }

        list1.head.next = &list1.head;
        list1.head.prev = &list1.head;
        list2.head.next = &list2.head;
        list2.head.prev = &list2.head;
    }
}
// Task#1.2
void CDLLD::splitList(CDLLD &leftHalf, CDLLD &rightHalf)
{
    int count = 0;
    DNode *curr = head.next;
    while (curr != &head)
    {
        curr = curr->next;
        count++;
    }
    if (count == 0)
    {
        leftHalf.head.next = &leftHalf.head;
        rightHalf.head.next = &rightHalf.head;
        leftHalf.head.prev = &leftHalf.head;
        rightHalf.head.prev = &rightHalf.head;
        return;
    }
    else if (count == 1)
    {
        DNode* onlyNode = head.next;
        leftHalf.head.next = onlyNode;
        leftHalf.head.prev = onlyNode;
        onlyNode->prev = &leftHalf.head;
        onlyNode->next = &leftHalf.head;

        rightHalf.head.next = &rightHalf.head;
        rightHalf.head.prev = &rightHalf.head;

        head.next = &head;
        head.prev = &head;
        return;
    }
    int leftPrevious = count / 2 + count % 2;
    DNode *startOfRight = head.next;
    for (int i = 0; i < leftPrevious; i++)
    {
        startOfRight = startOfRight->next;
    }
    DNode *endOfLeft = startOfRight->prev;
    DNode *endOfRight = head.prev;
    // Leftside manipulation
    leftHalf.head.next = head.next;
    leftHalf.head.prev = endOfLeft;
    endOfLeft->next = &leftHalf.head;
    head.next->prev = &leftHalf.head;
    // Right side manipulation
    rightHalf.head.next = startOfRight;
    rightHalf.head.prev = endOfRight;
    endOfRight->next = &rightHalf.head;
    startOfRight->prev = &rightHalf.head;

    head.next = &head;
    head.prev = &head;
}
// Task#1.3
bool CDLLD::isSorted() const
{
    if (head.next == &head || head.next->next == &head)
    {
        return true;
    }
    DNode *curr = head.next;
    DNode *nextP = head.next->next;
    while (nextP != &head)
    {
        if (curr->data > nextP->data)
        {
            return false;
        }
        curr = curr->next;
        nextP = nextP->next;
    }
    return true;
}
// Task#1.4
bool CDLLD::removeLastNode(int &val)
{
    if (head.next == &head)
    {
        return false;
    }
    DNode *toBeRemoved = head.prev;
    head.prev = toBeRemoved->prev;
    toBeRemoved->prev->next = &head;
    val = toBeRemoved->data;
    delete toBeRemoved;
    toBeRemoved = nullptr;
    return true;
}
bool CDLLD::removeSecondLastNode(int &val)
{
    if (head.next == &head || head.next->next == &head)
    {
        return false;
    }
    DNode *secondLast = head.prev->prev;
    secondLast->prev->next = secondLast->next;
    secondLast->next->prev = secondLast->prev;
    val = secondLast->data;
    delete secondLast;
    secondLast = nullptr;
    return true;
}
bool CDLLD::removeKthNode (int k, int& val){
    DNode* curr = head.next;
    int i =1;
    while(curr != &head && i<k){
        curr = curr->next;
        i++;
    }
    if(curr == &head){
        return false;
    }
    curr ->next->prev = curr->prev;
    curr->prev->next = curr->next;
    val = curr->data;
    delete curr;
    curr = nullptr;
    return true;
}