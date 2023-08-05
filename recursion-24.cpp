// if input = 5;
// output -> 1-2+3-4+5 = 3;
#include<iostream>
using namespace std;
int print(int n){
    if(n==0){
        return 0;
    }
    return print(n-1) +  ((n%2 == 0)? -n : n);
}
int main(){
    int n; cin>>n;
    cout<<print(n);
    return 0;
}