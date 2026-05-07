# include <iostream>    
# include "BST.h"
# include "BST.cpp"
# include "LinkedQueueForBSTNode.h"
# include "LinkedQueueForBSTNode.cpp"
# include "BSTNode.h"
# include "BSTNode.cpp"
using namespace std;
int main(){
    BST bst;
    int choice, val;
    cout<<"1. Insert "<<endl;
        cout<<"2. Remove "<<endl;
        cout<<"3. Search "<<endl;
        cout<<"4. Display InOrder "<<endl;
        cout<<"5. Display PreOrder "<<endl;
        cout<<"6. Display PostOrder "<<endl;
        cout<<"7. Find Minimum "<<endl;
        cout<<"8. Find Maximum "<<endl;
        cout<<"9. Get Height "<<endl;
        cout<<"10. Exit "<<endl;
    do{
        cin>>choice;
        if(choice == 1){
            cout<<"Enter value to insert: ";
            cin>>val;
            bst.insert(val);
        }
        else if(choice == 2){
            cout<<"Enter value to remove: ";
            cin>>val;
            bool result = bst.remove(val);
            if(result){
                cout<<"Value removed from the BST."<<endl;
            }
            else{
                cout<<"Value not found in the BST."<<endl;
            }
        }
        else if(choice == 3){
            cout<<"Enter value to search: ";
            cin>>val;
            if(bst.Search(val)){
                cout<<"Value found in the BST."<<endl;
            }
            else{
                cout<<"Value not found in the BST."<<endl;
            }
        }
        else if(choice == 4){
            cout<<"InOrder Traversal: ";
            bst.displayInOrder();
        }
        else if(choice == 5){
            cout<<"PreOrder Traversal: ";
            bst.displayPreOrder();
        }
        else if(choice == 6){
            cout<<"PostOrder Traversal: ";
            bst.displayPostOrder();
        }
        else if(choice == 7){
            int minVal;
            if(bst.findMin(minVal)){
                cout<<"Minimum value in the BST is: "<<minVal<<endl;
            }
            else{
                cout<<"BST is empty."<<endl;
            }
        }
        else if(choice == 8){
            int maxVal;
            if(bst.findMax(maxVal)){
                cout<<"Maximum value in the BST is: "<<maxVal<<endl;
            }
            else{
                cout<<"BST is empty."<<endl;
            }
        }
        else if(choice == 9){
            int height = bst.getHeight();
            cout<<"Height of the BST is: "<<height<<endl;
        }
        else if(choice == 10){
            cout<<"Exiting..."<<endl;
        }
        else{
            cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    while(choice >= 1 && choice <= 9);
    return 0;
}