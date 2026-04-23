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
        Node* mergeSort(Node* head);
        Node* getMiddle(Node* head);
        Node* merge(Node* left, Node* right);
        Node* getHead(){
            return head;
        }
        void setHead(Node* newHead){
            head = newHead;
        }
};