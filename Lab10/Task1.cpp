# include <iostream>
#include "CDLLD.h"
#include "CDLLD.cpp"
#include "DNode.h"
#include"DNode.cpp"
using namespace std;
int main()
{
    CDLLD list1 ;
    CDLLD list2;
    CDLLD list;
    list1.insertAtStart(8);
    list1.insertAtStart(7);
    list1.insertAtStart(6);
    list1.insertAtStart(5);
    list2.insertAtStart(4);
    list2.insertAtStart(3);
    list2.insertAtStart(2);
    // list2.insertAtStart(1);
    list.merge(list1,list2);
    list.display();
    list.splitList(list1,list2);
    list1.display();
    list2.display();
    list.insertAtEnd(5);
    list.insertAtEnd(1);
    list.insertAtEnd(7);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    cout<<list.countNodes();
    list.mergeSort();
    list.display();
}