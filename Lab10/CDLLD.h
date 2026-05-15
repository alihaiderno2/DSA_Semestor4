# pragma once
# include "DNode.h"
class CDLLD{
    private:
        DNode head;

        void display(DNode* curr);
    public:
        CDLLD();
        void display();
        bool insertAtStart(int val);
        bool insertAtEnd(int val);
        CDLLD(CDLLD& orig);
        ~CDLLD();
        bool removeByVal(int val);
        bool removeAtStart();
        bool removeAtEnd();
        bool sortedInsert(int val);
        bool sortedRemove(int val);
        void combine(CDLLD& list1, CDLLD& list2);
        CDLLD& operator=(CDLLD& orig);
        void shuffleMerge(CDLLD& list1, CDLLD& list2);
        void reverse();
        void splitList (CDLLD& leftHalf, CDLLD& rightHalf);
        bool isSorted() const;
        bool removeLastNode (int& val);
        bool removeSecondLastNode (int& val);
        bool removeKthNode (int k, int& val);
        bool merge (CDLLD& list1, CDLLD& list2);
        void mergeSort();
        void mergeSort(DNode* head);
        int countNodes(DNode* curr);
        int countNodes();
        void insertionSort();
        void selectionSort();
};