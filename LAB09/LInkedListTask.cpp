# include <iostream>
# include "LinkedList.h"
# include "LinkedList.cpp"
# include "Node.h"
# include "Node.cpp"
using namespace std;
int main(){
    LinkedList l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(1);
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(1);
    l1.insertAtEnd(1);
    l1.insertAtEnd(3);
    l1.insertAtEnd(0);
    int total;
    l1.removeAll(1);
    l1.display();
    int mini = l1.findMin();
    l1.display();
    cout<<mini;
}