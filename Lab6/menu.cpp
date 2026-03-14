#include "Deque.h"
#include "Deque.cpp"
#include <iostream>
using namespace std;
int main()
{
    Deque wah(4);
    int val = 0;
    int choice = -1;
    while (choice != 7)
    {
        cout << "1.Enter a value to insert at front" << endl;
        cout << "2. Insert value at Back" << endl;
        cout << "3. Remove value from Front " << endl;
        cout << "4. Remove value from Back" << endl;
        cout << "5. Display the deque" << endl;
        cout << "6. Make the deque empty" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the value to insert" << endl;
            cin >> val;
            if (wah.insertAtFront(val))
            {
                cout << "Insert successful" << endl;
            }
            else
            {
                cout << "Deque full" << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "Enter the value to insert" << endl;
            cin >> val;
            if (wah.insertAtBack(val))
            {
                cout << "Insert successful" << endl;
            }
            else
            {
                cout << "Deque full" << endl;
            }
        }
        else if (choice == 3)
        {
            if (wah.removeFromFront(val))
            {
                cout << "Following value is removed " << val << endl;
            }
            else
            {
                cout << "Removing value unsuccessful" << endl;
            }
        }
        else if(choice == 4){
            if (wah.removeFromBack(val))
            {
                cout << "Following value is removed " << val << endl;
            }
            else
            {
                cout << "Removing value unsuccessful" << endl;
            }
        }
        else if(choice == 5){
            wah.display();
        }
        else if(choice == 6){
            wah.makeEmpty();
        }
    }
}