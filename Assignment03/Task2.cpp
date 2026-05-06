/*Name : Ali Haider
Roll No : BITF24M004
Morning Section
*/
#include <iostream>
#include <sstream>
using namespace std;
class CDLLD;
class DNode
{
    friend class CDLLD;

private:
    int data;
    DNode *next;
    DNode *prev;
};
class CDLLD
{
private:
    DNode head; // Dummy header node
    static bool swapAdjacent(DNode *n1, DNode *n2);

public:
    CDLLD();
    // Default constructor
    ~CDLLD(); // Destructor
    bool insertAtStart(int val);
    bool insertAtEnd(int val);
    void display();
    int countNodes();
    bool search(int val);
    bool unsortedRemove(int val);
    void bubbleSort();
};
CDLLD::CDLLD()
{
    head.next = &head;
    head.prev = &head;
}
CDLLD::~CDLLD()
{
    DNode *current = head.next;
    while (current != &head)
    {
        DNode *temp = current;
        current = current->next;
        delete temp;
    }
    head.next = &head;
    head.prev = &head;
}
bool CDLLD::insertAtStart(int val)
{
    //inserting at the start infront of the first node
    DNode *newNode = new DNode;
    newNode->data = val;

    newNode->next = head.next;
    newNode->prev = &head;

    head.next->prev = newNode;
    head.next = newNode;
    return true;
}
bool CDLLD::insertAtEnd(int val)
{
    //inserting at the end after the last node
    DNode *newNode = new DNode;
    newNode->data = val;

    newNode->next = &head;
    newNode->prev = head.prev;

    head.prev->next = newNode;
    head.prev = newNode;
    return true;
}
void CDLLD::display()
{
    DNode *curr = head.next;

    while (curr != &head)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int CDLLD::countNodes()
{
    DNode *curr = head.next;

    int totalNodes = 0;
    while (curr != &head)
    {
        curr = curr->next;
        totalNodes++;
    }
    return totalNodes;
}
bool CDLLD::search(int val)
{
    DNode *curr = head.next;

    while (curr != &head && curr->data != val)
    {
        curr = curr->next;
    }
    if (curr == &head)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool CDLLD::unsortedRemove(int val)
{
    DNode *curr = head.next;

    while (curr != &head && curr->data != val)
    {
        curr = curr->next;
    }
    if (curr == &head)
    {
        return false;
    }
    else
    {
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        delete curr;
        curr = nullptr;
        return true;
    }
}
bool CDLLD::swapAdjacent(DNode *n1, DNode *n2)
{
    // if n1 and n2 are not adjacent return false
    if (n1->prev != n2 && n1->next != n2)
    {
        return false;
    }
    else
    {
        //swapping the nodes by changing the links
        DNode *backward;
        DNode *forward;
        if (n1->prev == n2)
        {
            // if n2 is before n1 then the links backward is n2's prev and forward is n1's next
            backward = n2->prev;
            forward = n1->next;

            n1->prev = backward;
            backward->next = n1;

            n2->next = forward;
            forward->prev = n2;

            n1->next = n2;
            n2->prev = n1;
        }
        else
        {
            // if n1 is before n2 then the links backward is n1's prev and forward is n2's next
            backward = n1->prev;
            forward = n2->next;

            n2->prev = backward;
            backward->next = n2;

            n1->next = forward;
            forward->prev = n1;

            n2->next = n1;
            n1->prev = n2;
        }
        return true;
    }
}
void CDLLD::bubbleSort()
{
    // counting total nodes and then using the loops to compare the adjacent nodes 
    //and swapping them if they are in wrong order until the whole list is sorted
    DNode *first = head.next;

    int total = countNodes();

    for (int i = total - 1; i > 0; i--)
    {
        DNode *second = head.next;
        for (int j = 0; j < i; j++)
        {
            //if the current node's data is greater than the next node's data swap them
            if (second->data > second->next->data)
            {
                swapAdjacent(second, second->next);
            }
            else
            {
                //else move to the next node
                second = second->next;
            }
        }
    }
}
int main()
{
    CDLLD list;
    int choice;

    cout << "\t 1. Insert at Start" << endl;
    cout << "\t 2. Insert at End" << endl;
    cout << "\t 3. Remove a value" << endl;
    cout << "\t 4. Search a value" << endl;
    cout << "\t 5. Display the Linked List" << endl;
    cout << "\t 6. Count Nodes" << endl;
    cout << "\t 7. Sort the Linked List (using Bubble sort)" << endl;
    cout << "\t 8. Exit" << endl;

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string line;
            cout << "Enter the values to be inserted at start: ";
            cin.ignore();
            getline(cin, line); // Read whole line containing multiple integers separated by spaces

            stringstream ss(line);

            int num;

            while (ss >> num) {

                list.insertAtStart(num);
            }
        }
        else if (choice == 2)
        {
            cout << "Enter the values to be inserted at end: ";
            string line;
            cin.ignore();
            getline(cin, line); // Read whole line containing multiple integers separated by spaces

            stringstream ss(line);

            int num;

            while (ss >> num) {

                list.insertAtEnd(num);
            }
        }
        else if (choice == 3)
        {
            cout << "Enter the value to be removed: ";
            int val;
            cin >> val;
            if (list.unsortedRemove(val))
            {
                cout << val << " has been removed from the list" << endl;
            }
            else
            {
                cout << "Error: " << val << " is not found in the linked list" << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "Enter the value to be searched: ";
            int val;
            cin >> val;
            if (list.search(val))
            {
                cout << "The number " << val << " is present in the linked list" << endl;
            }
            else
            {
                cout << "Error: " << val << " is not found in the linked list" << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "The list contains: ";
            list.display();
        }
        else if (choice == 6)
        {
            cout << "Total nodes in the list: " << list.countNodes() << endl;
        }
        else if (choice == 7)
        {
            list.bubbleSort();
            cout << "The list has been sorted!" << endl;
            cout << "The list contains: ";
            list.display();
        }
        else if (choice == 8)
        {
            cout << "Bye bye!!" << endl;
        }
        else
        {
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}