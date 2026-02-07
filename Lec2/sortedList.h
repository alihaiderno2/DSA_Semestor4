# pragma once
class sortedList{
    private:
        int *arr;
        int maxSize;
        int currSize;
    public:
        sortedList(int);
        ~sortedList();
        bool insert(int val);
        bool isFull()const;
        bool isEmpty()const;
        void display()const;
        bool remove2(int index,int& val);// to remove value at index and also preserving the order of
        //remaining elements
        bool operator==(const sortedList& rhs);
        int removeAll2(int val);//remove all elements by value and preserve their order and return their total count 
        int removeAll3(int val);
        bool search(int );
        void merge(const sortedList& list2);
        // Task1
        bool replace(int , int);
        // Task3
        bool binarySearch(int );
        int removeAll(int );
        sortedList(const sortedList& rhs);
        sortedList& operator=(const sortedList& rhs);
};