/*Name :Ali Haider
Roll Number : BITF24M004
Section : Morning*/
# include <iostream>
# include "SortedList.cpp"
# include "SortedList.h"
using namespace std;
int main (){
    SortedList list1(10);
    SortedList list2(5);
    for(int i=0;i<10;i++){
        list1.insert(i);
    }
    for(int j=0;j<5;j++){
        list2.insert(j);
    }
    // Testing the intersection function here of SortedList
    if(list2.isSubset(list1)){
        list2.display();
        cout<<"is subset of: ";
        list1.display();
    }
    else{
        list2.display();
        cout<<"is not subset of: ";
        list1.display();
    }
}