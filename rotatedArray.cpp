#include<iostream>
using namespace std;
int elementInRotatedArray(int arr[], int key,int start, int end){
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[start]<arr[mid]){
            if(key>=arr[start] && key<arr[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        else{
            if(key>arr[mid] && key<=arr[end]){
                start = mid+1;
            }
            else{
                end=mid-1;
            }
        }
    } 
// pura while loop chal gaye element nahi mila therefore
    return -1;
}
int main(){
int arr[] = {20,30,40,50,60,5,10};
int idx = elementInRotatedArray(arr,500,0,6);
if(idx==-1){
    cout<<"Element is not present in array list"<<endl;
}
else{
    cout<<"Element is present at index: "<<idx<<endl;
}
return 0;
}