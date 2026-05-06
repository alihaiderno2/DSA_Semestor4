# pragma once
# include "Node.h"
class LinkedList
{
    private:
        Node* head;
        int findMin(Node* curr);
        Node* mergeSort(Node* head);
        int countEvens(Node* curr);
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
        void mergeSort();
        Node* getMiddle(Node* head);
        Node* merge(Node* left, Node* right);
        Node* getHead(){
            return head;
        }
        void setHead(Node* newHead){
            head = newHead;
        }
        void sum(LinkedList& list1,LinkedList& list2);
        void reverse();
        int removeAll(int val);
        int findMin();
        int countEvens();
        void bubbleSort();
        int countNodes();
};