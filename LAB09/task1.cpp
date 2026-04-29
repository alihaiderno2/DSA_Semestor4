# include <iostream>
# include "CDLLD.h"
# include "CDLLD.cpp"
# include "DNode.h"
# include "DNode.cpp"
using namespace std;
int main(){
    CDLLD lis1;
    CDLLD lis2;
    CDLLD lis3;
    lis1.insertAtEnd(2);
    lis1.insertAtEnd(6);
    lis1.insertAtEnd(4);
    lis2.insertAtEnd(8);
    lis2.insertAtEnd(1);
    lis2.insertAtEnd(3);
    lis3.shuffleMerge(lis1,lis2);
    lis3.display();

    lis3.splitList(lis1,lis2);
    lis1.display();
    lis2.display();
}