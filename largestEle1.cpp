//if Elements are repeated
#include<iostream>
#include<climits>
using namespace std;
int largestEle(int arr[] , int size){
    int maxEle = INT_MIN;
    int secMax = INT_MIN;
    for(int i=0; i<size; i++){
        if(arr[i]>maxEle){
            maxEle = arr[i];
        }
    }
    for(int i=0; i<size; i++){
        if(arr[i]>secMax and arr[i]!=maxEle){
            secMax = arr[i];
        }
    }
    return secMax;
}

int main(){
    int arr[] = {1,2,9,4,9,7};
    int size = 6;
    int ans = largestEle(arr,size);
    cout<<"Second largest Element is: "<<ans<<endl;
    return 0;
}