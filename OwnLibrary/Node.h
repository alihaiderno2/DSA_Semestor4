# pragma once
class LinkedList;
class Node {
    friend class LinkedList;
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