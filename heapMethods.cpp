//      for MaxHeap

#include<iostream>
#define n 100
using namespace std;
class heap{
public:
 int arr[n];
 int sum = 0;

// Insertion
    void insert(int val){
        sum = sum + 1;
        int sibling = sum;
        arr[sibling] = val;
        while(sibling>1){
          int parent = sibling/2;
          if(arr[sibling]>arr[parent]){
            int temp = arr[sibling];
            arr[sibling] = arr[parent];
            arr[parent] = temp;
            }
         else{
            return;
         }
        }
    }
    
// Deletion
    void deleteHeap(){
        if(sum==0){
            cout<<"Nothing to Delete"<<endl;
            return;
        }
        int i=1;

        int temp = arr[1];
        arr[1] = arr[sum];
        arr[sum] = temp;
        sum--;

        int parent = i;
        int leftChild = 2*i;
        int rightChild = 2*i + 1;


        while(sum>i){
         if(arr[leftChild]>arr[parent] and leftChild<sum){
            int temp = arr[leftChild];
            arr[leftChild] = arr[parent];
            arr[parent] = temp;
         }
         else if(arr[rightChild]>arr[parent] and rightChild<sum){
            int temp = arr[rightChild];
            arr[rightChild] = arr[parent];
            arr[parent] = temp;
         }
         else{
            return;
         }
        }
    }


     void print(){
        for(int i=1; i<=sum; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(int arr[], int m , int i){
        int root = i;
        int leftNode = 2*i;
        int rightNode = 2*i + 1;
        if(leftNode<=m and arr[leftNode]>arr[root]){
            // leftNode index > m(total no. of node) => overflow condition
            root=leftNode;
        }
        if(rightNode<=m and arr[rightNode]>arr[root]){
            root=rightNode;
        }
        if(root != i){
            int temp = arr[i];
            arr[i] = arr[root];
            arr[root] = temp;
            heapify(arr,m,root);
        }
    }


//Max heap diya rahega array me
void heapSort(int arr[] , int m){
    int size = m;
    while(size>1){
        int temp = arr[1];
        arr[1] = arr[size];
        arr[size] = temp;

        size--;

        heapify(arr,m,1);
    }
}

int main(){
heap h;
h.insert(50);
h.insert(55);
h.insert(53);
h.insert(52);
h.insert(54);
h.print();

cout<<endl;

h.deleteHeap();
h.print();
cout<<endl;

int arr[] = {-1,50,55,53,52,54};
int m = 5;
for(int i=m/2 ; i>0 ; i--){
    heapify(arr,m,i);
}

for(int i=1; i<=m; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;

heapSort(arr,m);
for(int i=1; i<=m; i++){
    cout<<arr[i]<<" ";
}
return 0;
}