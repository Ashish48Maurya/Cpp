#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v = {0,-1,3,6,4,5};
    int n = v.size();
    for(int i=0; i<n; i++){
        int num = abs(v[i]) - 1;
        v[num] = -1*v[num];
    }
    int ans = n+1;
    for(int i=1; i<=n; i++){
        if(v[i-1]>0){
            ans = i;
        }
    }
    cout<<"Minimum missing +ve integer: "<<ans<<endl;
    return 0;
}