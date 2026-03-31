# pragma once
class LinkedList;
class LinkedStack;
class Node {
    friend class LinkedList;
    friend class LinkedStack;
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