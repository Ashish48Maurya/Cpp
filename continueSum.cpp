#include<iostream>
#include<vector>
using namespace std;
void continueSum(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        v[i] += v[i-1];
    }
}
int main(){
    int n; cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        int ele; cin>>ele;
        v.push_back(ele);
    }
    continueSum(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}