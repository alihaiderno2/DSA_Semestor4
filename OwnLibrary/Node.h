# pragma once
class LinkedList;
class LinkedStack;
class LinkedQueue;
class Node {
    friend class LinkedList;
    friend class LinkedStack;
    friend class LinkedQueue;
    private:
        int data;
        Node* next;
    public:
        Node();
        Node(int val);
        int getData();
        Node* getNext();
        void setNext(Node* nextNode);
};