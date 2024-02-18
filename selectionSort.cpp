#include<iostream>
#include<algorithm>
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

    for(int i=0; i<n-1; i++){
        int minEle = arr[i];
        int minEleIdx = i;

        for(int j=i+1; j<n; j++){
            if(minEle>arr[j]){
                minEle = arr[j];
                minEleIdx = j;
            }
        }

        swap(arr[minEleIdx] , arr[i]);
    }

    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}