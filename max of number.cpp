#include<iostream>
using namespace std;
int main(){
      int n;
    cin>>n;
    int array[n];
    for( int i=0; i<n; i++){
       cin>>array[n];
       cout<<endl;
    }
    int mx=-199;
    for(int i=0; i<n; i++){
      mx = max(mx,array[i]);
      cout<<mx<<endl;
    }
    return 0;
}