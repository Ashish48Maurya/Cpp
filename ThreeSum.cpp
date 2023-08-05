#include<iostream>
#include<vector>
// #include<algorithm>  // for sort
using namespace std;
int main(){
    cout<<"Enter the value of n"<<endl;
    int n; cin>>n;
    cout<<"Enter the value of target"<<endl;
    int target; cin>>target;
    cout<<"Enter the array element"<<endl;
    vector<int> v(n);
    for(auto i:v){
        cin>>v[i];
    }
    sort(v.begin() , v.end());
    bool found = false;
    for(int i=0; i<n; i++){
        int L=i+1, R=n-1;
        while(L<R){
        int ans = v[i]+ v[L]+ v[R];
        if(ans==target){
            found=true;
        }
        if(ans>target){
            L--;
        }
        else{
            R++;
        } 
        }
    }
    if(found){
        cout<<"Triplet Exist"<<endl;
    }
    else{
        cout<<"Triplet does'nt Exist"<<endl;
    }
return 0;
}