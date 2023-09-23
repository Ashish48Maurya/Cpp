//Divide the array in two parts such that summation of both the parts must be equal and return 1 if u were able to do that else return false(0)
#include<iostream>
using namespace std;
bool isPartitionPossible(int arr[] , int size){
    int totalSum = 0;
    for(int i=0; i<size; i++){
        totalSum+=arr[i];
    }

    int prefixSum = 0;
    for(int i=1; i<size; i++){
        int sum = arr[i] + arr[i-1];
        prefixSum+=sum;
        if(prefixSum==)
    }
}

int main(){
    int arr[] = {1,9,2,4,5,7};
    int size = 6;
    cout<<isPartitionPossible(arr,size)<<endl;
    return 0;
}