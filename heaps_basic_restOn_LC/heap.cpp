#include<bits/stdc++.h>
using namespace std;
class maxHeap{
    public:
    vector<int> v;
    int size;
    int totalSize;
    maxHeap(int cap){
        v.resize(cap);
        size = 0;
        totalSize = cap;
    }

    void insert(int data){
        if(size==totalSize){
            cout<<"Heap Full"<<endl;
            return;
        }
        v[size] = data;
        int index = size;
        size++; 

        while(index>0 and v[index]>v[(index-1)/2]){ //in heap we always insert ele from left to right also for maxHeap child nodes must be smaller than parent node [if child node index is i than parent node index is (i-1)/2]
            swap(v[index],v[(index-1)/2]);          //v[index]<v[(index-1)/2]   => checking is child node value greater than parent node value, if it is so than swap
            index = (index-1)/2;         
        }
    }

    void heapify(int index){
        int largest = index;
        int leftIdx = 2*index+1;
        int rightIdx = 2*index+2;

        if(leftIdx<size and v[largest]<v[leftIdx]) largest = leftIdx;
        if(rightIdx<size and v[largest]<v[rightIdx]) largest = rightIdx;

        if(largest!=index){ //value of largest changes ?  => means it was smaller than its child
            swap(v[index],v[largest]);
            heapify(largest);
        }
    }

    void del(){ //delition in heap means deleting the first ele of array or deleting the root node of a tree
        if(size==0) {
            printf("Heap is Empty\n");
            return;
        }
        v[0] = v[size-1];
        size--;
        if(size==0) return;
        heapify(0); //is the process of picking the very first node and inserting it to its correct position so that property of heap remains intact
    }

    void print(){
        for(int i=0; i<size; i++){
            cout<<v[i]<<" ";
        }cout<<endl;
    }
};

int main(){
    maxHeap h1(6);
    h1.del();
    h1.insert(1);
    h1.insert(30);
    h1.insert(42);
    h1.insert(9);
    h1.insert(20);
    h1.insert(12);
    h1.print();
    h1.del();
    h1.print();
    return 0;
}