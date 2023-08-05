// 1 2 5 4 3 -->  peak element is 5;   
//Array must be in this form a[0]<a[1]<a[2]>a[3]>a[4]   (i.e) Mountain Array
#include<iostream>
#include<vector>
using namespace std;
int peakEleInMountainArray(vector<int> &arr,int length){
    int ans = -1;
    int l = 0, r = length-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(arr[mid]>arr[mid-1]){
            ans = max(ans,mid);
            // if (arr[mid]>arr[mid-1]) it means we are at incresing curve therefore left part of mid is discarded because at left part all elements are smaller than element present at mid;
            //E.g --> [1,2,3,4,5,6,3,2,0];
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}
int main(){
vector<int> arr = {1,2,4,7,1,0,-2};
int length = arr.size();
int ans = peakEleInMountainArray(arr,length);
if(ans==-1){
    cout<<"Peak element is not present"<<endl;
}
else{
    cout<<"Peak element "<<arr[ans]<<" is present at position "<<ans<<endl;
}
return 0;
}