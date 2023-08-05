#include<iostream>
using namespace std;
int findPeakElement(int arr[], int start, int end,int n){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if((mid==0 || arr[mid-1]<= arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid])){
        return mid;
    }
    else if(mid>0 && (arr[mid-1]>arr[mid])){
        return findPeakElement(arr,start,mid-1,n);
    }
    else{
        return findPeakElement(arr,mid+1,end,n);
    }
}
int main(){
int arr[] = {0,6,8,5,7,9};
cout<<"Peak Element Index is: "<<findPeakElement(arr,0,5,6)<<endl;
return 0;
}