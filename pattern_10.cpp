#include<iostream>
using namespace std;
int main(){

    cout<<"Enter the number"<<endl;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        for(int j=1; j<=n-1; j++){
            cout<<" ";
        }
        cout<<endl; 
    }
    return 0;
}