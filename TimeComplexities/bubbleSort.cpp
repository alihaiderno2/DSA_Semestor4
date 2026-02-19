#include <iostream>
#include "../OwnLibrary/LibraryFunctions.h"
#include "../OwnLibrary/LibraryFunctions.cpp"
using namespace std;
int main(){
    LibraryFunctions functions;
    int arr[5] = {14,21,2,5,33};
    functions.bubbleSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    functions.bubbleSortReverse(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}