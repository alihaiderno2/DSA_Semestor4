# pragma once
class SortedList{
    private:
        int *arr;
        int maxSize;
        int currSize;
    public:
        SortedList(int);
        ~SortedList();
        bool insert(int val);
        bool isFull()const;
        bool isEmpty()const;
        void display()const;
        bool remove2(int index,int& val);// to remove value at index and also preserving the order of
        //remaining elements
        bool operator==(const SortedList& rhs);
        int removeAll2(int val);//remove all elements by value and preserve their order and return their total count 
        int removeAll3(int val);
        bool search(int );
        void merge(const SortedList& list2);
        // Task1
        bool replace(int , int);
        // Task3
        bool binarySearch(int );
        int removeAll(int );
        SortedList(const SortedList& rhs);
        SortedList& operator=(const SortedList& rhs);
        SortedList intersection(const SortedList &list2) const;
        bool isSubset (const SortedList& list2) const;
        SortedList difference (const SortedList& list2) const; 
        SortedList Union (const SortedList& list2) const;
        int comparison(const SortedList& list2) const;
};