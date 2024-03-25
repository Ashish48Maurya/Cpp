                        //Using Recursion+Memoization (Top Down Approach)
#include<iostream>
#include<vector>
using namespace std;

int fib(int n, vector<int> &v){
    if(n<=1){
        return n;
    }

    if(v[n]!=-1){
        return v[n];
    }

    v[n] = fib(n-1,v)+fib(n-2,v);
    return v[n];
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n+1,-1);
    int ans = fib(n,v);
    cout<<ans<<endl;
    return 0;
}