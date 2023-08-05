//for better understanding see college wallah lec 1 
#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    int ans=n*factorial(n-1);
    return ans;
    
}
int main(){
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}     