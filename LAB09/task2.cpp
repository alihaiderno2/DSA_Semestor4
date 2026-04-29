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
    lis1.insertAtStart(9);
    lis1.insertAtStart(8);
    lis1.insertAtStart(5);
    lis1.insertAtStart(4);
    lis1.insertAtStart(3);
    lis1.insertAtStart(2);
    lis1.insertAtStart(1);
    lis1.splitList(lis2,lis3);
    lis2.display();
    lis3.display();
    int val;
    lis2.removeSecondLastNode(val);
    cout<<val<<endl;
}