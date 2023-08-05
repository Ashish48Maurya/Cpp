// input -> {1,2,3,3,3,4,4,5}; output -> {2,4};
//find first and last occurence of target element

//first - Method

// #include<iostream>
// using namespace std;
// int main(){
// int arr[] = {1,2,3,3,3,4,4,5};
// int size = sizeof(arr)/sizeof(arr[0]);
// int target = 3;
// int firstOcc = -1, lastOcc = -1;
// for(int i=0; i<size; i++){
//     if(arr[i]==target){
//         firstOcc = i;
//         break;
//     }
// }
// for(int i=(size-1); i>=0; i--){
//     if(arr[i]==target){
//         lastOcc = i;
//         break;
//     }
// }
// cout<<firstOcc<<" "<<lastOcc<<endl;
// return 0;
// }




//Second Method
#include<iostream>
using namespace std;
int firstOcc(int arr[],int target,int size){
    int selected = -1;
    int l = 0 , r = size-1;
    while(r>=l){
    int mid = (l+r)/2;
    if(arr[mid]==target){
        selected = mid;
        r = mid-1;
    }
    else if(arr[mid]>target){
        r=mid-1;
    }
    else{
        l=mid+1;
    }
    }
    return selected;
}


int lastOcc(int arr[],int target,int size){
    int selected = -1;
    int l = 0 , r = size-1;
    while(r>=l){
    int mid = (l+r)/2;
    if(arr[mid]>target){
        selected = mid;
        r=mid-1;
    }
    else{
        l=mid+1;
    }
    }
    return selected-1;
}

int main(){
int arr[] = {1,2,3,3,3,3,3,4,4,5};
int size = sizeof(arr)/sizeof(arr[0]);
int target = 3;
cout<<firstOcc(arr,target,size)<<" "<<lastOcc(arr,target,size);
return 0;
}