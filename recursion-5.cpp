#include<iostream>
using namespace std;
bool sorted(int A[] , int n){
    if(n==1){
        return true;
    }
    //bool restarray=sorted(A+1 , n-1);
    return (A[0]<A[1] && sorted(A+1 , n-1));
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n-1; i++){
        cin>>A[i];
    }
    cout<<sorted(A,n)<<endl;
    return 0;
}