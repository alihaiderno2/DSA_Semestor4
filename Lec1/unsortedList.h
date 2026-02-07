# pragma once
class unsortedList{
    private:
        int* arr;
        int currSize;
        int maxSize;
    public:
        unsortedList(int val);
        ~unsortedList();
        bool isFull()const;
        bool isEmpty()const;
        void display()const;
        bool insert(int val);
        bool remove1(int index,int& val);//to remove value at index but by not preserving the order
        bool remove2(int index,int& val);// to remove value at index and also preserving the order of
        //remaining elements
        unsortedList(unsortedList& rhs);
        unsortedList& operator=(unsortedList& rhs);
        bool operator==(unsortedList& rhs)const;
        int removeAll1(int val);//remove all elements by value and return their total count
        int removeAll2(int val);//remove all elements by value and preserve their order and return their total count 
        int removeAll3(int val);
        int removeAll4(int val);
        bool search(int );
        // Task 2
        bool removeMax(int&);
        void reverse();
        void combineList(const unsortedList& list2);
        // Task4
        int replaceAll(int, int);
        bool removeLastOccurance(int );
        int removeAll(int val);
};