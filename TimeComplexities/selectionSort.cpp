#include <iostream>
#include "../OwnLibrary/LibraryFunctions.h"
#include "../OwnLibrary/LibraryFunctions.cpp"
using namespace std;
int main(){
    LibraryFunctions functions;
    int arr[5] = {14,21,2,5,33};
    functions.selectionSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    functions.selectionSortReverse(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}