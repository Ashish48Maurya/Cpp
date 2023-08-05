//find a pairs in a array whose sum is equal to a given number x
#include<iostream>
using namespace std;
int main(){
    int arr[7];
    cout<<"Enter Array Element: ";
    for(int i=0; i<7; i++){
        cin>>arr[i];
    }
    
    int x;
    cout<<"Enter One Element: ";
    cin>>x;

    for(int i=0; i<7; i++){
        for(int j=i+1; j<7; j++){
            if(arr[i]+arr[j] == x){
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
    return 0;
}