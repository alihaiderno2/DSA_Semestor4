# include <iostream>
# include "SortedList.h"
# include "SortedList.cpp"
#include "LibraryFunctions.h"
# include "LibraryFunctions.cpp"
# include "Stack.cpp"
# include "Stack.h"
# include "StackChar.cpp"
# include "StackChar.h"
# include "StackString.cpp"
# include "StackString.h"
# include "LinkedList.h"
# include "LinkedList.cpp"
# include "Node.h"
# include "Node.cpp"
using namespace std;
using namespace std;

int main() {
    cout << "--- 1. Testing Basic Insertions & Display ---" << endl;
    LinkedList list1;
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtStart(5);
    list1.insertAtEnd(30);
    
    cout << "List 1 (Expected: 5 10 20 30): ";
    list1.display();
    cout << endl;

    cout << "\n--- 2. Testing Max & Search ---" << endl;
    cout << "Max value (Expected: 30): " << list1.findMax() << endl;
    cout << "Searching for 20 (Expected: 1/true): " << list1.search(20) << endl;
    cout << "Searching for 99 (Expected: 0/false): " << list1.search(99) << endl;

    cout << "\n--- 3. Testing Reverse Display ---" << endl;
    cout << "Reversed List 1 (Expected: 30 20 10 5): ";
    list1.displayReverse(); 
    cout << endl;
    cout << "List 1 restored? (Expected: 5 10 20 30): ";
    list1.display();
    cout << endl;

    cout << "\n--- 4. Testing Unsorted Removal ---" << endl;
    list1.unsortedRemove(20); // Remove middle
    list1.unsortedRemove(5);  // Remove head
    cout << "After removing 20 and 5 (Expected: 10 30): ";
    list1.display();
    cout << endl;

    cout << "\n--- 5. Testing Sorted Insert & Sorted Remove ---" << endl;
    LinkedList sortedList;
    sortedList.sortedInsert(15);
    sortedList.sortedInsert(5);
    sortedList.sortedInsert(25);
    sortedList.sortedInsert(10);
    
    cout << "Sorted List (Expected: 5 10 15 25): ";
    sortedList.display();
    cout << endl;
    
    sortedList.sortedRemove(10);
    cout << "After sortedRemove(10) (Expected: 5 15 25): ";
    sortedList.display();
    cout << endl;

    cout << "\n--- 6. Testing Rule of Three (Memory Management) ---" << endl;
    // Test Copy Constructor
    LinkedList copiedList = sortedList; 
    cout << "Copied List (Expected: 5 15 25): ";
    copiedList.display();
    cout << endl;

    // Test Assignment Operator
    LinkedList assignedList;
    assignedList.insertAtStart(999); // Put something in it first
    assignedList = list1;            // Should wipe 999 and replace with list1
    
    cout << "Assigned List (Expected: 10 30): ";
    assignedList.display();
    cout << endl;

    cout << "\nAll tests completed! Destructors will now fire to clean up memory." << endl;
    return 0;
}