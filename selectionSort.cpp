#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Number of Element you want in an array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter array Element: "<<endl;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<=n-1; i++){   //Outer loop will run n-1 times
        int min_idx = i;
        for(int j=i+1; j<=n; j++){
            if(arr[min_idx]>arr[j]){
                min_idx = j;
            }
        }
        if(min_idx!=i){
            swap(arr[min_idx],arr[i]);
        }
    }
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}