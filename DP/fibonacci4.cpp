                        //Using Space Optimization Method
#include<iostream>
using namespace std;

int fib(int n){
    int prev1 = 1;
    int prev2 = 0;

    for(int i=2; i<=n; i++){
        int curr = prev1+prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
    int n;
    cin>>n;
    int ans = fib(n);
    cout<<ans<<endl;
    return 0;
}