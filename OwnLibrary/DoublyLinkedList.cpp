# include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};
class DoublyLinkedList{
    private:
    Node* head;
    Node* tail;
    int size;
    public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    bool insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
        return true;
    }
    bool insertAtTail(int val){
        Node* newNode = new Node(val);
        if(tail == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
        return true;
    }
    bool removeAll(int val){
        if(head == nullptr){
            return false;
        }
        Node* curr = head;
        while(head != nullptr && head->data == val){
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
        curr = head;
        while(curr != nullptr){
            if(curr->data == val){
                Node* temp = curr;
                curr = curr->next;
                temp->prev->next = temp->next;
                if(temp->next != nullptr){
                    temp->next->prev = temp->prev;
                }
                else{
                    tail = temp->prev;
                }
                delete temp;
                size--;
            }
        }
    }
};