/*Name : Ali Haider
Roll No : BITF24M004
Morning Section
*/
#include <iostream>
#include <sstream>
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
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList();
    ~LinkedList();
    bool insert(int val);
    void display();
    bool unsortedRemove(int val);
    bool search(int val);
    void selectionSort();
    void reverse();
    void emptyList();
};
LinkedList::LinkedList()
{
    head = nullptr;
}
LinkedList::~LinkedList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = nullptr;
}
bool LinkedList::insert(int val)
{
    // inserts the value at head by newNode as head
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    return true;
}
void LinkedList::display()
{
    // display the list iteratively by moving from the head to nullptr
    int total = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        total++;
        temp = temp->next;
    }
    temp = head;
    if (total == 0)
    {
        cout << "The list is empty!" << endl;
        return;
    }
    cout << "The list contains following " << total << " elements: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
bool LinkedList::unsortedRemove(int val)
{
    //removes the node by bypassing the node
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr && temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }
    // If value is not found
    if (temp == nullptr)
    {
        return false;
    }
    // If head is to be removed
    if (prev == nullptr)
    {
        Node *temp1 = head;
        head = head->next;
        delete temp1;
        return true;
    }
    else
    {
        prev->next = temp->next;
        delete temp;
        temp = nullptr;
        return true;
    }
}
bool LinkedList::search(int val)
{
    //search the value from head to nullptr iteratively returnig true if found else false
    Node *temp = head;
    while (temp != nullptr && temp->data != val)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void LinkedList::selectionSort()
{
    //outer loop pointer
    Node *first = head;

    //Creating a new pointer to keep track of the new list being created by selection sort
    Node *newList = head;
    // as the first iteration sets the head keeping iter to keep track of the first iteration to set the head of the new list
    int iter = 0;
    while (first != nullptr)
    {
        //prev pointer and minPrev to keep track of previous to bypass the nodes
        Node *prev = first;
        Node *minPrev = nullptr;

        //inner loop pointer
        Node *second = first->next;
        //The initial minimun value
        int minVal = first->data;
        //The initial minimum node
        Node *minimum = first;

        while (second != nullptr)
        {
            //If a smaller value is found
            if (second->data < minVal)
            {
                minimum = second;
                minPrev = prev;
                minVal = second->data;
            }
            prev = second;
            second = second->next;
        }

        // For the very first iteration the head is set
        if (iter == 0)
        {
            //if the minimum is the first node
            if (minPrev == nullptr)
            {
                //head is set to first and moved ahead
                head = first;
                newList = first;
                first = first->next;
            }
            else
            {
                //if minimum is some other node the head is set to that
                head = minimum;
                minPrev->next = minimum->next;
                newList = minimum;
            }
            iter++;
        }
        else
        {
            //other iterations
            if (minPrev == nullptr)
            {
                //similarly if minimum is the first node the new list is connected to that
                newList->next = first;
                newList = newList->next;
                first = first->next;
            }
            else
            {
                //else to the minimum node
                minPrev->next = minimum->next;
                newList->next = minimum;
                newList = newList->next;
            }
        }
        minimum->next = nullptr;
    }
}
void LinkedList::reverse()
{
    //Simply  keeping track of previous and current and reversing the links 
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
void LinkedList::emptyList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = nullptr;
}
int main()
{

    LinkedList list;
    int choice;
    cout << "\t 1. Insert values" << endl;
    cout << "\t 2. Remove a value" << endl;
    cout << "\t 3. Search a value" << endl;
    cout << "\t 4. Display the Linked List" << endl;
    cout << "\t 5. Sort the Linked List(using Selection sort)" << endl;
    cout << "\t 6. Reverse the Linked List" << endl;
    cout << "\t 7. Empty the Linked List" << endl;
    cout << "\t 8. Exit" << endl;
    do
    {
        cout << endl
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the values to be inserted:";
            string line;
            cin.ignore();
            getline(cin, line); // Read whole line containing multiple integers separated by spaces

            stringstream ss(line);

            int num;

            while (ss >> num) {

                list.insert(num);
            }
        }
        else if (choice == 2)
        {
            cout << "Enter the value to be removed: ";
            int val;
            cin >> val;
            if (list.unsortedRemove(val) == true)
            {
                cout << val << " has been removed from the list" << endl;
            }
            else
            {
                cout << "Error: " << val << " is not found in the linked list" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Enter the value to be searched: ";
            int val;
            cin >> val;
            if (list.search(val) == true)
            {
                cout << "The number " << val << " is present in the linked list" << endl;
            }
            else
            {
                cout << "Error: " << val << " is not found in the linked list" << endl;
            }
        }
        else if (choice == 4)
        {
            list.display();
        }
        else if (choice == 5)
        {
            list.selectionSort();
            cout << "The list has been sorted!" << endl;
            list.display();
        }
        else if (choice == 6)
        {
            list.reverse();
            cout << "The list has been reversed!" << endl;
            list.display();
        }
        else if (choice == 7)
        {
            list.emptyList();
            cout << "All values have been removed from the Linked list" << endl;
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
