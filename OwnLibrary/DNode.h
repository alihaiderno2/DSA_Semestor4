# pragma once
class DNode{
    friend class CDLLD;
    private:
        int data;
        DNode* next;
        DNode* prev;
    public:
    DNode();
};