#include<iostream>
#include<vector>
using namespace std;
int findPeak(vector<int> &input){
int n = input.size();
int lo = 0;
int hi = n-1;
while(hi>=lo){
    int mid = lo + (hi-lo)/2;
    if(mid==0){
        if(input[mid]>input[mid+1]){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if(mid==n-1){
        if(input[mid]>input[mid-1]){
            return n-1;
        }
        else{
            return n-2;
        }
    }
    else{
        if(input[mid]>input[mid+1] and input[mid]>input[mid-1]){
            return mid;
        }
        else if(input[mid]>input[mid-1]){
            lo=mid+1;
        }
        else{
            hi = mid-1;
        }
    }
}
return -1;
}
int main(){
// vector<int> v = {3,4,5,1,9,10,2,6,8,2};
vector<int> v = {1,2,1};
cout<<findPeak(v);
return 0;
}