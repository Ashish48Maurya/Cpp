#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int findMax1(vector<int> arr,int n){//starting from right
    if(n==0){
        return arr[0];
    }
    if(n<0){
        return 0;
    }
    int included = arr[n] + findMax1(arr,n-2);
    int excluded = 0 + findMax1(arr,n-1);
    return max(included,excluded);
}