/*Name :Ali Haider
Roll Number : BITF24M004
Section : Morning*/
# include <iostream>
# include "UnsortedList.cpp"
# include "UnsortedList.h"
using namespace std;
int main (){
    UnsortedList list1(10);
    UnsortedList list2(5);
    for(int i=0;i<10;i++){
        list1.insert(i);
    }
    for(int j=0;j<5;j++){
        list2.insert(j);
    }
    // Testing the intersection function here of UnsortedList
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