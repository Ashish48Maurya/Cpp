#include<iostream>
#include<vector>
using namespace std;
bool arrayPartiton(vector<int> &v){
    int totalSum = 0;
    for(int i=0; i<v.size(); i++){
        totalSum += v[i];
    }
    int prefixSum = 0;
    int suffixSum = 0;
    for(int i=0; i<v.size(); i++){
        prefixSum += v[i];
        suffixSum = totalSum - prefixSum;
        if(prefixSum == suffixSum){
            return true;
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int ele; cin>>ele;
        v.push_back(ele);
    }
    cout<<arrayPartiton(v)<<endl;
    return 0;
}