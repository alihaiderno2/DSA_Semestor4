#include <iostream>
#include "LinkedList.h"
#include "CDLLD.h"
#include "LinkedList.cpp"
#include "CDLLD.cpp"
#include "Node.h"
#include "Node.cpp"
#include "DNode.h"
#include "DNode.cpp"

using namespace std;

void printHeader(string title) {
    cout << "\n========================================" << endl;
    cout << "   " << title << endl;
    cout << "========================================" << endl;
}

void testSinglyLinkedList() {
    printHeader("TESTING SINGLY LINKED LIST");

    LinkedList list;
    
    cout << "1. Insertions & Display:\n";
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtStart(5);
    list.sortedInsert(15);
    cout << "Expected: 5 10 15 20\nActual:   ";
    list.display();

    cout << "\n2. Search, Max, Min:\n";
    cout << "Search 15 (Expected 1): " << list.search(15) << endl;
    cout << "Search 99 (Expected 0): " << list.search(99) << endl;
    cout << "Max (Expected 20): " << list.findMax() << endl;
    cout << "Min (Expected 5): " << list.findMin() << "  <-- (Will be 999 if bug isn't fixed!)" << endl;

    cout << "\n3. Removals:\n";
    list.unsortedRemove(10);
    list.sortedRemove(20);
    cout << "After removing 10 and 20 (Expected: 5 15)\nActual:   ";
    list.display();

    cout << "\n4. Remove All:\n";
    list.insertAtEnd(7);
    list.insertAtEnd(7);
    list.insertAtStart(7);
    cout << "List before removeAll(7): "; list.display();
    int removed = list.removeAll(7);
    cout << "Removed " << removed << " sevens. (Expected: 5 15)\nActual:   ";
    list.display();

    cout << "\n5. Display Reverse vs Actual Reverse:\n";
    cout << "Display Reverse (Expected: 15 5): "; 
    list.displayReverse(); 
    cout << "\nList shouldn't be changed: "; list.display();
    list.reverse();
    cout << "Actual Reverse (Expected: 15 5): "; list.display();

    cout << "\n6. Merge Sort:\n";
    LinkedList sortList;
    sortList.insertAtEnd(4); sortList.insertAtEnd(1); sortList.insertAtEnd(8); sortList.insertAtEnd(3);
    cout << "Before Sort: "; sortList.display();
    sortList.mergeSort();
    cout << "After Sort:  "; sortList.display();

    cout << "\n7. Sum:\n";
    LinkedList num1, num2, sumList;
    num1.insertAtEnd(9); num1.insertAtEnd(9); // 99
    num2.insertAtEnd(1);                      // +1
    sumList.sum(num1, num2);
    cout << "99 + 1 (Expected: 1 0 0)\nActual:   "; 
    sumList.display();
}

void testCircularDoublyLinkedList() {
    printHeader("TESTING CIRCULAR DOUBLY LINKED LIST");

    CDLLD clist;

    cout << "1. Insertions & Display:\n";
    clist.insertAtEnd(20);
    clist.insertAtEnd(30);
    clist.insertAtStart(10);
    cout << "Expected: 10 20 30\nActual:   ";
    clist.display();

    cout << "\n2. Sorted Operations & isSorted:\n";
    clist.sortedInsert(25);
    cout << "After Sorted Insert 25 (Expected: 10 20 25 30)\nActual:   ";
    clist.display();
    cout << "Is Sorted? (Expected 1): " << clist.isSorted() << endl;

    cout << "\n3. Various Removals:\n";
    int val = 0;
    clist.removeAtStart();       // Removes 10
    clist.removeAtEnd();         // Removes 30
    clist.removeByVal(25);       // Removes 25
    cout << "After Start/End/Val removals (Expected: 20)\nActual:   ";
    clist.display();

    clist.insertAtEnd(40); clist.insertAtEnd(50); clist.insertAtEnd(60); 
    // List is now: 20 40 50 60
    clist.removeSecondLastNode(val); // Removes 50
    cout << "Removed Second Last (50): " << val << endl;
    clist.removeLastNode(val);       // Removes 60
    cout << "Removed Last (60): " << val << endl;
    
    // List is now: 20 40
    clist.removeKthNode(2, val);     // Removes 40
    cout << "Removed 2nd Node (40): " << val << endl;
    cout << "Final List (Expected: 20)\nActual:   ";
    clist.display();

    cout << "\n4. Reverse:\n";
    clist.insertAtEnd(30); clist.insertAtEnd(40);
    cout << "Before reverse: "; clist.display();
    clist.reverse();
    cout << "After reverse (Expected: 40 30 20)\nActual:   "; clist.display();

    cout << "\n5. Split List:\n";
    CDLLD left, right;
    clist.splitList(left, right);
    cout << "Original List (Expected empty): "; clist.display();
    cout << "Left Half (Expected: 40 30): "; left.display();
    cout << "Right Half (Expected: 20): "; right.display();

    cout << "\n6. Combine:\n";
    CDLLD combined;
    combined.combine(left, right);
    cout << "Combined Left & Right (Expected: 40 30 20)\nActual:   ";
    combined.display();

    cout << "\n7. Shuffle Merge (Equal Lengths):\n";
    CDLLD l1, l2, shuffled;
    l1.insertAtEnd(1); l1.insertAtEnd(3);
    l2.insertAtEnd(2); l2.insertAtEnd(4);
    shuffled.shuffleMerge(l1, l2);
    cout << "Shuffled [1,3] and [2,4] (Expected: 1 2 3 4)\nActual:   ";
    shuffled.display();
}

int main() {
    testSinglyLinkedList();
    testCircularDoublyLinkedList();
    
    cout << "\n\nAll tests completed successfully!\n";
    return 0;
}