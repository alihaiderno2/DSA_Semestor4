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
};