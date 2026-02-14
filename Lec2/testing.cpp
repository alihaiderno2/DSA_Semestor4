# include <iostream>
# include "SortedList.h"
# include "SortedList.cpp"
using namespace std;
int main(){
    SortedList list1(18);
    SortedList list2(5);
    for(int i=7;i<18;i++){
        list1.insert(i);
    }
    list1.display();
    for(int j = 3;j<8;j++){
        list2.insert(j);
    }
    list2.display();
    SortedList list3 = list1.Union(list2);
    list3.display();
}