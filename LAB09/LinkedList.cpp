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
    cout << endl;
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
bool LinkedList::unsortedRemove(int val)
{
    Node *curr = head, *prev = nullptr;
    while (curr != nullptr && curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr)
    { // value not found
        return false;
    }
    else if (curr == head)
    { // head is being removed
        head = curr->next;
    }
    else
    {
        prev->next = curr->next;
    }
    delete curr;
    curr = nullptr;
    return true;
}
bool LinkedList::sortedRemove(int val)
{
    Node *curr = head, *prev = nullptr;
    while (curr != nullptr && curr->data < val)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr || curr->data != val)
    {
        return false;
    }
    else if (curr == head)
    {
        head = curr->next;
    }
    else
    {
        prev->next = curr->next;
    }
    delete curr;
    curr = nullptr;
    return true;
}
LinkedList::~LinkedList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
    head = nullptr;
}
LinkedList::LinkedList(LinkedList &orig)
{
    if (orig.head == nullptr)
    {
        head = nullptr;
    }
    else
    {
        head = new Node;
        head->data = orig.head->data;

        Node *p1 = orig.head->next;
        Node *p2 = head;
        while (p1 != nullptr)
        {
            p2->next = new Node;
            p2 = p2->next;
            p2->data = p1->data;
            p1 = p1->next;
        }
        p2->next = nullptr;
    }
}
LinkedList &LinkedList::operator=(LinkedList &orig)
{
    if (this == &orig)
    {
        return *this;
    }
    else
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
        head = nullptr;
        if (orig.head == nullptr)
        {
            head = nullptr;
        }
        else
        {
            head = new Node;
            head->data = orig.head->data;

            Node *p1 = orig.head->next;
            Node *p2 = head;
            while (p1 != nullptr)
            {
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
Node *LinkedList::mergeSort(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *middle = getMiddle(head);
    Node *nextOfMiddle = middle->next;
    middle->next = nullptr;
    Node *left = mergeSort(head);
    Node *right = mergeSort(nextOfMiddle);
    Node *sortedList = merge(left, right);
    return sortedList;
}
Node *LinkedList::getMiddle(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *LinkedList::merge(Node *left, Node *right)
{
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }
    Node temp;
    Node *start = &temp;
    while (left != nullptr && right != nullptr)
    {
        if (left->data <= right->data)
        {
            start->next = left;
            left = left->next;
        }
        else
        {
            start->next = right;
            right = right->next;
        }

        start = start->next;
    }
    if (left != nullptr)
    {
        start->next = left;
    }
    else
    {
        start->next = right;
    }
    return temp.next;
}
void LinkedList::sum(LinkedList &list1, LinkedList &list2)
{

    // Reverse the lists to sum
    list1.reverse();
    list2.reverse();
    int carry = 0;
    Node *l1 = list2.head;
    Node *l2 = list1.head;
    Node dummy;
    Node *l = &dummy;
    while (l1 != nullptr && l2 != nullptr)
    {
        int summation = l1->data + l2->data + carry;
        l->next = new Node();
        l->next->data = summation % 10;
        carry = summation / 10;
        l = l->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != nullptr)
    {
        int summation = l1->data + carry;
        l->next = new Node();
        l->next->data = summation % 10;
        carry = summation / 10;
        l = l->next;
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        int summation = l2->data + carry;
        l->next = new Node();
        l->next->data = summation % 10;
        carry = summation / 10;
        l = l->next;
        l2 = l2->next;
    }
    if (carry > 0)
    {
        l->next = new Node();
        l->next->data = carry;
        l = l->next;
    }
    l->next = nullptr;
    head = dummy.next;

    // Reversing the answer
    reverse();

    // Reversing the original lists back
    list1.reverse();
    list2.reverse();
}
void LinkedList::reverse()
{
    Node *prev = nullptr;
    Node *curr = head;
    while (curr != nullptr)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

// Task#2.1
int LinkedList::removeAll(int val)
{
    int count = 0;
    if (head == nullptr)
    {
        return 0;
    }
    Node *t1 = nullptr;
    Node *t2 = head;
    while (t2 != nullptr && t2->data == val)
    {
        Node *temp = t2;
        t2 = t2->next;
        head = t2;
        delete temp;
        count++;
    }
    while (t2 != nullptr)
    {
        if (t2->data == val)
        {
            t1->next = t2->next;
            delete t2;
            t2 = t1->next;
            count++;
        }
        else
        {
            t1 = t2;
            t2 = t2->next;
        }
    }
    return count;
}
// Task#2.2
int LinkedList::findMin()
{
    return findMin(head);
}
int LinkedList::findMin(Node *curr)
{
    if (curr == nullptr)
    {
        return 999;
    }
    else
    {
        int min = findMin(curr->next);
        if (min < curr->data)
        {
            return min;
        }
        else
        {
            return curr->data;
        }
    }
}