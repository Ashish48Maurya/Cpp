#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the Number of Element you want in an Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter Array Elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        int current_ele = arr[i];
        int j = i-1;
        while(arr[j]>current_ele && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current_ele;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}