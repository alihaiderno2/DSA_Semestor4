# include <iostream>
# include "CDLLD.h"
# include "CDLLD.cpp"
# include "DNode.h"
# include "DNode.cpp"
using namespace std;
int main(){
    CDLLD list1;
    list1.insertAtStart(3);
    list1.insertAtStart(5);
    list1.insertAtEnd(4);
    list1.insertAtStart(7);
    list1.insertAtStart(9);
    list1.insertAtEnd(4);
    list1.removeByVal(3);
    list1.display();
    CDLLD list2(list1);
    list2.display();
}