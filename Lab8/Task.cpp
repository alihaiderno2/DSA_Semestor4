/* Name: Ali Haider
    Roll No: BITF24M004
    Morning Section
*/
#include <iostream>
using namespace std;
class LinkedList;
class Node
{
    friend class LinkedList;

private:
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
    int getData()
    {
        return data;
    }
    Node *getNext()
    {
        return next;
    }
    void setNext(Node *nextNode)
    {
        next = nextNode;
    }
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    void display();
    void insertAtStart(int val);
    void insertAtEnd(int val);
    void sortedInsert(int val);
    bool search(int key);
    void displayReverse();
    bool unsortedRemove(int val);
    bool sortedRemove(int val);
    ~LinkedList();
    LinkedList(LinkedList &orig);
    LinkedList &operator=(LinkedList &orig);
    // Task 1
    bool removeKthNode(int k, int &val);
    // Task2
    void combine(LinkedList &list1, LinkedList &list2);
    // Task 3
    void shuffleMerge(LinkedList &list1, LinkedList &list2);
    // Task 4
    bool removeLastNode(int &val);
    bool removeSecondLastNode(int &val);
    // Task 5
    int countNodes();
    int findMin();
    int findMax();
};
// Task 1 Implementation
bool LinkedList::removeKthNode(int k, int &val)
{
    if (k < 1 || head == nullptr)
    {
        return false;
    }
    Node *temp = head, *prev = nullptr;
    while (temp != nullptr && k > 1)
    {
        prev = temp;
        temp = temp->next;
        k--;
    }
    if (temp == nullptr)
    {
        return false;
    }
    else if (temp == head)
    {
        head = temp->next;
        val = temp->data;
        delete temp;
        temp = nullptr;
        return true;
    }
    else
    {
        prev->next = temp->next;
        val = temp->data;
        delete temp;
        temp = nullptr;
        return true;
    }
}
// Task 2 Implementation
void LinkedList::combine(LinkedList &list1, LinkedList &list2)
{
    if (list1.head == nullptr && list2.head == nullptr)
    {
        head = nullptr;
    }
    else if (list1.head == nullptr)
    {
        head = list2.head;
        list2.head = nullptr;
    }
    else if (list2.head == nullptr)
    {
        head = list1.head;
        list1.head = nullptr;
    }
    else
    {
        head = list1.head;
        list1.head = nullptr;
        Node *temp = head;
        while (temp != nullptr && temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = list2.head;
        list2.head = nullptr;
    }
}
// Task 3 implementation
void LinkedList::shuffleMerge(LinkedList &list1, LinkedList &list2)
{
    if (list1.head == nullptr && list2.head == nullptr)
    {
        head = nullptr;
    }
    else if (list1.head == nullptr)
    {
        head = list2.head;
        list2.head = nullptr;
    }
    else if (list2.head == nullptr)
    {
        head = list1.head;
        list1.head = nullptr;
    }
    else
    {
        head = list1.head;
        Node *tempOrig = head;
        Node *temp = list2.head;
        while (temp != nullptr)
        {
            Node *nextNodeInOrig = tempOrig->next;
            tempOrig->next = temp;
            list2.head = temp->next;
            temp->next = nextNodeInOrig;
            temp = list2.head;
            tempOrig = nextNodeInOrig;
        }
        list1.head = nullptr;
    }
}
// Task 4 implementation
bool LinkedList::removeLastNode(int &val)
{
    if (head == nullptr)
    {
        return false;
    }
    Node *temp = head, *prev = nullptr;
    while (temp != nullptr && temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == nullptr)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    val = temp->data;
    delete temp;
    temp = nullptr;
    return true;
}
bool LinkedList::removeSecondLastNode(int &val)
{
    if (head == nullptr)
    {
        return false;
    }
    if (head->next == nullptr)
    {
        return false;
    }
    Node *temp = head, *prev = nullptr, *preprev = nullptr;
    while (temp != nullptr && temp->next != nullptr)
    {
        preprev = prev;
        prev = temp;
        temp = temp->next;
    }
    if (preprev == nullptr)
    {
        head = prev->next;
    }
    else
    {
        preprev->next = prev->next;
    }
    val = prev->data;
    delete prev;
    prev = nullptr;
    return true;
}
// Task 5 implementation
int LinkedList::countNodes()
{
    int total = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        total++;
    }
    return total;
}
int LinkedList::findMin()
{
    if (head == nullptr)
    {
        return 999;
    }
    int min = head->data;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
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
// Driver task 1
void driverTask1()
{
    cout<<"Driver Task 1"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"Test 1"<<endl;
    LinkedList list;
    list.insertAtEnd(4);
    list.insertAtEnd(2);
    list.insertAtEnd(8);
    list.insertAtEnd(1);
    list.insertAtEnd(9);
    list.insertAtEnd(5);
    list.insertAtEnd(4);
    list.insertAtEnd(6);
    list.display();
    int val = 0;
    list.removeKthNode(4, val);
    list.display();
    cout<<"Value removed: "<<val<<endl;
    cout<<"Test 2 removing the first node"<<endl;
    list.removeKthNode(1, val);
    list.display();
    cout<<"Value removed: "<<val<<endl;
    cout<<"Test 3 removing the last node"<<endl;
    list.removeKthNode(6, val);
    list.display();
    cout<<"Value removed: "<<val<<endl;
    cout<<"-------------------------------------------"<<endl;
}
// Driver Task 2
void driverTask2()
{
    cout<<"Driver Task 2"<<endl;
    cout<<"-----------------------------------------"<<endl;
    // Test 1
    cout<<"Test 1"<<endl;
    LinkedList list;
    list.insertAtEnd(7);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(2);
    LinkedList list2;
    cout<<"List 1: ";
    list.display();
    list2.insertAtEnd(5);
    list2.insertAtEnd(9);
    cout<<"List 2: ";
    list2.display();
    LinkedList list3;
    list3.combine(list, list2);
    cout<<"Combined List: ";
    list3.display();

    // Test 2
    cout<<"Test 2"<<endl;
    LinkedList list4;
    LinkedList list5;
    list5.insertAtEnd(7);
    list5.insertAtEnd(3);
    list5.insertAtEnd(4);
    list5.insertAtEnd(2);
    cout<<"List 4: ";
    list4.display();
    cout<<"List 5: ";
    list5.display();
    LinkedList list6;
    list6.combine(list4, list5);
    cout<<"Combined List: ";
    list6.display();
    cout<<"-----------------------------------------"<<endl;
}
void driverTask3()
{
    cout<<"Driver Task 3"<<endl;
    cout<<"-----------------------------------------"<<endl;
    // Test 1
    cout<<"Test 1"<<endl;
    LinkedList list;
    list.insertAtEnd(7);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(2);
    cout<<"List 1: ";
    list.display();
    LinkedList list2;
    list2.insertAtEnd(5);
    list2.insertAtEnd(9);
    list2.insertAtEnd(1);
    list2.insertAtEnd(6);
    cout<<"List 2: ";
    list2.display();
    LinkedList list3;
    list3.shuffleMerge(list, list2);
    cout<<"Shuffled Merged List: ";
    list3.display();
    // Test 2
    cout<<"Test 2"<<endl;
    LinkedList list4;
    LinkedList list5;
    list4.insertAtEnd(8);
    list5.insertAtEnd(7);
    cout<<"List 4: ";
    list4.display();
    cout<<"List 5: ";
    list5.display();
    LinkedList list6;
    list6.shuffleMerge(list4, list5);
    cout<<"Shuffled Merged List: ";
    list6.display();

    cout<<"-----------------------------------------"<<endl;
}
void driverTask4()
{
    cout<<"Driver Task 4"<<endl;
    cout<<"-----------------------------------------"<<endl;
    // Test 1
    cout<<"Test 1"<<endl;
    LinkedList list;
    list.insertAtEnd(7);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(2);
    int val = 0;
    list.removeLastNode(val);
    cout<<"Value removed: "<<val<<endl;
    list.display();
    list.removeSecondLastNode(val);
    cout<<"Value removed: "<<val<<endl;
    list.display();

    // Test 2
    cout<<"Test 2"<<endl;
    LinkedList list2;
    list2.insertAtEnd(5);
    list2.removeLastNode(val);
    cout<<"Value removed: "<<val<<endl;
    
    // Test 3
    cout<<"Test 3"<<endl;
    LinkedList list3;
    list3.insertAtEnd(8);
    list3.insertAtEnd(7);
    list3.removeSecondLastNode(val);
    cout<<"Value removed: "<<val<<endl;
    list3.display();
    cout<<"-----------------------------------------"<<endl;
}
void driverTask5()
{
    cout<<"Driver Task 5"<<endl;
    cout<<"-----------------------------------------"<<endl;
    // Test 1
    cout<<"Test 1"<<endl;
    LinkedList list;
    list.insertAtEnd(7);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(2);
    cout<<"Total nodes: "<<list.countNodes()<<endl;
    cout<<"Minimum value: "<<list.findMin()<<endl;
    cout<<"Maximum value: "<<list.findMax()<<endl;

    // Test 2
    cout<<"Test 2"<<endl;
    LinkedList list2;
    cout<<"Total nodes: "<<list2.countNodes()<<endl;
    cout<<"Minimum value: "<<list2.findMin()<<endl;
    cout<<"Maximum value: "<<list2.findMax()<<endl;

    // Test 3
    cout<<"Test 3"<<endl;
    LinkedList list3;
    list3.insertAtEnd(8);
    list3.insertAtEnd(7);
    list3.insertAtEnd(9);
    cout<<"Total nodes: "<<list3.countNodes()<<endl;
    cout<<"Minimum value: "<<list3.findMin()<<endl; 
    cout<<"Maximum value: "<<list3.findMax()<<endl;
    cout<<"-----------------------------------------"<<endl;
}
int main()
{
    driverTask1();
    driverTask2();
    driverTask3();
    driverTask4();
    driverTask5();
    return 0;
}