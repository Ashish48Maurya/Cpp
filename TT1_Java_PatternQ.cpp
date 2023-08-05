#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
for(int i=0; i<n; i++){
int key = i;
for(int j=0; j<n; j++){
    if(j>=n-i-1){
        cout<<key;
        key--;
    }
    else{
        cout<<" ";
    }
}
for(int j=1; j<n; j++){
    if(j<=i){
        cout<<j;
    }
    else{
        cout<<" ";
    }
}
cout<<endl;
}
return 0;
}