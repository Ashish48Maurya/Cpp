#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Number of Element You want in Array: ";
cin>>n;
int arr[n];
for(int i=0; i<n; i++){
    cin>>arr[i];
}

for(int i=0; i<n-1; i++){
    bool flag = false; //For More Optimisation I have added flag
    for(int j=0; j<n-1-i; j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            flag = true;
        }
    }
    if(flag == false) break;
}

for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
}
return 0;
}