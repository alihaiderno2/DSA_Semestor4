# include <iostream>
# include "sortedList.h"
# include "sortedList.cpp"
using namespace std;
int main(){
    sortedList list(64);
    for(int i=0;i<64;i++){
        list.insert(i);
    }
    list.binarySearch(99);
    list.display();
}