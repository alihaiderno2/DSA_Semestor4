# include "unsortedList.h"
# include "unsortedList.cpp"
# include<iostream>
using namespace std;
int main(){
    unsortedList list(4);
    for(int i=0;!(list.isFull());i++){
        int val;
        cin>>val;
        list.insert(val);
    }
    unsortedList list2(2);
    for(int i=0;!(list2.isFull());i++){
        int val;
        cin>>val;
        list2.insert(val);
    }
    list.combineList(list2);
    list.display();
}