#include<iostream>
#include<vector>
using namespace std;
void maxSumSubarray(vector<int> arr, int k, int x, int n){
    int sum=0, ans=0;
    for(int i=0; i<k; i++){
        sum += arr[i];
    }
    if(sum<x){
        ans=sum;
    }
    for(int i=k; i<n; i++){
        sum=sum-arr[i-k];
        sum=sum+arr[k];
        if(sum<x){
            ans=max(ans,sum);
        }
    }
    cout<<ans<<":is the max sum subarray";
}
int main(){
vector<int> arr ={7,5,4,6,8,9};
maxSumSubarray(arr,3,20,6);
return 0;
}