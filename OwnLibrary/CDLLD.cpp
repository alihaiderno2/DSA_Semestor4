# include "CDLLD.h"
# include <iostream>
using namespace std;
CDLLD::CDLLD(){
    head.next = &head;
    head.prev = &head;
}
void CDLLD::display(DNode* curr){
    if(curr == &head){
        return;
        cout<<endl;
    }
    else{
        cout<<curr->data<<" ";
        display(curr->next);
    }
}
void CDLLD::display(){
    display(head.next);
}
bool CDLLD::insertAtStart(int val){
    DNode* newNode = new DNode();
    newNode->data = val;

    newNode->next = head.next;

    head.next = newNode;

    newNode->prev = &head;
    newNode->next->prev = newNode;

    return true;
}
bool CDLLD::insertAtEnd(int val){
    DNode* newNode = new DNode();
    newNode->data = val;

    newNode->prev = head.prev;
    newNode->next = &head;

    newNode->prev->next = newNode;
    head.prev = newNode;

    return true;
}
CDLLD::CDLLD(CDLLD& orig){
    head.next = &head;
    head.prev = &head;

    DNode* temp = &head;
    DNode* curr = orig.head.next;
    while(curr != &orig.head){
        DNode* newNode = new DNode();
        newNode->data = curr->data;
        //to point to the head of the new list by the newNode's next pointer
        newNode->next = temp->next;
        temp->next = newNode;

        //similarly to point to the head of the new list by the newNode's prev pointer
        newNode->prev = temp;
        newNode->next->prev = newNode;
        
        temp = temp->next;
        curr = curr->next;
    }
}
CDLLD::~CDLLD(){
    DNode* temp = head.next;
    while(temp != &head){
        DNode* temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
}
bool CDLLD::removeByVal(int val){
    DNode* curr = head.next;
    while(curr != &head ){
        if(curr->data == val){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            curr = nullptr;
            return true;
        }
        curr= curr->next;
    }
    return false;
}
bool CDLLD::removeAtStart(){
    if(head.next == &head){
        return false;
    }
    DNode* temp = head.next;
    head.next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    temp = nullptr;
    return true;
}
bool CDLLD::removeAtEnd(){
    if(head.next == &head){
        return false;
    }
    DNode* curr = head.prev;
    head.prev = curr->prev;
    curr->prev->next = &head;

    delete curr;
    curr = nullptr;
    return true;
}
bool CDLLD::sortedInsert(int val){
    DNode* newNode = new DNode();
    newNode->data = val;
    DNode* curr = head.next;
    while(curr !=&head && curr->data < val){
        curr = curr->next;
    }
    newNode->prev = curr->prev;
    newNode->next = curr;

    newNode->prev->next = newNode;
    curr->prev = newNode;

    return true;
}
bool CDLLD::sortedRemove(int val){
    DNode* curr = head.next;
    while(curr != &head && curr->data < val){
        curr = curr->next;
    }
    if(curr != &head && curr->data == val){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        delete curr;
        curr = nullptr;
        return true;
    }
    else{
        return false;
    }
}
void CDLLD::combine(CDLLD& list1, CDLLD& list2){

    if(list1.head.next == &list1.head && list2.head.next == &list2.head){
        return;
    }
    else if(list1.head.next == &list1.head){
        head.next = list2.head.next;
        head.prev = list2.head.prev;
        list2.head.prev->next = &head;
        list2.head.next->prev = &head;

        list2.head.next = &list2.head;
        list2.head.prev = &list2.head;
    }
    else if (list2.head.next == &list2.head){
        head.next = list1.head.next;
        head.prev = list1.head.prev;
        list1.head.prev->next = &head;
        list1.head.next->prev = &head;

        list1.head.next = &list1.head;
        list1.head.prev = &list1.head;
    }
    else{
        // Pointing the head to the list1's first element
        head.next = list1.head.next;
        list1.head.next ->prev = &head;
        // Pointing the list1's last element to the list2's first element
        list1.head.prev->next = list2.head.next;
        list2.head.next->prev = list1.head.prev;
        // Pointing the very last node of list2 to the head
        list2.head.prev->next = &head;
        head.prev = list2.head.prev;

        // pointing the heads back to the head
        list1.head.next = &list1.head;
        list1.head.prev = &list1.head;
        list2.head.next = &list2.head;
        list2.head.prev = &list2.head;

    }
}
CDLLD& CDLLD::operator=(CDLLD& orig){
    if(this == &orig){
        return *this;
    }
    DNode* temp = head.next;
    while(temp != &head){
        DNode* temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
    head.next = &head;
    head.prev = &head;

    temp = &head;
    DNode* curr = orig.head.next;
    while(curr != &orig.head){
        DNode* newNode = new DNode();
        newNode->data = curr->data;

        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
        curr = curr->next;
    }
    temp->next = &head;
    head.prev = temp;
    return *this;
}
