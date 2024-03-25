#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int findMinDiff(vector<int> arr, int N, int M){
    sort(arr.begin(),arr.end());
    int start = 0;
    int end = M-1;
    int mini = INT_MAX;
    while(end<M){
        int diff = arr[end] - arr[start];
        mini = min(mini,diff);
        start++;
        end++;
    }
    return mini;
}

int main(){
    int N = 8;
    int M = 5;      //No. of Children
    vector<int> arr = {3,4,1,9,56,7,9,12};
    int ans = findMinDiff(arr,N,M);
    cout<<ans<<endl;
    return 0;
}