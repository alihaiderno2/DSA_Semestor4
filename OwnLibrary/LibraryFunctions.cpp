#include "LibraryFunctions.h"
void LibraryFunctions::intSwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void LibraryFunctions::bubbleSort(int *a, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                intSwap(a[j], a[j + 1]);
            }
        }
    }
}
void LibraryFunctions::bubbleSortReverse(int *a, int n)
{
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]<a[j+1]){
                intSwap(a[j],a[j+1]);
            }
        }
    }
}
void LibraryFunctions::selectionSort(int* a,int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        intSwap(a[i],a[min]);
    }
}
void LibraryFunctions::selectionSortReverse(int* a,int n){
    for(int i=0;i<n-1;i++){
        int max = i;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[max]){
                max = j;
            }
        }
        intSwap(a[i],a[max]);
    }
}