# pragma once
# include <iostream>
using namespace std;
class LibraryFunctions
{
    public:
        void intSwap(int &a, int &b);
        void bubbleSort(int* a, int n);
        void bubbleSortReverse(int* a, int n);
        void selectionSort(int* a,int n);
        void selectionSortReverse(int* a,int n);
        void selectionSortByFindMax(int* a,int n);
        void selectionSortByFindMin(int* a,int n);
        void insertionSort(int* a,int n);
        void insertionSortReverse(int* a,int n);
        void decimalToBinaryConversion(int num);
        int logBase2(int num);
        int evaluationOfPostfixExpression(const char* exp);
        string infixToPostfix(string);
        int getPrecedence(string op);
        void merge(int* arr,int l1,int l2,int r1,int r2);
        void mergeSort(int* arr,int start,int end);
};