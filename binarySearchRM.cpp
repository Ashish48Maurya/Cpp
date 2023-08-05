//Recursive Method
#include<iostream>
using namespace std;
int binarySearch(int arr[], int key, int start, int end){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return binarySearch(arr,key,start,mid-1);
    }
    else{
        return binarySearch(arr,key,mid+1,end);
    }
}
int main(){
   int arr[] = {1,2,3,4,5,6};
   int idx = binarySearch(arr,9,0,5);
   if(idx==-1){
    cout<<"Element is not present in array list"<<endl;
   }
   else{
    cout<<"Element is present at index: "<<idx<<endl;
   }
    return 0;
}