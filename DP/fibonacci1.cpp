                                //using Recursion
#include<iostream>
using namespace std;

int fib(int n){
    //Base Case
    if(n<=1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    cin>>n;
    int ans = fib(n);
    cout<<ans<<endl;
    return 0;
}