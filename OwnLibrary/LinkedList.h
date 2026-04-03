# pragma once
# include "Node.h"
class LinkedList
{
    private:
        Node* head;
    public:
        LinkedList();
        void display();
        void insertAtStart(int);
        void insertAtEnd(int );
        void sortedInsert(int);
        bool search(int);
        int findMax();
        void displayReverse();
        bool unsortedRemove(int);
        bool sortedRemove(int);
        ~LinkedList();
        LinkedList(LinkedList&);
        LinkedList& operator=(LinkedList& orig);
};