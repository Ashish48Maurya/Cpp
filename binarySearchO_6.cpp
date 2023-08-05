#include<iostream>
#include<vector>
using namespace std;
bool canDistributeChoco(vector<int> v, int mid, int s){
    int n = v.size();
    int studentRequired = 1;
    int currSum = 0;
    for(int i=0; i<n; i++){
        if(v[i]>mid){
            return false;
        }
        if(currSum + v[i] > mid){
            studentRequired++;
            currSum = v[i];
            if(studentRequired>s){return false;}
        }
        else{
            currSum += v[i];
        }
    }
    return true;
}

int distribute_chocolates(vector<int> v , int s){
    int n = v.size();
    int lo = v[0];
    int hi = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        hi+=v[i];
    }
    while(hi>=lo){
        int mid = lo + (hi-lo)/2;
        if (canDistributeChoco(v,mid,s)){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1; 
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {12,34,67,90};
    int students;
    cout<<"Enter Number of Students: ";
    cin>>students;
    cout<<distribute_chocolates(arr,students);
    return 0;
}