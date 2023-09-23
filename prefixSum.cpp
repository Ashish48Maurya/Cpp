#include<iostream>
#include<vector>
using namespace std;

void prefixSum(vector<int> &v){
    for(int i=1; i<v.size(); i++){
        v[i]+=v[i-1];
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    prefixSum(vec);

    cout<<"Printing Array"<<endl;
    for(int ele: vec){
        cout<<ele<<" ";
    }cout<<endl;
    return 0;
}