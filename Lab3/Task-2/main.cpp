/*Name :Ali Haider
Roll Number : BITF24M004
Section : Morning*/
#include <iostream>
# include "SortedList.cpp"
# include "SortedList.h"
using namespace std;
int main(){
    SortedList list1(5),list2(5);
    for(int i=0;i<5;i++){
        list1.insert(i);
    }
    cout<<"List 1: ";
    list1.display();
    for(int j=2;j<7;j++){
        list2.insert(j);
    }
    cout<<"List 1: ";
    list2.display();
    // Testing the intersection function here of UnsortedList
    SortedList list3 = list1.intersection(list2);
    cout<<"Intersection: ";
    list3.display();
}