#include<iostream>
#include<climits>
using namespace std;
void countSort(int arr[], int size){

int max_ele = INT_MIN;  //Finding Max Element
for(int i=0; i<size; i++){
    if(arr[i]>max_ele){
        max_ele = arr[i];
    }
}

int freqArr[max_ele+1] = {0};

for(int i=0; i<size; i++){
    freqArr[arr[i]]++;
}

for(int i=1; i<max_ele+1; i++){
    freqArr[i] += freqArr[i-1];
}

int ansArr[size];

for(int i=size-1 ; i>=0; i--){
    ansArr[--freqArr[arr[i]]] = arr[i];
}

for(int i=0; i<size; i++){
    cout<<ansArr[i]<<" ";
}

}

int main(){
    int arr[] = {5,2,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    countSort(arr,size);
    return 0;
}