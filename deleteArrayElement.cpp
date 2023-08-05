#include<iostream>
using namespace std;
int main(){
    int arr[6] = {1,2,3,7,8,9};
    int n,temp;
    cout<<"Enter position: ";
    cin>>n;
    for(int i=n-1;i<6;i++){
      temp = arr[i];
      arr[i] = arr[i+1];
      arr[i+1] = temp;
    }
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
