# include <iostream>
# include "SortedList.h"
# include "SortedList.cpp"
#include "LibraryFunctions.h"
# include "LibraryFunctions.cpp"
using namespace std;
int main(){
    // SortedList list1(6);
    // for(int i=0;i<5;i++){
    //     list1.insert(i);
    // }
    // list1.insert(4);
    // SortedList list2(6);
    // for(int i=3;i<9;i++){
    //     list1.insert(i);
    // }
    // SortedList temp = list1.Union(list2);
    // temp.display();
    int arr[7] = {1,5,2,8,3,5,2};
    LibraryFunctions lib;
    lib.insertionSortReverse(arr,7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<endl;
    }
}