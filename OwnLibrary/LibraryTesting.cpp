# include <iostream>
# include "SortedList.h"
# include "SortedList.cpp"
#include "LibraryFunctions.h"
# include "LibraryFunctions.cpp"
# include "Stack.cpp"
# include "Stack.h"
# include "StackChar.cpp"
# include "StackChar.h"
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
    LibraryFunctions lib;
    char ch[14] = "a+b*(c-d)>e+f";
    string infix = lib.infixToPostfix(ch);
    cout<<infix<<endl;
}