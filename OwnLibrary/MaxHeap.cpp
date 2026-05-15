# include <iostream>
using namespace std;
class MaxHeap
{
    private:
    int *h;
    int maxSize;
    int currSize;
    bool remove(int val);
public:
    MaxHeap(int size);
    ~MaxHeap();
    MaxHeap(const MaxHeap& other);
    MaxHeap& operator=(const MaxHeap& other);
    bool isFull();
    bool isEmpty();
    bool insert(int val);
    bool removeMax(int &val);
    void display();
    void Heapify(int i);
    void buildHeap(int* arr,int size);
    void heapSort();
    int search(int val);
};
MaxHeap::MaxHeap(int size)
{
    maxSize = size;
    currSize = 0;
    h = new int[maxSize + 1];
}
MaxHeap::~MaxHeap()
{
    delete[] h;
    h = nullptr;
}
MaxHeap::MaxHeap(const MaxHeap& other){
    int s = other.maxSize;
    h = new int[s];
    for(int i = 0; i < other.currSize; i++){
        h[i] = other.h[i];
    }
    maxSize = other.maxSize;
    currSize = other.currSize;
}
MaxHeap& MaxHeap::operator=(const MaxHeap& other){
    if(this == &other){
        return *this;
    }
    delete[] h;
    h = new int[other.maxSize];
    for(int i = 0; i < other.currSize; i++){
        h[i] = other.h[i];
    }
    maxSize = other.maxSize;
    currSize = other.currSize;
    return *this;
}
bool MaxHeap::isFull()
{
    return currSize == maxSize;
}
bool MaxHeap::isEmpty()
{
    return currSize == 0;
}
bool MaxHeap::insert(int val)
{
    if(isFull()){
        return false;
    }
    else{
        currSize++;
        int i = currSize ;
        while(i>1 && val > h[i/2]){
            h[i] = h[i/2];
            i = i/2;
        }
        h[i] = val;
        return true;
    }
}
bool MaxHeap::removeMax(int &val){
    if(isEmpty()){
        return false;
    }
    else {
        val = h[1];
        h[1] = h[currSize];
        currSize--;
        int i = 1,left, right,largest;
        bool flag = true;
        while(i*2<= currSize && flag){
            left = i*2;
            right = i*2 +1;
            largest  = i;
            if(left <= currSize && h[left] > h[largest]){
                largest = left;
            }
            if(right <= currSize && h[right] > h[largest]){
                largest = right;
            }
            if(i != largest){
                swap(h[i],h[largest]);
                i = largest;
            }
            else{
                flag = false;
            }
        }
        return true;
    }
}
void MaxHeap::display(){
    for(int i = 1; i <= currSize; i++){
        cout << h[i] << " ";
    }
    cout << endl;
}
void MaxHeap::Heapify(int i){
    if(i > currSize || i < 1){
        return;
    }
    bool flag = true;
    int left, right,largest;
    while(i*2<= currSize && flag){
        left = i*2;
        right = i*2 +1;
        largest  = i;
        if(left <= currSize && h[left] > h[largest]){
            largest = left;
        }
        if(right <= currSize && h[right] > h[largest]){
            largest = right;
        }
        if(i != largest){
            swap(h[i],h[largest]);
            i = largest;
        }
        else{
            flag = false;
        }
    }
}
void MaxHeap::buildHeap(int* arr, int size){
    if(size > maxSize){
        delete[] h;
        maxSize = size;
        h = new int[maxSize + 1];
    }
    for(int i = 0;i<size;i++){
        h[i+1] = arr[i];
    }
    currSize = size;

    for(int i = currSize/2; i>= 1;i--){
        Heapify(i);
    }
}

void MaxHeap::heapSort(){
    int origSize = currSize;
    for(int i = origSize; i>=1;i--){
        swap(h[1],h[i]);
        currSize--;
        Heapify(1);
    }
    currSize = origSize;
}
int MaxHeap::search(int val){
    for(int i = 1;i<= currSize;i++){
        if(h[i] == val){
            return i;
        }
    }
    return -1;
}
bool MaxHeap::remove(int val){
    int index = search(val);
    if(index == -1){
        return false;
    }
    else{
        int i = index,left ,right, largest;
        h[index] = h[currSize];
        currSize--;
        bool flag = true;
        while(i*2<= currSize && flag){
            left = i*2;
            right = i*2+1;
            largest = i;
            if(left <= currSize && h[left] > h[largest]){
                largest = left;
            }
            if(right<= currSize && h[right] > h[largest]){
                largest = right;
            }
            if(i != largest){
                swap(h[i],h[largest]);
                i = largest;
            }
            else{
                flag = false;
            }
        }
        return true;
    }
}
int main() {
    // 1. Create unsorted data
    int data[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    // 2. Initialize the heap (we allocate slightly more space just in case)
    MaxHeap myHeap(10);

    // 3. Build the heap in O(n) time
    myHeap.buildHeap(data, n);
    cout << "Max-Heap structure: ";
    myHeap.display(); // Expected: 13 11 12 5 6 7 

    // 4. Sort the heap in O(n log n) time
    myHeap.heapSort();
    cout << "Sorted Array:       ";
    myHeap.display(); // Expected: 5 6 7 11 12 13

    return 0;
}