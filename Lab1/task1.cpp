// # include "C:\Users\User\Desktop\Semestor04\Data_Structures\Lab\Lec1\unsortedList.cpp"
# include "UnsortedList.cpp"
# include <iostream>

# include "UnsortedList.h"
using namespace std;
int main(){
    UnsortedList list(6);
    for(int i=0;!(list.isFull());i++){
        int val;
        cin>>val;
        list.insert(val);
    }
    list.display();
    UnsortedList list2 = list;
    list2.removeAll4(2);
    list2.display();
}
